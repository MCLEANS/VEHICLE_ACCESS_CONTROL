#ifndef _VEHICLE_RECORDS
#define _VEHICLE_RECORDS

#include <iostream>
#include <string.h>

namespace access_control{
    struct Vehicle_details{
        std::string rfid;
        std::string plate_number;
        std::string vehicle_owner;
        std::string phone_number;
        std::string owner_employment_number;
    };

}




#endif //_VEHICLE_RECORDS