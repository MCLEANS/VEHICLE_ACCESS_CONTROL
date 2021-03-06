#include "vehicle_records.hpp"

namespace access_control{

    Vehicle_records::Vehicle_records(std::string db_name,
                                        std::string db_username,
                                        std::string db_password):Vehicle_access_control(db_name,
                                                                                        db_username,
                                                                                        db_password){

    }

    Vehicle_records::~Vehicle_records(){
        con = NULL;
        pstmt = NULL;
        result = NULL ;
        stmt = NULL;
    }


    bool Vehicle_records::insert(Vehicle_details &vehicle_details){
        pstmt = con ->prepareStatement("INSERT INTO VEHICLE_RECORDS (RF_ID, PLATE_NUMBER, VEHICLE_OWNER, PHONE_NUMBER, OWNER_EMPLOYMENT_NUMBER) VALUES(?,?,?,?,?)  ");
        pstmt->setString(1,vehicle_details.rfid);
        pstmt->setString(2,vehicle_details.plate_number);
        pstmt->setString(3,vehicle_details.vehicle_owner);
        pstmt->setString(4,vehicle_details.phone_number);
        pstmt->setString(5,vehicle_details.owner_employment_number);
        pstmt->executeQuery();

        return true;
    }

    Vehicle_details Vehicle_records::read(std::string rfid){
        Vehicle_details vehicle_details;
        pstmt = con->prepareStatement("SELECT * FROM VEHICLE_RECORDS");
        result = pstmt->executeQuery();

        while(result -> next()){
            std::string retreived_rfid = result->getString(2);

            if(rfid == retreived_rfid){
                vehicle_details.rfid = result->getString(2).c_str();
                vehicle_details.plate_number = result->getString(3).c_str();
                vehicle_details.vehicle_owner = result->getString(4).c_str();
                vehicle_details.phone_number = result->getString(5).c_str();
                vehicle_details.owner_employment_number = result->getString(6).c_str();

                return vehicle_details;
            }
        }

       return vehicle_details;
       }
    bool Vehicle_records::update_phone_number(std::string rfid, std::string new_phone_number){
        pstmt = con->prepareStatement("UPDATE VEHICLE_RECORDS SET PHONE_NUMBER = ? WHERE RF_ID = ?");
        pstmt->setString(1,new_phone_number);
        pstmt->setString(2,rfid);
        pstmt->executeQuery();

        return true;
    }

    bool Vehicle_records::update_vehicle_owner(std::string rfid, std::string new_vehicle_owner){
        pstmt = con->prepareStatement("UPDATE VEHICLE_RECORDS SET VEHICLE_OWNER = ? WHERE RF_ID = ?");
        pstmt->setString(1,new_vehicle_owner);
        pstmt->setString(2,rfid);
        pstmt->executeQuery();

        return true;
    }

    bool Vehicle_records::update_owner_employment_number(std::string rfid, std::string new_employment_number){

        pstmt = con->prepareStatement("UPDATE VEHICLE_RECORDS SET OWNER_EMPLOYMENT_NUMBER = ? WHERE RF_ID = ?");
        pstmt->setString(1,new_employment_number);
        pstmt->setString(2,rfid);
        pstmt->executeQuery();

        return true;
    }

    bool Vehicle_records::delete_record(std::string rfid){
        pstmt = con->prepareStatement("DELETE FROM VEHICLE_RECORDS WHERE RF_ID = ?");
        pstmt->setString(1,rfid);
        result = pstmt->executeQuery();
        
        return true;
    }
}