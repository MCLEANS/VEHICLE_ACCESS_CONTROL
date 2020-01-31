#include "Catch/catch.hpp"
#include "security_staff.hpp"

TEST_CASE("CONNECT TO VEHICLE_ACCESS_CONTROL DATABASE"){

    access_control::Security_staff db_staff_details("VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    
    SECTION("CONNECTING TO THE DATABASE"){
        REQUIRE(db_staff_details.connect() == true);
    }

}

TEST_CASE("INSERT SECURITY STAFF DATA INTO THE DATABASE"){

    access_control::Security_staff db_staff_details("VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    db_staff_details.connect();

    SECTION("INSERT FIRST DATA POINT "){

        Staff_details staff_details = {
            "JACK MCLEANS",
            "QME0001",
            4,
            "mcleans_jack",
            "FALSE"
            };

        REQUIRE(db_staff_details.insert(staff_details ) == true);

        }
    }
    
TEST_CASE("READ SECURITY STAFF DATA FROM DATABASE"){

    access_control::Security_staff db_staff_details("VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    db_staff_details.connect();

    Staff_details staff_details;

    staff_details = db_staff_details.read();

    REQUIRE(staff_details.name = "JACK MCLEANS");
    REQUIRE(staff_details.employment_number = "QME0001");
    REQUIRE(staff_details.clearence_level = 4);
    REQUIRE(staff_details.password = "mcleans_jack");
    REQUIRE(staff_details.is_onduty = "FALSE");

}

TEST_CASE("UPDATE SECURITY STAFF DETAILS FROM DATABASE"){

    access_control::Security_staff db_staff_details("VEHICLE_ACCESS_CONTROL",
                                                    "root",
                                                    "mcleans123");
    db_staff_details.connect();

     Staff_details staff_details = {
            "JACK MCLEANS",
            "QME0001",
            4,
            "mcleans_jack",
            "FALSE"
            };

    REQUIRE(db_staff_details.update_name(staff_details.name,ID) == true);
    REQUIRE(db_staff_details.update_employment_number(staff_details.employment_number,ID) == true);
    REQUIRE(db_staff_details.update_clearence_level(staff_details.clearence_level,ID) == true); 
    REQUIRE(db_staff_details.update_password(staff_details.password,ID) == true);
    REQUIRE(db_staff_details.update_is_onduty(staff_details.is_onduty,ID) == true);
    

}





