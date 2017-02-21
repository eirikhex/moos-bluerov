/************************************************************/
/*    NAME: Eirik Hexeberg Henriksen                                              */
/*    ORGN: MIT                                             */
/*    FILE: Qualisys.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef Qualisys_HEADER
#define Qualisys_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "RTProtocol.h"

using namespace std;

class Qualisys : public CMOOSApp
{
 public:
   Qualisys();
   ~Qualisys();

 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
   string serverAddress; 		// The address of the computer connected to the Qualisys motion tracking system (ex: "130.75.144.179")
   int basePort;                // The base port (as entered in QTM, TCP/IP port number, in the RT output tab of the workspace options

   // Defining global variables
   float x, y, z, roll, pitch, yaw;
   uint bodyCount;
   uint frameNumber;

   CRTPacket*             pRTPacket;
   CRTPacket::EPacketType eType;

   // Defining a protocol that connects to the Qualisys
   CRTProtocol poRTProtocol;
};

#endif 
