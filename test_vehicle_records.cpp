#include "Catch/catch.hpp"
#include <vehicle_records.hpp>

TEST_CASE("CONNECT TO DATABASE"){

    access_control::Vehicle_records vehicle_records("localhost/VEHICEL_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    REQUIRE(vehicle_records.connect == true);
    
}

TEST_CASE("ADD NEW VEHICLE RECORD"){

    access_control::Vehicle_records vehicle_records("localhost/VEHICEL_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    vehicle_records.connect();

    access_control::Vehicle_details vehicle_details = {
        "3E4D52",
        "KCA 235R",
        "JAMES THOMPSON",
        "+25478234768",
        "RTA0001"
    };

    REQUIRE(vehicle_records.insert(vehicle_details) == true);
    

}

