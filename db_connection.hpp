#ifndef _DB_CONNECTION_
#define _DB_CONNECTION_

#include <iostream>
#include <string.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

namespace access_control{

    class Vehicle_access_control{
        private:
        std::string db_name;
        std::string db_username;
        std::string db_password;

        

        private:
        public:
             sql::Driver *driver;
             sql::Connection *con;
        public:
            Vehicle_access_control(std::string db_name,
                                    std::string db_username,
                                    std::string db_password);





            ~Vehicle_access_control();

            bool connect();
    };
}




#endif //_DB_CONNECTION_