#include "UserFile.h"


UserFile::UserFile()
{
	anyUsers = load();
}

bool UserFile::load()
{
	return file.Load("users.xml");
}

void UserFile::save()
{
	file.Save("users.xml");
}


void UserFile::add(std::string & name, std::string & surname, std::string & login, std::string & password)
{
	int userID = 0;

	if (anyUsers == true)
	{
		file.ResetPos();
		while (file.FindChildElem())
			userID = std::stoi(file.GetChildAttrib("userID"));
		userID++;
	}
	else
	{
		userID = 1;
		file.AddElem("USERS");
	}

	file.IntoElem();
	file.AddElem("USER");
	file.SetAttrib("userID", userID);
	file.AddChildElem("login", login);
	file.AddChildElem("password", password);
	file.AddChildElem("name", name);
	file.AddChildElem("surname", surname);

	save();
}

bool UserFile::validate(std::string & login, std::string & password)
{
	User loggingUser = findByLogin(login);

	if (( loggingUser.getID() != 0 ) && ( loggingUser.getPassword() == password ))
	{
		setLoggedUserID(loggingUser.getID());
		return true;
	}

	return false;
}

User UserFile::findByLogin(std::string & providedLogin)
{
	int ID;
	std::string login, password;

	setPositionToFirstElement();

	while (file.FindChildElem())
	{
		if (file.GetChildData() == providedLogin)
		{
			ID = std::stoi(file.GetAttrib("userID"));
			file.FindChildElem();
			password = file.GetChildData();
			return User(ID, providedLogin, password);
		}
		file.FindElem();
	}
	return User();
}

void UserFile::changePassword(std::string& providedPassword)
{
	setPositionToFirstElement();

	while (file.FindElem())
	{
		if (file.GetAttrib("userID") == std::to_string(getLoggedUserID()))
		{
			file.FindChildElem("password");
			file.SetChildData(providedPassword);
		}
	}
}

bool UserFile::areThereAnyUsers()
{
	return anyUsers;
}




