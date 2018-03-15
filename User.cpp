#include "User.h"

User::User()
	:ID(0)
{
}

User::User(int ID, std::string & login, std::string & password)
	: ID(ID), login(login), password(password)
{
}

int User::getID()
{
	return ID;
}

std::string & User::getLogin()
{
	return login;
}

std::string & User::getPassword()
{
	return password;
}
