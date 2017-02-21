/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: MavMOOS.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <bitset>
#include "MBUtils.h"
#include "MavMOOS.h"

using namespace std;

//TODO: Finish Callbacks
//TODO: MOOS -> MAvlink write
//TODO: MAvlink UDP Link
//TODO: Message Mask for Mavlink (Filter)
//TODO: Binary Mavlink MOOS Messages?
//TODO: Ensure nice cleanup of serial port threads ++
//TODO: Make Class(es) to temporarily store MOOS messages needed for mavlink message, should have moos comms object in initalizer to be able to notify



//---------------------------------------------------------
// Constructor

MavMOOS::MavMOOS():
    serial_port("/dev/ttyACM0", 57600), //uart_name, baudrate FIXME: Read Parameter from .moosfile
    autopilot_interface(&serial_port),
    companion_id(0)
{
  m_iterations = 0;
  m_timewarp   = 1;



}

//---------------------------------------------------------
// Destructor

MavMOOS::~MavMOOS()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool MavMOOS::OnNewMail(MOOSMSG_LIST  &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;

    if(msg.GetKey() == "desiredThrust")
        handle_MOOS_desired_thrust_msg(msg);
    if(msg.GetKey() == "armingState")
        handle_MOOS_arm_msg(msg);

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

bool MavMOOS::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);
	
   RegisterVariables();
   //autopilot_interface.enable_offboard_control();
   autopilot_interface.set_callback( std::bind( &MavMOOS::Callback, this , std::placeholders::_1)) ;
   //autopilot_interface.set_callback( [this](mavlink_message_t& message){ this.Callback(message);}) ;
   usleep(100);
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool MavMOOS::Iterate()
{
    m_iterations++;

    // send heartbeat to autopilot
    send_mavlink_heartbeat();


    return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool MavMOOS::OnStartUp()
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
  
  m_timewarp = GetMOOSTimeWarp();

  RegisterVariables();

  serial_port.start();

  autopilot_interface.start();

  return(true);
}



//---------------------------------------------------------
// Procedure: RegisterVariables

void MavMOOS::RegisterVariables()
{
    Register("desiredThrust",0.0);
    Register("armingState",0.0);

}

void MavMOOS::Callback(mavlink_message_t& message)
{
  switch (message.msgid)
      { 

        case MAVLINK_MSG_ID_HEARTBEAT:
        {
          //printf("MAVLINK_MSG_ID_HEARTBEAT\n");
          /*
          mavlink_msg_heartbeat_decode(&message, &(current_messages.heartbeat));
          current_messages.time_stamps.heartbeat = get_time_usec();
          this_timestamps.heartbeat = current_messages.time_stamps.heartbeat;
          */
          break;
        }

        case MAVLINK_MSG_ID_SYS_STATUS:
        {
          //printf("MAVLINK_MSG_ID_SYS_STATUS\n");
          /*
          mavlink_msg_sys_status_decode(&message, &(current_messages.sys_status));
          current_messages.time_stamps.sys_status = get_time_usec();
          this_timestamps.sys_status = current_messages.time_stamps.sys_status;
          */
          break;
        }

        case MAVLINK_MSG_ID_BATTERY_STATUS:
        {
            handle_mavlink_battery_msg(message);
            break;
        }

        case MAVLINK_MSG_ID_RADIO_STATUS:
        {
          /*
          printf("MAVLINK_MSG_ID_RADIO_STATUS\n");
          mavlink_msg_radio_status_decode(&message, &(current_messages.radio_status));
          current_messages.time_stamps.radio_status = get_time_usec();
          this_timestamps.radio_status = current_messages.time_stamps.radio_status;
          */
          break;
        }

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
        {
          //printf("MAVLINK_MSG_ID_LOCAL_POSITION_NED\n");
          /*
          mavlink_msg_local_position_ned_decode(&message, &(current_messages.local_position_ned));
          current_messages.time_stamps.local_position_ned = get_time_usec();
          this_timestamps.local_position_ned = current_messages.time_stamps.local_position_ned;
          */
          break;
        }

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        {
          //printf("MAVLINK_MSG_ID_GLOBAL_POSITION_INT\n");
          /*
          mavlink_msg_global_position_int_decode(&message, &(current_messages.global_position_int));
          current_messages.time_stamps.global_position_int = get_time_usec();
          this_timestamps.global_position_int = current_messages.time_stamps.global_position_int;
          */
          break;
        }

        case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED:
        {
          //printf("MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED\n");
          /*
          mavlink_msg_position_target_local_ned_decode(&message, &(current_messages.position_target_local_ned));
          current_messages.time_stamps.position_target_local_ned = get_time_usec();
          this_timestamps.position_target_local_ned = current_messages.time_stamps.position_target_local_ned;
          */
          break;
        }

        case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT:
        {
          //printf("MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT\n");
          /*mavlink_msg_position_target_global_int_decode(&message, &(current_messages.position_target_global_int));
          current_messages.time_stamps.position_target_global_int = get_time_usec();
          this_timestamps.position_target_global_int = current_messages.time_stamps.position_target_global_int;
          */
          break;
        }

        case MAVLINK_MSG_ID_HIGHRES_IMU:
        {
            handle_mavlink_highres_imu_msg(message);
          //printf("MAVLINK_MSG_ID_HIGHRES_IMU\n");
          /*
          mavlink_msg_highres_imu_decode(&message, &(current_messages.highres_imu));
          current_messages.time_stamps.highres_imu = get_time_usec();
          this_timestamps.highres_imu = current_messages.time_stamps.highres_imu;
          */
          break;
        }

        case MAVLINK_MSG_ID_ATTITUDE:
        {
            handle_mavlink_attitude_msg(message);
            break;
        }
        case MAVLINK_MSG_ID_DEPTH:
        {
            handle_mavlink_depth_msg(message);
            break;
        }

        default:
        {
            //printf("Warning, did not handle message id %i\n",message.msgid);
            break;
        }


      } // end: switch msgid

}

