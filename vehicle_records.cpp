#include "vehicle_records.hpp"

namespace access_control{

    Vehicle_records::Vehicle_records(std::string db_name,
                                        std::string db_username,
                                        std::string db_password):db_name(db_name),
                                                                    db_username(db_username),
                                                                    db_password(db_password){

    }

    Vehicle_records::~Vehicle_records(){
        con = NULL;
        pstmt = NULL;
        result = NULL ;
        stmt = NULL;
    }
    
    bool Vehicle_records::connect(){
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

    bool Vehicle_records::insert(Vehicle_details &vehicle_details){
        pstmt = con ->prepareStatement("INSERT INTO VEHICLE_RECORDS (RF_ID, PLATE_NUMBER, VRHICLE_OWNER, PHONE_NUMBER, OWNER_EMPLOYMENT_NUMBER) VALUES(?,?,?,?,?)  ");
        pstmt->setString(1,vehicle_details.rfid);
        pstmt->setString(2,vehicle_details.plate_number);
        pstmt->setString(3,vehicle_details.vehicle_owner);
        pstmt->setString(4,vehicle_details.phone_number);
        pstmt->setString(5,vehicle_details.owner_employment_number);
        pstmt->executeQuery();

        return true;
    }
}