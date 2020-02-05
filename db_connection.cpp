#include "db_connection.hpp"

namespace access_control{

    Vehicle_access_control::Vehicle_access_control(std::string db_name,
                                                    std::string db_username,
                                                    std::string db_password):db_name(db_name),
                                                                                db_username(db_username),
                                                                                db_password(db_password){

 }

 bool Vehicle_access_control::connect(){
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

 Vehicle_access_control::~Vehicle_access_control(){
     con = NULL;
     driver = NULL;
 }
}