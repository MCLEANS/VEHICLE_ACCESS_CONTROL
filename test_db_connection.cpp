#include "Catch/catch.hpp"
#include "db_connection.hpp"


TEST_CASE("CONNECTION TO THE VEHICLE_ACCESS_CONTROL DATABASE"){
    SECTION("FIRST TRIAL"){
        access_control::Vehicle_access_control vehicle_access_control("localhost/VEHICLE_ACCESS_CONTROL",
                                                                "root",
                                                                "mcleans123");

        REQUIRE(vehicle_access_control.connect() == true);
    }

    SECTION("SECOND TRIAL"){
        access_control::Vehicle_access_control vehicle_access_control("localhost/VEHICLE_ACCESS_CONTROL",
                                                                        "root",
                                                                        "mcleans123");
        
        REQUIRE(vehicle_access_control.connect() == true);
    }

    SECTION("THIRD TRIAL"){
        access_control::Vehicle_access_control vehicle_access_control("localhost/VEHICLE_ACCESS_CONTROL",
                                                                        "root",
                                                                        "mcleans123");
        REQUIRE(vehicle_access_control.connect() == true);
    }
}
