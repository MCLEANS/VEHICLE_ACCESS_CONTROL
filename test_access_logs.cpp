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
        access_control::Access_entrance_details access_details = {
            "3E4D52",
            "A2",
            "TRUE"
        };

        REQUIRE(access_logs.insert(access_details) == true);

    }
    SECTION("SECOND ENTRANCE ACCESS LOG"){
        access_control::Access_entrance_details access_details = {
            "42E34D2",
            "A4",
            "TRUE"
        };

        REQUIRE(access_logs.insert(access_details) == true);
    }
}

TEST_CASE("UPDATE ACCESS LOGS"){
    access_control::Access_logs access_logs("localhost/VEHICLE_ACCESS_CONTROL",
                                            "root",
                                            "mcleans123");
    access_logs.connect();

    SECTION("FIRST ACCESS LOG  UPDATE"){
        access_control::Access_exit_details access_details = {
            "42E34D2",
            "FALSE"
        };

        REQUIRE(access_logs.update(access_details) == true);
    }

        SECTION("SECOND ACCESS LOG  UPDATE"){
        access_control::Access_exit_details access_details = {
            "3E4D52",
            "FALSE"
        };

        REQUIRE(access_logs.update(access_details) == true);
    }
}

TEST_CASE("RETREIVE LOGS FROM DATABASE"){
    access_control::Access_logs access_logs("localhost/VEHICLE_ACCESS_CONTROL",
                                            "root",
                                            "mcleans123");
    access_logs.connect();

    SECTION("FIRST RETREIVAL ATTEMPT"){

    std::vector<access_control::Access_details> retreived_details;
    std::string rfid = "42E34D2";

    retreived_details = access_logs.retreive_by_rfid(rfid);

    std::vector<access_control::Access_details>::iterator itr = retreived_details.begin();

    for(itr ; itr != retreived_details.end(); itr++){
        CHECK(itr->rfid == "42E34D2");
        
        }
    }

    SECTION("SECOND RETREIVAL ATTEMPT"){
        std::vector<access_control::Access_details> retreived_details;
        std::string rfid = "3E4D52";

        retreived_details = access_logs.retreive_by_rfid(rfid);

        std::vector<access_control::Access_details>::iterator itr = retreived_details.begin();

        for(itr; itr != retreived_details.end(); itr++){
            CHECK(itr->rfid == "3E4D52");
        }

    }



}