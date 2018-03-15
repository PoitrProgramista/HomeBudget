#pragma once
#include "User.h"
#include "File.h"

class UserFile : public File
{
	bool anyUsers;

	User findByLogin(std::string& providedLogin);
public:
	UserFile();
	~UserFile();
	virtual void save() override;
	virtual bool load() override;
	void changePassword(std::string& providedPassword);
	void add(std::string& name, std::string& surname, std::string& login, std::string& password);
	bool validate(std::string& login, std::string& password);
	bool areThereAnyUsers();
};

