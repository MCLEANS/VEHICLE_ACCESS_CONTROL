#ifndef _PARKING_STATUS_
#define _PARKING_STATUS_

#include <iostream>
#include "db_connection.hpp"

#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

namespace access_control{

    struct Parking_space{
        std::string lot;
        std::string status;
    };

    class Parking_status: public Vehicle_access_control{
        private:
            sql::Statement *stmt;
            sql::PreparedStatement *pstmt;
            sql::ResultSet *result;
            
        private:
        public:
        public:
            Parking_status(std::string db_name,
                            std::string db_username,
                            std::string db_password);
            ~Parking_status();
            bool update(Parking_space &parking_space);
            std::string retreive(std::string lot);

    };


}


#endif //_PARKING_STATUS_