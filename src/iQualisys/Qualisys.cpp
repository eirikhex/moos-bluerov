/************************************************************/
/*    NAME: Eirik Hexeberg Henriksen                                              */
/*    ORGN: NTNU                                             */
/*    FILE: Qualisys.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "Qualisys.h"

#define PI 3.141592653589793


using namespace std;

//---------------------------------------------------------
// Constructor

Qualisys::Qualisys()
{
    serverAddress = "192.168.0.20"; //"tracking1";		// The address of the computer connected to the Qualisys motion tracking system (ex: "130.75.144.179")
    basePort = 22222; 					// The base port (as entered in QTM, TCP/IP port number, in the RT output tab of the workspace options
}

//---------------------------------------------------------
// Destructor

Qualisys::~Qualisys()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Qualisys::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;

#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Qualisys::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);
	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Qualisys::Iterate()
{
    pRTPacket = poRTProtocol.GetRTPacket();
    frameNumber  = pRTPacket->GetFrameNumber();

    poRTProtocol.GetCurrentFrame(CRTProtocol::Component6dEuler);

    std::string BaseName("currentNEDPos");

    if (poRTProtocol.ReceiveRTPacket(eType, true))
    {
        switch (eType) {
            // Case 1 - sHeader.nType 0 indicates an error
            case CRTPacket::PacketError :
                cerr << "Error when streaming frames: " << poRTProtocol.GetRTPacket()->GetErrorString() << endl;
                break;
            case CRTPacket::PacketNoMoreData :  // No more data
                cout << "No more data" << endl;
                break;

            // Case 2 - Data received
            case CRTPacket::PacketData:
                bodyCount  = pRTPacket->Get6DOFEulerBodyCount();
                if (bodyCount <= 0)
                {
                        //cout << "No Bodies Found" << endl;
                }
                else
                {
                    for (int i = 0; i < bodyCount; i++) {
                        pRTPacket->Get6DOFEulerBody(i, x, y, z, roll, pitch, yaw);
                        if (isnan(x)||isnan(y)||isnan(z)||isnan(roll)||isnan(pitch)||isnan(yaw))
                        {
                        //cout << "Rigid-body " << i+1 << "/" << bodyCount << " not detected" << endl;
                        }
                        else
                        {
                            // ROTATION: GLOBAL (FIXED) X Y Z (R P Y)
                            stringstream name;
                            name << BaseName << i << "_";

                            /*Qualisys sometimes flips 180 degrees around the x axis
                            if (roll>90)
                                roll -= 180;
                            else if (roll<-90)
                                    roll += 180;
                            */
                            // Make output to meters:
                            x /= 1000.0; y /=1000.0; z /=1000.0;
                            // make output to radians
                            roll *= (PI/180.0); pitch *= (PI/180.0); yaw *= (PI/180.0);
                            double t = MOOSTime();
                            Notify(name.str() + "x",x,t);
                            Notify(name.str() + "y",y,t);
                            Notify(name.str() + "z",z,t);
                            Notify(name.str() + "rx",roll,t);
                            Notify(name.str() + "ry",pitch,t);
                            Notify(name.str() + "rz",yaw,t);

                        }
                    }
                }
                break;

            default:
                cout <<"Unknown CRTPacket case" << endl;
        }
    }

  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Qualisys::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      if(param == "FOO") {
        //handled
      }
      else if(param == "BAR") {
        //handled
      }
    }
  }
  

  // Connecting to the server
  cout << "Connecting to the Qualisys Motion Tracking system specified at: " << serverAddress << ":" << basePort << endl;

  if (!poRTProtocol.Connect((char*)serverAddress.data(), basePort, 0, 1, 7)){

      cerr << "Could not find the Qualisys Motion Tracking system at: " << serverAddress << ":" << basePort << endl;
      return(false);
  }

  cout << "Connected to " << serverAddress << ":" << basePort << endl;

  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void Qualisys::RegisterVariables()
{
  // Register("FOOBAR", 0);
}

