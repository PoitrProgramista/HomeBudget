#include "IncomeFile.h"

IncomeFile::IncomeFile()
{
	anyIncomes = load();
}

bool IncomeFile::load()
{
	return file.Load("incomes.xml");
}

bool IncomeFile::areThereAnyIncomes()
{
	return anyIncomes;
}

void IncomeFile::add(std::string& date, std::string & item, std::string& amount)
{
	int incomeID = 0;

	if (anyIncomes == true)
	{
		file.ResetPos();
		while (file.FindChildElem())
			incomeID = std::stoi(file.GetChildAttrib("incomeID"));
		incomeID++;
	}
	else
	{
		incomeID = 1;
		file.AddElem("INCOMES");
		anyIncomes = true;
	}

	file.IntoElem();
	file.AddElem("INCOME");
	file.SetAttrib("incomeID", incomeID);
	file.AddChildElem("userID", getLoggedUserID());
	file.AddChildElem("date", date);
	file.AddChildElem("item", item);
	file.AddChildElem("amount", amount);

	save();
}

void IncomeFile::save()
{
	file.Save("incomes.xml");
}