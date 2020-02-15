#include "parking_status.hpp"

namespace access_control{
    
    Parking_status::Parking_status(std::string db_name,
                                    std::string db_username,
                                    std::string db_password):Vehicle_access_control(db_name,
                                                                                     db_username,
                                                                                     db_password){
            
      }              


    Parking_status::~Parking_status(){
         con = NULL;
        pstmt = NULL;
        result = NULL ;
        stmt = NULL;

    }

    bool Parking_status::update(Parking_space &parking_space){
        pstmt = con->prepareStatement("UPDATE PARKING_STATUS SET IS_OCCUPIED = ? WHERE SPACE = ?");
        pstmt->setString(1,parking_space.status);
        pstmt->setString(2,parking_space.lot);
        pstmt->executeQuery();

        return true;
    }

    std::string Parking_status::retreive(std::string lot){
        std::string status;

         pstmt = con->prepareStatement("SELECT * FROM PARKING_STATUS");
        result = pstmt->executeQuery();

        while(result -> next()){
            std::string retreived_space = result->getString(2);

            if(lot== retreived_space){
                
                status = result->getString(3).c_str();
               

                return status;
                
            }
         }

         return status;
    }

}