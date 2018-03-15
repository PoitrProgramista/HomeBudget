#pragma once
#include "File.h"
#include "BillContainer.h"

class BillFile :
	public File
{
public:
	virtual void add(std::string& date, std::string& item, std::string& amount) = 0;
	void populateContainer(int beginDate, int endDate, BillContainer& bills);
};

