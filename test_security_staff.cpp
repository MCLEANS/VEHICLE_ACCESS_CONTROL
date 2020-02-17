#include "Catch/catch.hpp"
#include "security_staff.hpp"

TEST_CASE("CONNECT TO VEHICLE_ACCESS_CONTROL DATABASE"){

    access_control::Security_staff db_staff_details("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    
    SECTION("CONNECTING TO THE DATABASE"){
        REQUIRE(db_staff_details.connect() == true);
    }

}


TEST_CASE("INSERT SECURITY STAFF DATA INTO THE DATABASE"){

    access_control::Security_staff db_staff_details("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    db_staff_details.connect();

    SECTION("INSERT FIRST DATA POINT "){

        access_control::Staff_details staff_details = {
            "JACK MCLEANS",
            "QME0001",
            4,
            "mcleans_jack",
            "FALSE"
            };

        REQUIRE(db_staff_details.insert(staff_details) == true);

        access_control::Staff_details retreived_staff_details;
        retreived_staff_details = db_staff_details.read(staff_details.employment_number);

        CHECK(retreived_staff_details.name == "JACK MCLEANS");
        CHECK(retreived_staff_details.is_onduty == "FALSE");
        CHECK(retreived_staff_details.clearance_level == 4);
        CHECK(retreived_staff_details.password == "mcleans_jack");

        }

    SECTION("INSERT SECOND DATA POINT"){
        access_control::Staff_details staff_details = {
            "JIM PARSONS",
            "QME0008",
            2,
            "jim_parsons",
            "FALSE"
        };

        REQUIRE(db_staff_details.insert(staff_details) == true);

        access_control::Staff_details retreived_staff_details;
        retreived_staff_details = db_staff_details.read(staff_details.employment_number);

        CHECK(retreived_staff_details.name == "JIM PARSONS");
        CHECK(retreived_staff_details.is_onduty == "FALSE");
        CHECK(retreived_staff_details.clearance_level == 2);
        CHECK(retreived_staff_details.password == "jim_parsons");
    }
    }

 
TEST_CASE("READ SECURITY STAFF DATA FROM DATABASE"){

   access_control::Security_staff db_staff_details("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
  
    db_staff_details.connect();

    access_control::Staff_details staff_details;
    std::string employment_number ="QME0001";

    staff_details = db_staff_details.read(employment_number);

    REQUIRE(staff_details.name == "JACK MCLEANS");
    REQUIRE(staff_details.employment_number == "QME0001");
    REQUIRE(staff_details.clearance_level == 4);
    REQUIRE(staff_details.password == "mcleans_jack");
    REQUIRE(staff_details.is_onduty == "FALSE");

}

TEST_CASE("UPDATE SECURITY STAFF DETAILS FROM DATABASE"){

    access_control::Security_staff db_staff_details("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    db_staff_details.connect();

    SECTION("FIRST UPDATE ATTEMPT"){

        access_control::Staff_details staff_details = {
                "PAUL MCLEANS",
                "QME0001",
                5,
                "mcleans_jack",
                "TRUE"
                };
        std::string employment_number = "QME0001";

        SECTION("UPDATE SECURITY STAFF NAME"){
        
            REQUIRE(db_staff_details.update_name(staff_details.name,employment_number) == true);
        }
        SECTION("UPDATE SECURITY STAFF CLEARANCE LEVEL"){

            REQUIRE(db_staff_details.update_clearance_level(staff_details.clearance_level,employment_number) == true); 
        }
        SECTION("UPDATE SECURITY STAFF PASSWORD"){

            REQUIRE(db_staff_details.update_password(staff_details.password,employment_number) == true);
        }
        SECTION("UPDATE SECURITY STAFF DUTY STATUS"){

            REQUIRE(db_staff_details.update_is_onduty(staff_details.is_onduty,employment_number) == true);
        
        }

        SECTION("DETAILS VERIFICATION"){

            access_control::Staff_details retreived_staff_details;
            retreived_staff_details = db_staff_details.read(employment_number);

            CHECK(retreived_staff_details.name == "PAUL MCLEANS");
            CHECK(retreived_staff_details.is_onduty == "TRUE");
            CHECK(retreived_staff_details.clearance_level == 5);
            CHECK(retreived_staff_details.password == "mcleans_jack");
        }
    }
}

TEST_CASE("DELETE SECURITY STAFF DETAILS FROM DATABASE"){
    access_control::Security_staff db_staff_details("localhost/VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    db_staff_details.connect();

    SECTION("DELETE ID QME0001"){
        std::string employment_number = "QME0001";
      REQUIRE(db_staff_details.delete_record(employment_number) == true);
    }

    SECTION("DELETE ID QME0008"){
        std::string employment_number = "QME0008";
        REQUIRE(db_staff_details.delete_record(employment_number) == true);
    }
}



