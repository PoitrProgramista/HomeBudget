#pragma once
#include "BillFile.h"

class ExpenseFile :
	public BillFile
{
	bool anyExpenses;

public:
	ExpenseFile();
	~ExpenseFile();
	bool areThereAnyExpenses();
	virtual bool load() override;
	virtual void save() override;
	virtual void add(std::string& date, std::string& item, std::string& amount) override;
};

