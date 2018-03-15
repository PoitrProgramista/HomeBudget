#pragma once
#include "BillFile.h"

class IncomeFile :
	public BillFile
{
	bool anyIncomes;

public:
	IncomeFile();
	bool areThereAnyIncomes();
	virtual void save() override;
	virtual bool load() override;
	virtual void add(std::string& date, std::string& item, std::string& amount) override;
};

