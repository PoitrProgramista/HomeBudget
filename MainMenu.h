#pragma once
#include "UserMenu.h"

class MainMenu
{
	UserFile users;

	void logIn();
	void signIn();
	bool quit();

public:
	MainMenu();
	void displayMainMenu();
};

