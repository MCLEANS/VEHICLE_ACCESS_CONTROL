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
}