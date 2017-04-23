#include "user.h"

User::User(void)
{
    std::cout << "User initialized" << '\n';
    this->logged = false;
}

std::string User::toString(void)
{
    return this->getName() + "\n<" + this->getEmail() + ">\n" + this->getStatus() + '\n';
}

std::string User::getName()
{
    return this->name;
}

void User::setName(std::string name)
{
    this->name = name;
}

std::string User::getEmail(void)
{
    return this->email;
}

void User::setEmail(std::string email)
{
    this->email = email;
}

std::string User::getPasswd(void)
{
    return this->passwd;
}

void User::setPasswd(std::string passwd)
{
    this->passwd = passwd;
}

bool User::isLogged(void)
{
    return this->logged;
}

void User::setLogged(bool b)
{
    this->logged = b;
}

std::string User::getStatus(void)
{
    return this->status;
}

void User::setStatus(std::string status)
{
    this->status = status;
}
