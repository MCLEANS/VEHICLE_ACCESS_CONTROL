#include "Catch/catch.hpp"
#include "vehicle_records.hpp"

TEST_CASE("CONNECT TO DATABASE"){

    access_control::Vehicle_records vehicle_records("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    REQUIRE(vehicle_records.connect() == true);
    
}

TEST_CASE("ADD NEW VEHICLE RECORD"){

    access_control::Vehicle_records vehicle_records("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    vehicle_records.connect();


    SECTION("INSERT FIRST VEHICLE DETAILS"){

    access_control::Vehicle_details vehicle_details = {
        "3E4D52",
        "KCA 235R",
        "JAMES THOMPSON",
        "+25478234768",
        "RTA0001"
    };

    REQUIRE(vehicle_records.insert(vehicle_details) == true);
    }

    SECTION("INSERT SECOND VEHICLE DETAILS"){

        access_control::Vehicle_details vehicle_details = {
            "42E34D2",
            "KAD 976Y",
            "PATRICK SIMONS",
            "+2547245678654",
            "RTA0002"
        };

        REQUIRE(vehicle_records.insert(vehicle_details) == true);
    }

}

TEST_CASE("READ FROM DATABASE"){

    access_control::Vehicle_records vehicle_records("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    REQUIRE(vehicle_records.connect() == true);

    SECTION("READ FIRST DATA FROM DATABASE"){
        access_control::Vehicle_details vehicle_details;
        std::string rfid ="42E34D2" ;

        vehicle_details = vehicle_records.read(rfid);
        CHECK(vehicle_details.plate_number == "KAD 976Y");
        CHECK(vehicle_details.vehicle_owner == "PATRICK SIMONS");
        CHECK(vehicle_details.phone_number == "+2547245678654");
        CHECK(vehicle_details.owner_employment_number == "RTA0002");
    }

    SECTION("READ SECOND DATA FROM DATABSE"){
        access_control::Vehicle_details vehicle_details;
        std::string rfid = "3E4D52";

        vehicle_details = vehicle_records.read(rfid);
        CHECK(vehicle_details.plate_number == "KCA 235R");
        CHECK(vehicle_details.vehicle_owner == "JAMES THOMPSON");
        CHECK(vehicle_details.phone_number == "+25478234768");
        CHECK(vehicle_details.owner_employment_number == "RTA0001");
        
    }

}

TEST_CASE("UPDATE DATABASE RECORDS"){
    access_control::Vehicle_records vehicle_records("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    vehicle_records.connect();

    SECTION("UPDATE  PHONE NUMBER"){
        std::string rfid = "42E34D2";
        std::string  new_phone_number = "+254729873565";

        REQUIRE(vehicle_records.update_phone_number(rfid,new_phone_number) == true);

    }

    SECTION("UPDATE VEHICLE_OWNER"){
        std::string rfid = "42E34D2";
        std::string new_vehicle_owner = "MARY JANE";

        REQUIRE(vehicle_records.update_vehicle_owner(rfid,new_vehicle_owner) == true);

    }

    SECTION("UPDATE VEHICLE OWNER EMPLOYMENT NUMBER"){
        std::string rfid = "42E34D2";
        std::string new_employment_number = "RTA0004";

        REQUIRE(vehicle_records.update_owner_employment_number(rfid,new_employment_number) == true);
    }
}



TEST_CASE("DELETE DATABASE RECORD"){
    access_control::Vehicle_records vehicle_records("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");

    vehicle_records.connect();

    SECTION("DELETE FIRST RECORD"){
        std::string rfid = "42E34D2";

        REQUIRE(vehicle_records.delete_record(rfid) == true);

    }
    
    SECTION("DELETE SECOND RECORD"){
        std::string rfid = "3E4D52";

        REQUIRE(vehicle_records.delete_record(rfid) == true);
    }
}