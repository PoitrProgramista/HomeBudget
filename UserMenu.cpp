#include "UserMenu.h"

using namespace Prompt;

UserMenu::UserMenu(UserFile & users)
	:users(users)
{
	Date::setCurrentDate();
	Date::precalculateDates();
}

void UserMenu::displayUserMenu()
{
	bool isDone = false;

	while (isDone == false)
	{
		system("cls");
		prompt("MENU UZYTKOWNIKA\n");
		prompt("1. Dodaj przychod");
		prompt("2. Dodaj wydatek");
		prompt("3. Bilans z biezacego miesiaca");
		prompt("4. Bilans z poprzedniego miesiaca");
		prompt("5. Bilans z wybranego okresu");
		prompt("6. Zmien haslo");
		prompt("7. Wyloguj sie");

		char option;
		std::cin >> option;

		switch (option)
		{
			case '1':
				addIncome();
				break;
			case '2':
				addExpense();
				break;
			case '3':
				thisMonthBill();
				break;
			case '4':
				previousMonthBill();
				break;
			case '5':
				billForPeriod();
				break;
			case '6':
				changePassword();
				break;
			case '7':
				isDone = logout();
				break;
			default:
				promptAndWait("Prosze podac poprawny numer");
		}
	}
}

void UserMenu::addIncome()
{
	std::string date, item, amount;

	system("cls");
	prompt("DODAWANIE DOCHODU\n");
	displayDateChoice(date);

	system("cls");
	prompt("DODAWANIE DOCHODU\n");
	prompt("Prosze podac opis dochodu: ");

	std::cin.ignore();
	std::getline(std::cin, item);

	bool amountValid = false;

	while (amountValid == false)
	{
		system("cls");
		prompt("DODAWANIE DOCHODU\n");
		promptAndGet("Prosze podac kwote: ", amount);

		amountValid = verifyAmount(amount);

		if (amountValid)
			incomeFile.add(date, item, amount);
		else
		{
			system("cls");
			promptAndWait("Prosze podac poprawna kwote");
		}
	}
}

void UserMenu::addExpense()
{
	std::string date, item, amount;

	system("cls");
	prompt("DODAWANIE WYDATKU\n");
	displayDateChoice(date);

	system("cls");
	prompt("DODAWANIE WYDATKU\n");
	prompt("Prosze podac opis wydatku: ");

	std::cin.ignore();
	std::getline(std::cin, item);

	system("cls");
	prompt("DODAWANIE WYDATKU\n");
	promptAndGet("Prosze podac kwote: ", amount);

	verifyAmount(amount);

	expenseFile.add(date, item, amount);
}

void UserMenu::displayDateChoice(std::string& date)
{
	prompt("1. Dodaj z dzisiejsza data");
	prompt("2. Dodaj z inna data");

	char option;
	std::cin >> option;

	switch (option)
	{
		case '1':
			date = Date::getCurrentDate();
			break;
		case '2':
			date = Date::enterDate();
			break;
		default:
			promptAndWait("Prosze podac poprawny numer");
	}
}

bool UserMenu::verifyAmount(std::string & amount)
{
	std::regex amountPattern("^[0-9]+([,.][0-9]{1,2})?");

	if (std::regex_match(amount, amountPattern))
	{
		size_t dotPosition = amount.find(",");
		if (dotPosition != std::string::npos)
			amount.replace(dotPosition, 1, ".");
		return true;
	}
	return false;
}

void UserMenu::thisMonthBill()
{
	system("cls");
	prompt("BILANS Z BIEZACEGO MIESIACA\n");

	displayBill(Date::getCurrentMonthFirstDate(), Date::getCurrentMonthLastDate());
}

void UserMenu::previousMonthBill()
{
	system("cls");
	prompt("BILANS Z POPRZEDNIEGO MIESIACA\n");

	displayBill(Date::getPreviousMonthFirstDate(), Date::getPreviousMonthLastDate());
}

void UserMenu::billForPeriod()
{
	int beginDate, endDate;

	promptAndWait("Podaj date poczatku");
	beginDate = Date::dateToInt(Date::enterDate());

	promptAndWait("Podaj date konca");
	endDate = Date::dateToInt(Date::enterDate());

	system("cls");
	prompt("BILANS Z PODANEGO OKRESU\n");
	displayBill(beginDate, endDate);
}

void UserMenu::displayBill(int beginDate, int endDate)
{
	displayIncomes(beginDate, endDate);
	displayExpenses(beginDate, endDate);
	displaySummary();

	incomes.clear();
	expenses.clear();
	prompt("\nWcisnij klawisz aby wrocic");
	std::cin.ignore();
	std::cin.get();
}

void UserMenu::displayIncomes(int beginDate, int endDate)
{
	if (incomeFile.areThereAnyIncomes() == true)
	{
		prompt("Przychody:\n");

		incomeFile.populateContainer(beginDate, endDate, incomes);

		if (incomes.isEmpty() == false)
		{
			incomes.sortByDate();
			incomes.display();
			return;
		}

		prompt("Brak przychodow\n");
	}
}

void UserMenu::displayExpenses(int beginDate, int endDate)
{
	if (expenseFile.areThereAnyExpenses() == true)
	{
		prompt("Wydatki:\n");

		expenseFile.populateContainer(beginDate, endDate, expenses);

		if (expenses.isEmpty() == false)
		{
			expenses.sortByDate();
			expenses.display();
			return;
		}

		prompt("Brak wydatkow\n");
	}
}

void UserMenu::displaySummary()
{
	float incomeSum = 0, expenseSum = 0, difference;

	if (incomeFile.areThereAnyIncomes() == true)
	{
		incomeSum = incomes.sum();
	}

	if (expenseFile.areThereAnyExpenses() == true)
	{
		expenseSum = expenses.sum();
	}

	difference = incomeSum - expenseSum;

	prompt("Suma przychodow: ");
	std::cout << incomeSum << std::endl;
	prompt("Suma wydatkow: ");
	std::cout << expenseSum << std::endl;
	prompt("Bilans: ");
	std::cout << difference << std::endl;
}

bool UserMenu::logout()
{
	promptAndWait("Wylogowano");

	return true;
}

void UserMenu::changePassword()
{
	std::string haslo;

	system("cls");
	prompt("ZMIANA HASLA\n");
	promptAndGet("Podaj nowe haslo: ", haslo);

	users.changePassword(haslo);

	promptAndWait("Haslo zmienione");
}
