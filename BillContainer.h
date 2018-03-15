#pragma once
#include "Bill.h"
#include "Date.h"
#include <vector>
#include <iostream>
#include <algorithm>

class BillContainer
{
	std::vector<Bill> bills;

public:
	void sortByDate();
	void display();
	void addBill(int date, std::string& item, float amount);
	void clear();
	float sum();
	bool isEmpty();
};

