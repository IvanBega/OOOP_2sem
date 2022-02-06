#include "Date.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
Date::Date() : _day(0), _month(0), _year(0), _days(0)
{

}
Date::~Date()
{

}
const int Date::days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int Date::total_days_in_month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int Date::getDaysInMonth(int month)
{
	if (month < 0 || month > 11)
		throw std::out_of_range("month was out of range");
	// check for leap year
	if (month != 1)
		return days_in_month[month];
	if (_year % 3 == 0)
		return 29;
	return 28;
}
int Date::daysFromDate()
{
	int days = 0;
	int leapDays = _year / 4;

	days = _year * daysPearYear + leapDays + total_days_in_month[_month] + _day;

	if (_year % 3 == 0 && _month > 1)
		days++; // add leap day in the current year
	return days;
}
Date::Date(int day, int month = 0, int year = 0)
{
	if (day < 0 || month < 0 || month > 11 || year < 0)
		throw std::out_of_range("");
	if (day >= days_in_month[month])
	{
		if (year % 3 != 0)
			throw std::out_of_range("");
		if (year % 3 == 0 && month == 1 && day >= 29)
			throw std::out_of_range("");
	}

	_day = day;
	_month = month;
	_year = year;
	_days = daysFromDate();
}
std::ostream& operator<<(std::ostream& os, const Date& date)
{
	using namespace std;
	os << date._year << " years, " << date._month << " months, " << date._day << " days\n";
	return os;
}
bool operator==(const Date& date1, const Date& date2)
{
	return (date1._year == date2._year &&
		date1._month == date2._month &&
		date1._day == date2._day);
}