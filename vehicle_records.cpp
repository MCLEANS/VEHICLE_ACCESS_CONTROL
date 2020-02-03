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
    
}