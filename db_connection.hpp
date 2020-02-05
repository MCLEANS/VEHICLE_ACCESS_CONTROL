#ifndef _DB_CONNECTION_
#define _DB_CONNECTION_

#include <iostream>

namespace access_control{

    class Vehicle_access_control{
        private:
        std::string db_name;
        std::string db_username;
        std::string db_password;
        private:
        public:
        public:
            Vehicle_access_control(std::string db_name,
                                    std::string db_username,
                                    std::string db_password);

            bool connect();
    };
}




#endif //_DB_CONNECTION_