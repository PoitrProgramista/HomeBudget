#pragma once
#include <string>
#include <Windows.h>
#include "Prompt.h"

class Date
{
	static int currentDay;
	static int currentMonth;
	static int currentYear;
	static int thisMonthFirstDate;
	static int thisMonthLastDate;
	static int previousMonthFirstDate;
	static int previousMonthLastDate;
	static const int FIRST_AVAILABLE_DATE;

	static std::string addLeadingZero(int dateField);
	static int compose(int year, int month, int day);
	static int calculateDaysInMonth(int year, int month);
	static bool verify(std::string& date);
	static bool isLeapYear(int year);
	static bool firstDateGreaterOrEqual(int firstDate, int secondDate);
	static void checkYearBegin(int& year, int& month);
	static void setCurrentMonthLastDate();
	static void setCurrentMonthFirstDate();
	static void setPreviousMonthLastDate();
	static void setPreviousMonthFirstDate();

public:
	static void setCurrentDate();
	static void precalculateDates();
	static std::string getCurrentDate();
	static std::string enterDate();
	static std::string dateToString(int date);
	static int dateToInt(std::string date);
	static int getCurrentMonthLastDate();
	static int getCurrentMonthFirstDate();
	static int getPreviousMonthLastDate();
	static int getPreviousMonthFirstDate();
};

