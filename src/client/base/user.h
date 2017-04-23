#ifndef __H__USER
#define __H__USER

#include <string>
#include <iostream>

class User
{
    private:
        std::string name;
        std::string email;
        std::string passwd;
        std::string status;
        bool logged;

    public:
        User (void);
        std::string getName(void);
        void setName(std::string name);
        std::string getEmail(void);
        void setEmail(std::string email);
        std::string getStatus(void);
        void setStatus(std::string status);
        std::string getPasswd(void);
        void setPasswd(std::string status);
        bool isLogged(void);
        void setLogged(bool b);
        std::string toString(void);
        //virtual ~User ();
};

#endif
