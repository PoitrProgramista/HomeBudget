#pragma once
#include <string>

class User
{
	int ID;
	std::string login;
	std::string password;

public:
	User();
	User(int ID, std::string& login, std::string& password);
	int getID();
	std::string& getLogin();
	std::string& getPassword();
};

