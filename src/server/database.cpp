//============================================================================
// Name        : Database.cpp
// Author      : Lincon Dias
// Version     : 0.0.1a
// Copyright   : MIT License
// Description : An interface for mysql database operations
//============================================================================
#include "database.h"

Database::Database(void)
{
    this->init = false;

    try
    {
        this->driver    = get_driver_instance();
        this->con       = this->driver->connect(HOST, USER, PASS);
        this->con->setSchema(DATB);

        this->init = true;
    }
    catch( sql::SQLException &e )
    {
        std::cout << "Failed on Database" << '\n';
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << '\n';
    }

    std::cout << "Database initialized." << '\n';
}

/**
 * Auth an User in the database
 */
bool Database::Auth(User* u)
{
    sql::PreparedStatement  *stmt;
    sql::ResultSet  *res;

    if ( !this->init ){
        std::cout << "Database not initialized, aborting." << "\n";
        return false;
    }

    if ( u->isLogged() )
    {
        std::cout << "User already logged, escacping." << '\n';
        return true;
    }

    try
    {
        std::cout << "Trying to auth user " << u->getEmail() << " " << u->getPasswd() << '\n';
        stmt = this->con->prepareStatement("SELECT NAME, STATUS FROM USERS WHERE EMAIL=? AND PASSWD=?");
        stmt->setString(1, u->getEmail());
        stmt->setString(2, u->getPasswd());
        res  = stmt->executeQuery();
        res->next();

        u->setName(res->getString("NAME"));
        u->setStatus(res->getString("STATUS"));
        u->setLogged(true);

    }
    catch( sql::SQLException &e )
    {
        std::cout << "Failed on Database" << '\n';
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << '\n';
        return false;
    }

    delete stmt;
    delete res;

    if ( u->isLogged() )
        return true;
    return false;
}

Database::~Database(void)
{
    std::cout << "Finishing database." << '\n';
    delete this->con;
}
