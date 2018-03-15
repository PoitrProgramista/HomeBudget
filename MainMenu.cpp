#include "MainMenu.h"

using namespace Prompt;

MainMenu::MainMenu()
{
	if (users.areThereAnyUsers() == false)
	{
		promptAndWait("WITAJ PO RAZ PIERWSZY!");
		signIn();
	}
}

void MainMenu::displayMainMenu()
{
	bool isDone = false;

	while (isDone == false)
	{
		system("cls");
		prompt("MENU GLOWNE\n");
		prompt("1. Logowanie");
		prompt("2. Rejestracja");
		prompt("3. Zamknij program");

		char option;
		std::cin >> option;

		switch (option)
		{
			case '1':
				logIn();
				break;
			case '2':
				signIn();
				break;
			case '3':
				isDone = quit();
				break;
			default:
				promptAndWait("Prosze podac poprawny numer");
		}
	}
}

void MainMenu::logIn()
{
	std::string login, password;

	system("cls");
	prompt("LOGOWANIE\n");
	promptAndGet("Podaj login: ", login);
	promptAndGet("Podaj haslo: ", password);

	if (users.validate(login, password) == true)
	{
		promptAndWait("Zalogowano");

		UserMenu userMenu(users);
		userMenu.displayUserMenu();
	}
	else
	{
		promptAndWait("Bledna nazwa uzytkownika lub haslo");
	}
}

void MainMenu::signIn()
{
	std::string name, surname, login, password;

	system("cls");
	prompt("REJESTRACJA\n");
	promptAndGet("Podaj imie: ", name);
	promptAndGet("Podaj nazwisko: ", surname);
	promptAndGet("Podaj login: ", login);
	promptAndGet("Podaj haslo: ", password);

	users.add(name, surname, login, password);

	promptAndWait("Zarejestrowano");
}

bool MainMenu::quit()
{
	return true;
}
