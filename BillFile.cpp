#include "BillFile.h"


void BillFile::populateContainer(int beginDate, int endDate, BillContainer & bills)
{
	int date;
	float amount;
	std::string item;

	setPositionToFirstElement();
	while (file.FindElem())
	{
		file.FindChildElem("userID");
		int userID = std::stoi(file.GetChildData());

		if (userID == getLoggedUserID())
		{
			file.FindChildElem("date");
			date = Date::dateToInt(file.GetChildData());
			file.FindChildElem("item");
			item = file.GetChildData();
			file.FindChildElem("amount");
			amount = std::stof(file.GetChildData());

			if (( date >= beginDate ) && ( date <= endDate ))
				bills.addBill(date, item, amount);
		}
	}
}
