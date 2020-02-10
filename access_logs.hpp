#ifndef _ACCESS_LOGS_
#define _ACCESS_LOGS_

#include <iostream>
#include <vector>

#include "db_connection.hpp"
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

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
        std::string parking_space;
        std::string is_onSite;
    };

    class Access_logs : public Vehicle_access_control{
        private:
            sql::Statement *stmt;
            sql::PreparedStatement *pstmt;
            sql::ResultSet *result;
            
        private:
        public:
        public:
            Access_logs(std::string db_name,
                        std::string db_username,
                        std::string db_password);

            bool insert(Access_entrance_details &access_details);
            bool update(Access_exit_details &access_details);
            std::vector<Access_details> retreive_by_rfid(std::string rfid);
            

            ~Access_logs();
    };

}


#endif //_ACCESS_LOGS