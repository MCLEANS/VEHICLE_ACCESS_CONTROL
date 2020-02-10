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