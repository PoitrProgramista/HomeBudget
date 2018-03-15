#pragma once
#include "UserFile.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "Prompt.h"

class UserMenu
{
	BillContainer incomes;
	BillContainer expenses;
	IncomeFile incomeFile;
	ExpenseFile expenseFile;
	UserFile& users;

	void displayBill(int beginDate, int endDate);
	void displaySummary();
	void displayIncomes(int beginDate, int endDate);
	void displayExpenses(int beginDate, int endDate);
	void addIncome();
	void addExpense();
	void previousMonthBill();
	void thisMonthBill();
	void billForPeriod();
	void changePassword();
	bool verifyAmount(std::string& amount);
	void displayDateChoice(std::string& date);
	bool logout();

public:
	UserMenu(UserFile& users);
	void displayUserMenu();
};

