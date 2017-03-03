#ifndef UPIDPLOTTER_H
#define UPIDTIMEPLOTTER_H

#include <QObject>
#include <QThread>
#include "mainwindow.h"
#include "MOOS/libMOOS/MOOSLib.h"

class PIDPlotter : public QObject, public CMOOSApp
{
    Q_OBJECT



public:
    PIDPlotter();
    virtual ~PIDPlotter() {}
    MainWindow w;

    bool OnNewMail(MOOSMSG_LIST &NewMail);
    bool Iterate();
    bool OnConnectToServer();
    bool OnStartUp();
    void RegisterVariables();
    void UpdateSortingMap();
    std::vector<std::string> StringVector(std::string str);

signals:
    // sends, key, x-value (time), y-value
    void newPlotDataArrived(std::string key,std::pair<double,double> PlotData);
    void newPlots(std::vector<std::string> names);
    void redrawPlots();

protected:
    // map from MOOSMsg key to plot-name
    std::map<std::string,std::set<std::string> > sorting_map;
    // map from plot-name to config for x and y values of plot
    std::map<std::string,plotconf> config_map;
    double extractData(CMOOSMsg &msg, std::string conf);
    std::pair<double,double> extractDataPair(CMOOSMsg &msg, plotconf config);

};

class PlotterThread : public QThread
{
    Q_OBJECT

public:
    PlotterThread(const std::string &  sName,const std::string & sMissionFile, int inArgc,  char * inArgv[])
    {
        app_name        = sName;
        mission_file    = sMissionFile;
        argc            = inArgc;
        argv            = inArgv;

        plotter.w.setWindowTitle(QString::fromStdString( sName));

        connect(&plotter,SIGNAL(newPlotDataArrived(std::string, std::pair<double,double>)),&plotter.w,SLOT(realtimeDataSlot(std::string,std::pair<double,double>)));
        connect(&plotter,SIGNAL(newPlots(std::vector<std::string>)),&plotter.w,SLOT(addPlots(std::vector<std::string>)));
        connect(&plotter,SIGNAL(redrawPlots()),&plotter.w,SLOT(replot()));
    }

public slots:
    void stop()
    {
           plotter.RequestQuit();
           wait();
           quit();
    }

private:
        std::string  app_name;
        std::string  mission_file;
        int argc;
        char ** argv;
        PIDPlotter plotter;

    void run()
    {
        plotter.Run(app_name, mission_file, argc, argv);
    }
};

#endif // UPIDPLOTTER_H
