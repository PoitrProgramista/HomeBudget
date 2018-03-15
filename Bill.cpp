#include "Bill.h"

Bill::Bill(int date, std::string & item, float amount)
	:date(date), item(item), amount(amount)
{
}

int Bill::getDate()
{
	return date;
}

std::string & Bill::getItem()
{
	return item;
}

float Bill::getAmount()
{
	return amount;
}
