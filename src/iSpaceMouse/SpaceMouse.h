/************************************************************/
/*    NAME: Eirik Hexeberg Henriksen                        */
/*    ORGN: NTNU                                            */
/*    FILE: SpaceMouse.h                                    */
/*    DATE: 06.10.15                                        */
/************************************************************/

#ifndef SpaceMouse_HEADER
#define SpaceMouse_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h" 
#include <string>
#include <iostream>
#include <spnav.h>

using namespace std;

class SpaceMouse : public AppCastingMOOSApp
{
 public:
   SpaceMouse();
   ~SpaceMouse();
   bool buildReport();

 protected:
   bool Iterate();
   bool OnConnectToServer();
   bool OnDisconnectFromServer();
   bool OnStartUp();
   
   void deadband(int& x, int& y, int& z, int& rx , int& ry, int& rz);

 private: // Configuration variables
   spnav_event sev;

 private: // State variables
   bool         m_connectedToDevice;
   bool         m_deadbandActive;
   bool         m_control_modes;
   double       m_current_mode;
   double       m_deadbandThreshold;
   string       m_joystick_position;
   string       m_button;
};

#endif 
