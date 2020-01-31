#ifndef _SECURITY_STAFF
#define _SECURITY_STAFF

#include <iostream>


namespace access_control{


struct Staff_details{
    std::string name;
    std::string employment_number;
    int clearence_level;
    std::string password;
    bool is_onduty;
};

class Security_staff{
    private:
        std::string db_name;
        std::string db_username;
        std::string db_password;

    private:
    public:
        bool present = true;
    public:
        Security_staff(std::string db_name,std::string db_username,std::string db_password):db_name(db_name),
                                                                                            db_username(db_username),
                                                                                            db_password(db_password);
        ~Security_staff();
        bool connect();
        


};

}
#endif //_SECURITY_SATFF