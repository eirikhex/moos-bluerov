#include "upidplotter.h"
#include "mainwindow.h"
#include "MBUtils.h"
#include "MatrixParse.h"
#include <ostream>


PIDPlotter::PIDPlotter()
{

    w.show();
    // to linjer, x posisjon desired og current

    //current

   // config_map["current"] = plotconf("simNorth","time","double");
   //config_map["desired"] = plotconf("DESIRED_NORTH","time","double");

    //UpdateSortingMap();
}

void PIDPlotter::UpdateSortingMap()
{
    std::map<std::string,plotconf>::const_iterator it;
    for( it = config_map.begin(); it != config_map.end(); it++)
    {
        std::string MOOSkey = it->second.MOOSkey;
        std::string plotName = it->first;

        std::set<std::string> names;
        // if the current key is in the map, assign name-set to names
        if (sorting_map.count(MOOSkey) ==1)
            names = sorting_map[MOOSkey];
        // make sure plotName is inserted, set makes sure there is no duplicates
        names.insert(plotName);

        // assign set to key in map
        sorting_map[MOOSkey] = names;
    }
}

bool PIDPlotter::Iterate()
{
    emit redrawPlots();
    return(true);
}

bool PIDPlotter::OnNewMail(MOOSMSG_LIST &NewMail)
{
    //std::map<std::string,std::pair<double,double> > msgMap;
    MOOSMSG_LIST::iterator p;
        for(p = NewMail.begin(); p!=NewMail.end(); p++) {
            CMOOSMsg &msg = *p;
            if(sorting_map.count(msg.GetKey()) == 1)
            {
                // loop through set of plots using the MOOSvariable
                std::set<std::string> nameSet = sorting_map[msg.GetKey()];
                std::set<std::string>::iterator iter;
                for(iter = nameSet.begin(); iter != nameSet.end(); iter++)
                {
                    //get name string;
                    std::string name = *iter;

                    // get config struct
                    plotconf config = config_map[name];

                    // get x and y value
                    std::pair<double,double> data = extractDataPair(msg,config);

                    emit newPlotDataArrived(name,data);

                }
            }
        }
    return(true);
}

double PIDPlotter::extractData(CMOOSMsg &msg, std::string conf)
{
    if(conf == "double")
    {
        return(msg.GetDouble());
    }
    else if(conf == "time")
    {
        return(msg.GetTime());
    }
    else if(conf.find("vector") != std::string::npos)
    {
        biteString(conf,'[');
        std::string numberString = biteString(conf,']');
        int i = QString::fromStdString(numberString).toInt();
        std::vector<double> vec = MOOSStringToDVector(msg.GetString());
        return(vec[i]);
    }
}

std::pair<double,double> PIDPlotter::extractDataPair(CMOOSMsg &msg, plotconf config)
{
    double x,y;
    x = extractData(msg,removeWhite(config.x));
    y = extractData(msg,removeWhite(config.y));
    return(std::make_pair(x,y));
}

bool PIDPlotter::OnStartUp()
{
    int nLines;
    if (!m_MissionReader.GetConfigurationParam("nLines", nLines))
        return(false);
    std::string lineNames;
    if(!m_MissionReader.GetConfigurationParam( "lineNames",lineNames))
        return(false);
    std::string xValues;
    if(!m_MissionReader.GetConfigurationParam( "xValues",xValues))
        return(false);
    std::string xTypes;
    if(!m_MissionReader.GetConfigurationParam( "xTypes",xTypes))
        return(false);

    std::vector<std::string> names = StringVector(lineNames);
    std::vector<std::string> values = StringVector(xValues);
    std::vector<std::string> types = StringVector(xTypes);
    if (names.size() != nLines || values.size() != nLines || types.size() != nLines){
        return(false);
    }

    for (int i = 0; i < nLines; ++i) {
        config_map[names[i]] = plotconf(values[i],"time",types[i]);
    }
    UpdateSortingMap();
    emit newPlots(names);

    RegisterVariables();
    return(true);
}

bool PIDPlotter::OnConnectToServer()
{
    RegisterVariables();
    return(true);
}

void PIDPlotter::RegisterVariables()
{

    // Register for all MOOSVariables in the sorting map
    std::map<std::string,std::set<std::string> >::const_iterator iterator;
    for(iterator = sorting_map.begin(); iterator != sorting_map.end();iterator++)
    {
        m_Comms.Register(iterator->first,0.0);
    }
}

std::vector<std::string> PIDPlotter::StringVector(std::string str){
    std::vector<std::string> stringVector;
    int p;
    while ((p = str.find(',')) != std::string::npos)
    {
        std::string entry =  stripBlankEnds( str.substr(0,p));
        stringVector.push_back(entry);
        str.erase(0, p + 1);
    }
    // get last entry in row
    stringVector.push_back(stripBlankEnds( str));
    return(stringVector);
}

