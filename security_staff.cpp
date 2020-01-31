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

}