void MavMOOS::send_mavlink_heartbeat()
    {
        mavlink_heartbeat_t heartbeat = {};
        heartbeat.type = MAV_TYPE_GCS;/*< Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)*/
        heartbeat.autopilot = 0; /*< Autopilot type / class. defined in MAV_AUTOPILOT ENUM*/
        heartbeat.base_mode = 0; /*< System mode bitfield, see MAV_MODE_FLAG ENUM in mavlink/include/mavlink_types.h*/
        heartbeat.system_status = 0; /*< System status flag, see MAV_STATE ENUM*/
        heartbeat.mavlink_version= 3;

        mavlink_message_t msg;
        mavlink_msg_heartbeat_encode(autopilot_interface.system_id, companion_id, &msg, &heartbeat);
        autopilot_interface.write_message(msg);
    }

void MavMOOS::handle_mavlink_highres_imu_msg(mavlink_message_t& message)
    {   
        mavlink_highres_imu_t imu_message = {};
        mavlink_msg_highres_imu_decode( &message, &imu_message);

        std::bitset<16> bitmask(imu_message.fields_updated);
        bool publish_old = true;

        double time = MOOSTime();

        Notify("imu_timestamp_usec", imu_message.time_usec ,time);
        Notify("imu_bitmask", bitmask.to_string() ,time);

            
        if(bitmask[0] || publish_old) // xacc
            Notify("imu_acc_x", imu_message.xacc, time);
        if(bitmask[1] || publish_old) // yacc
            Notify("imu_acc_z", imu_message.yacc, time);
        if(bitmask[2] || publish_old) // zacc
            Notify("imu_acc_y", -imu_message.zacc, time);
        if(bitmask[3] || publish_old) // xgyro
            Notify("imu_gyro_p", imu_message.xgyro, time);
        if(bitmask[4] || publish_old) // ygyro
            Notify("imu_gyro_r", -imu_message.ygyro, time);
        if(bitmask[5] || publish_old) // zgyro
            Notify("imu_gyro_q", imu_message.zgyro, time);
        if(bitmask[6] || publish_old) // xmag
            Notify("imu_mag_x", imu_message.xmag, time);
        if(bitmask[7] || publish_old) // ymag
            Notify("imu_mag_z", -imu_message.ymag, time);
        if(bitmask[8] || publish_old) // zmag'
          Notify("imu_mag_y", imu_message.zmag, time);

        


    }

void MavMOOS::handle_mavlink_depth_msg(mavlink_message_t& message)
    {
        mavlink_depth_t depth_msg = {};
        mavlink_msg_depth_decode(&message, &depth_msg);
        Notify("currentDepth", depth_msg.depth);
        Notify("currentPressure", depth_msg.abs_pressure);
    }

