#include "Catch/catch.hpp"
#include "parking_status.hpp"

TEST_CASE("CONNECT TO DATABASE"){
    access_control::Parking_status parking_status("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    REQUIRE(parking_status.connect() == true);

}

TEST_CASE("UPDATE PARKING STATUS"){
    access_control::Parking_status parking_status("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    
    parking_status.connect();

    SECTION("FIRST PARKING STATUS UPDATE"){

        access_control::Parking_space parking_space = {
            "A1",
            "TRUE"
        };

        parking_status.update(parking_space);
        CHECK(parking_status.retreive(parking_space.lot) == "TRUE");
    }

    SECTION("SECOND PARKING SPACE UPDATE"){
        access_control::Parking_space parking_space = {
            "A2",
            "TRUE"
        };

        parking_status.update(parking_space);
        CHECK(parking_status.retreive(parking_space.lot) == "TRUE");
    }

}