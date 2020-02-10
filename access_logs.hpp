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

    struct Access_details{
        std::string rfid;
        std::string time_in;
        std::string time_out;
        std::string is_onSite;
    };

    class Access_logs : public Vehicle_access_control{
        private:
            
        private:
        public:
        public:
            Access_logs(std::string db_name,
                        std::string db_username,
                        std::string db_password);

            bool insert(Access_entrance_details &access_details);
            bool update(Access_exit_details &access_details);
            Access_details retreive_by_rfid();
            

            ~Access_logs();
    };

}


#endif //_ACCESS_LOGS