void MavMOOS::handle_mavlink_attitude_msg(mavlink_message_t& message)
    {
        mavlink_attitude_t attitude_msg = {};
        mavlink_msg_attitude_decode(&message, &attitude_msg);
        double time = MOOSTime();
        
        Notify("VEHroll", attitude_msg.roll, time);
        Notify("VEHpitch", attitude_msg.pitch, time);
        Notify("VEHyaw", attitude_msg.yaw, time);
        
        Notify("VEHrollSpeed", attitude_msg.rollspeed, time);
        Notify("VEHpitchSpeed", attitude_msg.pitchspeed, time);
        Notify("VEHyawSpeed", attitude_msg.yawspeed, time);
    }

void MavMOOS::handle_mavlink_battery_msg(mavlink_message_t& message)
    {
        mavlink_battery_status_t battery_msg = {};
        mavlink_msg_battery_status_decode(&message, &battery_msg);
        Notify("batteryCellVoltage", battery_msg.voltages[0]);
        Notify("batteryPercentage", battery_msg.battery_remaining);
    }

void MavMOOS::handle_MOOS_desired_thrust_msg(CMOOSMsg& message)
    {
      // get data from MOOS msg
        std::vector<double> thrust;
        parseMatrix(message.GetString(),thrust);

      // send mavlink msg
      mavlink_manual_control_t control_msg = {};
      control_msg.x = thrust[0];
      control_msg.y = thrust[1];
      control_msg.z = thrust[2];
      control_msg.r = thrust[3];
      control_msg.buttons = 0;
      control_msg.target = autopilot_interface.system_id;

      mavlink_message_t msg;
      mavlink_msg_manual_control_encode(autopilot_interface.system_id, companion_id, &msg, &control_msg);
      autopilot_interface.write_message(msg);

    }

void MavMOOS::handle_MOOS_arm_msg(CMOOSMsg& message)
    {   
        mavlink_command_int_t command_struct = {};
        command_struct.command = MAV_CMD_COMPONENT_ARM_DISARM;
        command_struct.param1 = (int)(toupper(message.GetString()) == "TRUE");
        command_struct.target_system = autopilot_interface.system_id;
        command_struct.target_component = autopilot_interface.autopilot_id;

        mavlink_message_t msg;
        mavlink_msg_command_int_encode(autopilot_interface.system_id, companion_id, &msg, &command_struct);
        autopilot_interface.write_message(msg);
    }

void MavMOOS::_disarm_cmd()
    {
        mavlink_command_int_t command_struct = {};
        command_struct.command = MAV_CMD_COMPONENT_ARM_DISARM;
        command_struct.param1 = 0;
        command_struct.target_system = autopilot_interface.system_id;
        command_struct.target_component = autopilot_interface.autopilot_id;

        mavlink_message_t msg;
        mavlink_msg_command_int_encode(autopilot_interface.system_id, companion_id, &msg, &command_struct);
        autopilot_interface.write_message(msg);
    }





/* extracts the first matrix it finds in the string,
 * and pushes all values in it to a vector. The return value
 * is a pair of detected number of rows and colums in the matrix
 *
 * TODO: error handling, and fail-safes
 */
std::pair<int, int> MavMOOS::parseMatrix(std::string moos_string, std::vector<double>& num)
{
    int num_rows =1;
    int num_cols = 1;


    std::string str = moos_string;
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());



    int startMatrix = str.find('[') + 1;
    int endMatrix = str.find(']') - startMatrix;
    str = str.substr(startMatrix,endMatrix);

    size_t pos, p = 0;
    std::string row, entry;
    while ((pos = str.find(';')) != std::string::npos)
    {
        row = str.substr(0, pos);
        num_rows ++;

        while ((p = row.find(',')) != std::string::npos)
        {
            entry = row.substr(0,p);
            num.push_back(str2dbl(entry));
            row.erase(0, p + 1);
        }
        // get last entry in row
        num.push_back(str2dbl(row));
        str.erase(0, pos + 1);
    }
    // get last row in matrix
    while ((p = str.find(',')) != std::string::npos)
    {
        entry = str.substr(0,p);
        num.push_back(str2dbl(entry));
        str.erase(0, p + 1);
    }
    // get last entry in row
    num.push_back(str2dbl(str));


    num_cols = num.size()/num_rows;

    std::pair <int,int> return_pair = std::make_pair(num_rows,num_cols);

    return return_pair;

}

double MavMOOS::str2dbl(std::string str)
{
    double dbl = 0.0;
    std::istringstream istr(str);

    //make sure stream is locale-independent
    istr.imbue(std::locale("C"));
    istr >> dbl;
    return(dbl);
}