/************************************************************/
/*    NAME: Eirik Hexeberg Henriksen                        */
/*    ORGN: NTNU                                            */
/*    FILE: SpaceMouse.cpp                                  */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "SpaceMouse.h"

using namespace std;

//---------------------------------------------------------
// Constructor

SpaceMouse::SpaceMouse()
{
  m_connectedToDevice = false;
  m_joystick_position = "";
  m_button            = "";
  m_deadbandActive    = true;
  m_control_modes     = true;
  m_current_mode      = 0;
  m_deadbandThreshold = 0.15;
}

//---------------------------------------------------------
// Destructor

SpaceMouse::~SpaceMouse()
{
    spnav_close();
}


//---------------------------------------------------------
// Procedure: OnConnectToServer

bool SpaceMouse::OnConnectToServer()
{
    AppCastingMOOSApp::RegisterVariables();
    if(spnav_open()==-1)
    {
        reportRunWarning( "failed to connect to the space navigator daemon\n");
        m_connectedToDevice = false;
    }
    else
    {
        m_connectedToDevice=true;
    }
    return(m_connectedToDevice);
}

bool SpaceMouse::OnDisconnectFromServer() {
    spnav_close();
    m_connectedToDevice=false;
    return(true);
}

bool SpaceMouse::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();
  AppCastingMOOSApp::RegisterVariables();
  
  STRING_LIST sParams;
    m_MissionReader.GetConfiguration(GetAppName(), sParams);
  
    STRING_LIST::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
        string sLine = *p;
        string param = toupper(biteStringX(sLine, '='));
        string value = sLine;
        double dval  = atof(value.c_str());
        if(param == "DEADBAND")
        {
          if (value == "true")
          {
            m_deadbandActive = true;
          }
          else
          {
            m_deadbandActive = false;
          }
        }
        else if(param == "CONTROL_MODES")
        {
          if (value == "true")
          {
            m_control_modes = true;
          }
          else
          {
            m_control_modes = false;
          }
        }
        else if (param == "THRESHOLD")
        {
            m_deadbandThreshold = dval;
        }
    }
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool SpaceMouse::Iterate()
{
    AppCastingMOOSApp::Iterate();
    // poll all events since last iteration
    while(spnav_poll_event(&sev))
    {
        // if event is movement in joystick
        if(sev.type == SPNAV_EVENT_MOTION)
        {
            int x,y,z,rx,ry,rz;
            x   = sev.motion.z;   y   = sev.motion.x;   z   = sev.motion.y;
            rx  = sev.motion.rz;  ry  = sev.motion.rx;  rz  = sev.motion.ry;
            
            
            
            if (m_deadbandActive)
              deadband(x,y,z,rx,ry,rz);
            
            
            
            string msg;
            // Converting spaceMouse axis to NED axis
            msg += "x=" + intToString(sev.motion.z) + ",";
            msg += "y=" + intToString(sev.motion.x) + ",";
            msg += "z=" + intToString(sev.motion.y) + ",";
            msg += "rx=" + intToString(sev.motion.rz) + ",";
            msg += "ry=" + intToString(sev.motion.rx) + ",";
            msg += "rz=" + intToString(sev.motion.ry);
            
            m_joystick_position = msg;
            
            Notify("JoystickMotion",msg,MOOSTime());
        }
        // if event is button press or realease
        else if(sev.type == SPNAV_EVENT_BUTTON)
        {
            string msg;
            msg += (sev.button.press ? "press" : "release");
            msg += "=" + intToString(sev.button.bnum);
            
            m_button = msg;
            
            Notify("JoystickButton",msg,MOOSTime());

            if(m_control_modes)
            {
                switch (sev.button.bnum) {
                case 12:
                    m_current_mode = 1;
                    Notify("currentControlMode",m_current_mode);
                    break;
                case 13:
                    m_current_mode = 2;
                    Notify("currentControlMode",m_current_mode);
                    break;
                case 14:
                    m_current_mode = 3;
                    Notify("currentControlMode",m_current_mode);
                    break;
                case 15:
                    m_current_mode = 4;
                    Notify("currentControlMode",m_current_mode);
                    break;
                case 22:
                    //esc
                    Notify("MOOS_MANUAL_OVERIDE","m_current_mode","true");
                    break;
                case 25:
                    Notify("MOOS_MANUAL_OVERIDE","m_current_mode","false");
                    break;
                default:
                    break;
                }

                
            }
        }
    }
    
    AppCastingMOOSApp::PostReport();
    return(true);
}

bool SpaceMouse::buildReport()
{
     m_msgs << "Last sent joystick position: " << m_joystick_position << endl;
     m_msgs << "Last sent joystick button: " << m_button  << endl;
     m_msgs << "Connected to device: " << (m_connectedToDevice ? "true" : "false" ) << endl;
     m_msgs << "Current deadband threshold: " << m_deadbandThreshold << endl;
     m_msgs << "Deadband active: " << (m_deadbandActive ? "true" : "false" ) << endl;
     m_msgs << "ControlModes active: " << (m_control_modes ? "true" : "false" ) << endl;
     m_msgs << "Current control mode: " << m_current_mode << endl;
  
     return(true);
}

void SpaceMouse::deadband(int& x, int& y, int& z, int& rx , int& ry, int& rz)
{
  double deadband = double(abs(x) + abs(y) + abs(z) + abs(rx) + abs(ry) + abs(rz)) * m_deadbandThreshold;
  
  int * joystick_output[6] = {&x, &y, &z, &rx, &ry, &rz};
  
  int db = int(deadband);
  
  for (int i = 0;  i < 6; ++i)
  {
    if( abs(*joystick_output[i]) < db)
       {
        *joystick_output[i] = 0;
       }
  }
}

