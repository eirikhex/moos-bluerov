/************************************************************/
/*    NAME:                                               */
/*    ORGN: NTNU                                             */
/*    FILE: MavMOOS.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef MavMOOS_HEADER
#define MavMOOS_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "autopilot_interface.h"
#include "serial_port.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <locale>
#include <bluerov2/mavlink.h>


class MavMOOS : public CMOOSApp
{
 public:
   MavMOOS();
   ~MavMOOS();

   void Callback(mavlink_message_t& message);

   void send_mavlink_heartbeat();
   void handle_mavlink_highres_imu_msg(mavlink_message_t& message);
   void handle_mavlink_depth_msg(mavlink_message_t& message);
   void handle_mavlink_attitude_msg(mavlink_message_t& message);
   void handle_mavlink_battery_msg(mavlink_message_t& message);

   void handle_MOOS_desired_thrust_msg(CMOOSMsg& message);
   void handle_MOOS_arm_msg(CMOOSMsg& message);
   void _disarm_cmd();




 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();

   int companion_id;

   Serial_Port serial_port;
   Autopilot_Interface autopilot_interface;
   



 private: // Configuration variables

 private: // State variables
   unsigned int m_iterations;
   double       m_timewarp;

   double str2dbl(std::string str);
   std::pair<int, int> parseMatrix(std::string moos_string, std::vector<double>& num);
};





#endif 
