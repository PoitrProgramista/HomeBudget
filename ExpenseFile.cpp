#include "ExpenseFile.h"

ExpenseFile::ExpenseFile()
{
	anyExpenses = load();
}

bool ExpenseFile::load()
{
	return file.Load("expenses.xml");
}

ExpenseFile::~ExpenseFile()
{
	if (anyExpenses == true)
		save();
}

void ExpenseFile::save()
{
	file.Save("expenses.xml");
}

bool ExpenseFile::areThereAnyExpenses()
{
	return anyExpenses;
}

void ExpenseFile::add(std::string& date, std::string & item, std::string& amount)
{
	int expenseID = 0;

	if (anyExpenses == true)
	{
		file.ResetPos();
		while (file.FindChildElem())
			expenseID = std::stoi(file.GetChildAttrib("expenseID"));
		expenseID++;
	}
	else
	{
		expenseID = 1;
		file.AddElem("EXPENSES");
		anyExpenses = true;
	}

	file.IntoElem();
	file.AddElem("EXPENSE");
	file.SetAttrib("expenseID", expenseID);
	file.AddChildElem("userID", getLoggedUserID());
	file.AddChildElem("date", date);
	file.AddChildElem("item", item);
	file.AddChildElem("amount", amount);
}
