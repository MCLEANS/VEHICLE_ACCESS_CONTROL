#ifndef _VEHICLE_RECORDS
#define _VEHICLE_RECORDS

#include <iostream>
#include <string.h>
#include "db_connection.hpp"

#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

namespace access_control{
    struct Vehicle_details{
        std::string rfid;
        std::string plate_number;
        std::string vehicle_owner;
        std::string phone_number;
        std::string owner_employment_number;
    };

    class Vehicle_records : public Vehicle_access_control{
        private:
            std::string db_name;
            std::string db_username;
            std::string db_password;

            sql::Statement *stmt;
            sql::PreparedStatement *pstmt;
            sql::ResultSet *result;


        private:
        public:
        public:
            Vehicle_records(std::string db_name,
                            std::string db_username,
                            std::string db_passsword);
            ~Vehicle_records();
            bool insert(Vehicle_details &vehicle_details);
            Vehicle_details read(std::string rfid);
            bool update_phone_number(std::string rfid , std::string new_phone_number);
            bool update_vehicle_owner(std::string rfid, std::string new_vehicle_owner);
            bool update_owner_employment_number(std::string rfid,std::string new_employment_number);
            bool delete_record(std::string rfid);
    };

}





#endif //_VEHICLE_RECORDS