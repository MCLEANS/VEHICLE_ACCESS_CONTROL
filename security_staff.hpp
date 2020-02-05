#ifndef _SECURITY_STAFF
#define _SECURITY_STAFF

#include <iostream>
#include <string.h>
#include "db_connection.hpp"

#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


namespace access_control{


struct Staff_details{
    std::string name;
    std::string employment_number;
    int clearance_level;
    std::string password;
    std::string is_onduty;
};

class Security_staff : public Vehicle_access_control{
    private:
        std::string db_name;
        std::string db_username;
        std::string db_password;

        
        sql::Statement *stmt;
        sql::PreparedStatement *pstmt;
        sql::ResultSet *result;

    private:
    public:
        bool present = true;
    public:
        Security_staff(std::string db_name,std::string db_username,std::string db_password);
        ~Security_staff();
        bool insert(Staff_details &Staff_details);
        Staff_details read(std::string employment_number);
        bool update_name(std::string name, std::string employment_number);
        bool update_clearance_level(int clearance_level,std::string employment_number);
        bool update_password(std::string password, std::string employment_number);
        bool update_is_onduty(std::string on_duty, std::string employment_number);
        bool delete_record(std::string employment_number);



};

}
#endif //_SECURITY_SATFF