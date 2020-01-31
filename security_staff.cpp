#include "security_staff.hpp"

namespace access_control{

    Security_staff::Security_staff(std::string db_name,
                                    std::string db_username,
                                    std::string db_password):db_name(db_name),
                                                            db_username(db_username),
                                                            db_password(db_password){}


    Security_staff::~Security_staff(){

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

}