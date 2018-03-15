#pragma once
#include <string>

class Bill
{
	int date;
	std::string item;
	float amount;

public:
	Bill(int date, std::string& item, float amount);
	int getDate();
	std::string& getItem();
	float getAmount();
};

