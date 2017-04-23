#ifndef __H__DATABASE
#define __H__DATABASE

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>

#include "base/user.h"

#define HOST "localhost"
#define USER "your_user"
#define PASS "your_password"
#define DATB "CryptoChat"

class Database
{
    private:
        sql::Driver     *driver;
        sql::Connection *con;
    public:
        bool init;
        Database (void);
        bool Auth(User* u);
        virtual ~Database ();
};

#endif
