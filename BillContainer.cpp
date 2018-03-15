#include "BillContainer.h"


float BillContainer::sum()
{
	float sum = 0.0f;

	for (size_t i = 0; i < bills.size(); i++)
		sum += bills[i].getAmount();

	return sum;
}

void BillContainer::sortByDate()
{
	auto sortCondition = [](Bill& firstDate, Bill&secondDate)
	{
		return firstDate.getDate() < secondDate.getDate();
	};

	std::sort(bills.begin(), bills.end(), sortCondition);
}

void BillContainer::display()
{
	for (size_t i = 0; i < bills.size(); i++)
	{
		std::cout << Date::dateToString(bills[i].getDate()) << " " << bills[i].getItem() << " " << bills[i].getAmount() << std::endl;
	}
	std::cout << std::endl;
}

void BillContainer::addBill(int date, std::string & item, float amount)
{
	bills.emplace_back(date, item, amount);
}

void BillContainer::clear()
{
	bills.clear();
}

bool BillContainer::isEmpty()
{
	return bills.empty();
}
