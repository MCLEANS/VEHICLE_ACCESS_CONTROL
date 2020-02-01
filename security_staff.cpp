#include "security_staff.hpp"

namespace access_control{

    Security_staff::Security_staff(std::string db_name,
                                    std::string db_username,
                                    std::string db_password):db_name(db_name),
                                                            db_username(db_username),
                                                            db_password(db_password){}


    Security_staff::~Security_staff(){
        delete con;
        delete pstmt;
        delete result;

    }

    bool Security_staff::connect(){
        

        try{
            driver = get_driver_instance();
            con = driver->connect(this->db_name,this->db_username,this->db_password);
        }
        catch(sql::SQLException e){
            std::cout<<"could not connect to db, ERROR:  "<<e.what()<<std::endl;
            return false;
        }

        return true;
    }

    bool Security_staff::insert(Staff_details &staff_details){
        pstmt = con ->prepareStatement("INSERT INTO SECURITY_STAFF(NAME,EMPLOYMENT_ID,CLEARANCE_LEVEL,PASSWORD,ON_DUTY) VALUES(?,?,?,?,?)");
        pstmt->setString(1,staff_details.name);
        pstmt->setString(2,staff_details.employment_number);
        pstmt->setInt(3,staff_details.clearance_level);
        pstmt->setString(4,staff_details.password);
        pstmt->setBoolean(5,staff_details.is_onduty);
        
        return true;

    }

    Staff_details Security_staff::read(std::string employment_number){
        access_control::Staff_details staff_details;
        pstmt = con->prepareStatement("SELECT NAME,EMPLOYMENT_ID,CLEARANCE_LEVEL,PASSWORD,ON_DUTY FROM SECURITY_STAFF WHERE EMPLOYMENT_ID = ?");
        pstmt->setString(1,employment_number);
        result = pstmt->executeQuery();
        staff_details.name = result->getString(1);
        staff_details.employment_number = result->getString(2);
        staff_details.clearance_level = result->getInt(3);
        staff_details.password = result->getString(4);
        staff_details.is_onduty = result->getBoolean(5);

        return staff_details;


    }

    bool Security_staff::update_name(std::string name,std::string employment_number){
        pstmt = con->prepareStatement("UPDATE SECURITY_STAFF SET NAME = ? WHERE EMPLOYMENT_ID = ?");
        pstmt->setString(1,name);
        pstmt->setString(2,employment_number);
        pstmt->executeQuery();

        return true;


    }

    bool Security_staff::update_clearance_level(int clearance_level,std::string employment_number){
        pstmt = con->prepareStatement("UPDATE SECURITY_STAFF SET CLEARANCE_LEVEL = ? WHERE EMPLOYMENT_ID = ?");
        pstmt->setInt(1,clearance_level);
        pstmt->setString(2,employment_number);
        pstmt->executeQuery();

        return true;

    }

    bool Security_staff::update_password(std::string password, std::string employment_number){
        pstmt = con->prepareStatement("UPDATE SECURITY_STAFF SET PASSWORD = ? WHERE EMPLOYMENT_ID = ?");
        pstmt->setString(1,password);
        pstmt->setString(2,employment_number);
        pstmt->executeQuery();

        return true;
    }

    bool Security_staff::update_is_onduty(bool is_onduty,std::string employment_number){
         pstmt = con->prepareStatement("UPDATE SECURITY_STAFF SET ON_DUTY = ? WHERE EMPLOYMENT_ID = ?");
        pstmt->setBoolean(1,is_onduty);
        pstmt->setString(2,employment_number);
        pstmt->executeQuery();

        return true;
    }

    bool Security_staff::delete_record(std::string employment_number){
        pstmt = con->prepareStatement("DELETE FROM SECURITY_STAFF WHERE EMPLOYMENT_ID = ?");
        pstmt->setString(1,employment_number);
        result = pstmt->executeQuery();

        return true;
    }


}