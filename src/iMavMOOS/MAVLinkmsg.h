#include "MOOS/libMOOS/MOOSLib.h"
#include <bluerov2/mavlink.h>


Class MAVLinkmsg
{
	public:
		MAVLinkmsg(CMOOSCommClient &c);
		~MAVLinkmsg();


		virtual void reset();
		virtual bool is_full();
	protected:
		CMOOSCommClient comms;



}


Class MAVLinkHeartbeat
:MAVLinkmsg
{
	public:
		MAVLinkHeartbeat(CMOOSCommClient &c);
		~MAVLinkHeartbeat();

		mavlink_heartbeat_t mav_struct;


}