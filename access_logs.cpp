#include "access_logs.hpp"

namespace access_control{
    Access_logs::Access_logs(std::string db_name,
                                std::string db_username,
                                std::string db_password):Vehicle_access_control(db_name,
                                                                                db_username,
                                                                                db_password){

    }

    Access_logs::~Access_logs(){
        con = NULL;
        pstmt = NULL;
        result = NULL ;
        stmt = NULL;

    }

    bool Access_logs::insert(Access_entrance_details &access_details){
        pstmt = con->prepareStatement("INSERT INTO ACCESS_LOGS(RF_ID, PARKING_SPACE, IS_ONSITE) VALUES(?,?,?)");
        pstmt->setString(1,access_details.rfid);
        pstmt->setString(2,access_details.parking_space);
        pstmt->setString(3,access_details.is_onSite);
        pstmt->execute();

        return true;
    }

    bool Access_logs::update(Access_exit_details &access_details){
        pstmt = con->prepareStatement("UPDATE ACCESS_LOGS SET IS_ONSITE = ? WHERE RF_ID = ?");
        pstmt->setString(1,access_details.is_onSite);
        pstmt->setString(2,access_details.rfid);
        pstmt->executeQuery();
        
        return true;
    } 

    std::vector<Access_details> Access_logs::retreive_by_rfid(std::string rfid){
        std::vector<Access_details> retreived_details;

        pstmt = con->prepareStatement("SELECT * FROM ACCESS_LOGS");
        result = pstmt->executeQuery();

        while(result -> next()){
            Access_details access_details;
            access_details.rfid = result->getString(2).c_str();
            access_details.time_in = result->getString(3).c_str();
            access_details.time_out = result->getString(4).c_str();
            access_details.parking_space = result->getString(5).c_str();
            access_details.is_onSite = result->getString(6).c_str();

            retreived_details.push_back(access_details);
        }
        
        return retreived_details;


    }

}