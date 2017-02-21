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
    if(spnav_open()==-1)
    {
        fprintf(stderr, "failed to connect to the space navigator daemon\n");
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

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool SpaceMouse::Iterate()
{
    // poll all events since last iteration
    while(spnav_poll_event(&sev))
    {
        // if event is movement in joystick
        if(sev.type == SPNAV_EVENT_MOTION)
        {
            string msg;
            // Converting spaceMouse axis to NED axis
            msg += "x=" + intToString(sev.motion.z) + ",";
            msg += "y=" + intToString(sev.motion.x) + ",";
            msg += "z=" + intToString(sev.motion.y) + ",";
            msg += "rx=" + intToString(sev.motion.rz) + ",";
            msg += "ry=" + intToString(sev.motion.rx) + ",";
            msg += "rz=" + intToString(sev.motion.ry);

            Notify("JoystickMotion",msg,MOOSTime());
        }
        // if event is button press or realease
        else if(sev.type == SPNAV_EVENT_BUTTON)
        {
            string msg;
            msg += (sev.button.press ? "press" : "release");
            msg += "=" + intToString(sev.button.bnum);

            Notify("JoystickButton",msg,MOOSTime());
        }
    }
    return(true);
}

