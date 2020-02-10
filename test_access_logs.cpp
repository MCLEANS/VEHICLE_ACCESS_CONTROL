#include "Catch/catch.hpp"
#include "access_logs.hpp"

TEST_CASE("CONNECT TO DATABASE"){
    access_control::Access_logs access_logs("localhost/VEHICLE_ACCESS_CONTROL",
                                            "root",
                                            "mcleans123");

    SECTION("FIRST CONNECTION ATTEMPT"){
        REQUIRE(access_logs.connect() == true);
    }
    SECTION("SECOND CONNECTION ATTEMPT"){
        REQUIRE(access_logs.connect() == true);
    }
    SECTION("THIRD CONNECTION ATTEMPT"){
        REQUIRE(access_logs.connect() == true);
    }
}

TEST_CASE("INSERT LOGS INTO THE DATABASE"){
    access_control::Access_logs access_logs("localhost/VEHICLE_ACCESS_CONTROL",
                                            "root",
                                            "mcleans123");
    access_logs.connect();

    SECTION("FIRST ENTRANCE ACCESS LOG "){
        access_control::Access_details access_details = {
            "3E4D52",
            "A2",
            "TRUE"
        };

        REQUIRE(access_logs.insert(access_details) == true);

    }
    SECTION("SECOND ENTRANCE ACCESS LOG"){
        access_control::Access_details access_details = {
            "42E34D2",
            "A4",
            "TRUE"
        };

        REQUIRE(access_logs.insert(access_details) == true);
    }
}

