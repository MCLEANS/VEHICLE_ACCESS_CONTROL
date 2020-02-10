#ifndef _ACCESS_LOGS_
#define _ACCESS_LOGS_

#include <iostream>
#include "db_connection.hpp"

namespace access_control{
    struct Access_entrance_details{
        std::string rfid;
        std::string parking_space;
        std::string is_onSite;

    };

    struct Access_exit_details{
        std::string rfid;
        std::string is_onSite;
    };

    class Access_logs : public Vehicle_access_control{
        private:
        private:
        public:
        public:
    };

}


#endif //_ACCESS_LOGS