#ifndef _SECURITY_STAFF
#define _SECURITY_STAFF

#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


namespace access_control{


struct Staff_details{
    std::string name;
    std::string employment_number;
    int clearence_level;
    std::string password;
    bool is_onduty;
};

class Security_staff{
    private:
        std::string db_name;
        std::string db_username;
        std::string db_password;

        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::PreparedStatement *pstmt;

    private:
    public:
        bool present = true;
    public:
        Security_staff(std::string db_name,std::string db_username,std::string db_password);
        ~Security_staff();
        bool connect();
        bool insert(Staff_details &Staff_details);
        Staff_details read(std::string employment_number);
        bool update_name(std::string name, std::string employment_number);
        bool update_clearence_level(int clearence_level,std::string employment_number);
        bool update_password(std::string password, std::string employment_number);
        bool update_is_onduty(bool on_duty, std::string employment_number);
        bool delete_record(std::string employment_number);



};

}
#endif //_SECURITY_SATFF