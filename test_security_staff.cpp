#include "Catch/catch.hpp"
#include "security_staff.hpp"

TEST_CASE("EVERYTHING IS OK"){

    access_control::Security_staff security;
    
    REQUIRE(security.present == true);
}


