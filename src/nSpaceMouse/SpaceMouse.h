/************************************************************/
/*    NAME: Eirik Hexeberg Henriksen                        */
/*    ORGN: NTNU                                            */
/*    FILE: SpaceMouse.h                                    */
/*    DATE: 06.10.15                                        */
/************************************************************/

#ifndef SpaceMouse_HEADER
#define SpaceMouse_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include <spnav.h>

class SpaceMouse : public CMOOSApp
{
 public:
   SpaceMouse();
   ~SpaceMouse();

 protected:
   bool Iterate();
   bool OnConnectToServer();
   bool OnDisconnectFromServer();

 private: // Configuration variables
   spnav_event sev;

 private: // State variables
   bool         m_connectedToDevice;
};

#endif 
