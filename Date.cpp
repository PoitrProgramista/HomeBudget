#include "Date.h"


int Date::currentDay;
int Date::currentMonth;
int Date::currentYear;
int Date::thisMonthFirstDate;
int Date::thisMonthLastDate;
int Date::previousMonthFirstDate;
int Date::previousMonthLastDate;
const int Date::FIRST_AVAILABLE_DATE = 20000101;

std::string Date::enterDate()
{
	using namespace Prompt;

	std::string date;
	bool dateValid = false;

	while (dateValid == false)
	{
		system("cls");
		promptAndGet("Podaj date w formacie rrrr-mm-dd: ", date);

		dateValid = verify(date);
		if (dateValid == false)
			promptAndWait("Bledna data podaj date miedzy 2000-01-01 a ostatnim dniem biezacego miesiaca");
	}
	return date;
}

bool Date::verify(std::string& date)
{
	std::regex datePattern("\\b\\d{4}[-]\\d{2}[-]\\d{2}\\b");

	if (std::regex_match(date, datePattern))
	{
		int tempDate;
		tempDate = dateToInt(date);

		if (firstDateGreaterOrEqual(tempDate, FIRST_AVAILABLE_DATE)
			&& firstDateGreaterOrEqual(thisMonthLastDate, tempDate))
		{
			return true;
		}
	}
	return false;
}

int Date::dateToInt(std::string date)
{
	size_t iterator = 0;

	while (true)
	{
		iterator = date.find("-");

		if (iterator == std::string::npos)
		{
			break;
		}

		date.erase(date.begin() + iterator);
	}

	return std::stoi(date);
}

bool Date::firstDateGreaterOrEqual(int firstDate, int secondDate)
{
	if (firstDate >= secondDate)
		return true;
	else
		return false;
}

std::string Date::getCurrentDate()
{
	std::string year = std::to_string(currentYear);
	std::string month;
	std::string day;

	month = addLeadingZero(currentMonth);
	day = addLeadingZero(currentDay);

	return year + "-" + month + "-" + day;
}

int Date::compose(int year, int month, int day)
{
	std::string yearString, monthString, dayString, dateString;

	yearString = std::to_string(year);
	monthString = addLeadingZero(month);
	dayString = addLeadingZero(day);
	dateString = yearString + monthString + dayString;

	return std::stoi(dateString);
}

std::string Date::addLeadingZero(int dateField)
{
	std::string tempDay;

	if (dateField < 10)
	{
		tempDay = "0";
	}
	tempDay += std::to_string(dateField);

	return tempDay;
}

void Date::precalculateDates()
{
	setCurrentMonthFirstDate();
	setCurrentMonthLastDate();
	setPreviousMonthFirstDate();
	setPreviousMonthLastDate();
}

void Date::setCurrentMonthFirstDate()
{
	thisMonthFirstDate = compose(currentYear, currentMonth, 1);
}

void Date::setCurrentMonthLastDate()
{
	int currentMonthLastDay = calculateDaysInMonth(currentYear, currentMonth);
	thisMonthLastDate = compose(currentYear, currentMonth, currentMonthLastDay);
}

void Date::setPreviousMonthFirstDate()
{
	int month;
	int year;

	checkYearBegin(year, month);

	previousMonthFirstDate = compose(year, month, 1);
}

void Date::setPreviousMonthLastDate()
{
	int month;
	int year;

	checkYearBegin(year, month);

	int previousMonthLastDay = calculateDaysInMonth(year, month);
	previousMonthLastDate = compose(year, month, previousMonthLastDay);
}

void Date::checkYearBegin(int & year, int & month)
{
	const int JANUARY = 1;
	const int DECEMBER = 12;

	if (currentMonth == JANUARY)
	{
		month = DECEMBER;
		year = currentYear - 1;
	}
	else
	{
		month = currentMonth - 1;
		year = currentYear;
	}
}

int Date::calculateDaysInMonth(int year, int month)
{
	int daysInMonth = 31;
	bool leapYear = isLeapYear(year);

	if (month == 2)
	{
		daysInMonth = 28 + leapYear;
	}
	else
	{
		daysInMonth = 31 - ( month - 1 ) % 7 % 2;
	}

	return daysInMonth;
}

bool Date::isLeapYear(int year)
{
	return ( ( year % 4 ) && ( year % 100 != 0 ) ) || ( year % 400 );
}



std::string Date::dateToString(int date)
{
	const int AFTER_YEAR_POSITION = 4;
	const int AFTER_MONTH_POSITION = 7;

	std::string tempDate = std::to_string(date);
	tempDate.insert(AFTER_YEAR_POSITION, "-");
	tempDate.insert(AFTER_MONTH_POSITION, "-");

	return tempDate;
}

void Date::setCurrentDate()
{
	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	currentYear = currentDate.wYear;
	currentMonth = currentDate.wMonth;
	currentDay = currentDate.wDay;
}

int Date::getCurrentMonthLastDate()
{
	return thisMonthLastDate;
}

int Date::getCurrentMonthFirstDate()
{
	return thisMonthFirstDate;
}

int Date::getPreviousMonthLastDate()
{
	return previousMonthLastDate;
}

int Date::getPreviousMonthFirstDate()
{
	return previousMonthFirstDate;
}