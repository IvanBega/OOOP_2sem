#include "Date.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
Date::Date() : _day(0), _month(0), _year(0)
{

}
Date::~Date()
{

}
const int Date::days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int Date::total_days_in_month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int Date::getDaysInMonth(int month, int year)
{
	if (month < 0 || month > 11)
		throw std::out_of_range("month was out of range");
	// check for leap year
	if (month != 1)
		return days_in_month[month];
	if (year % 4 == 3)
		return 29;
	return 28;
}
int Date::getDaysFromDate(const Date& date)
{
	return Date::getDaysFromDate(date._year, date._month, date._day);
}
int Date::getDaysFromDate(int year, int month, int day)
{
	int days = 0;
	int leapDays = year / 4;

	days = year * daysPearYear + leapDays + total_days_in_month[month] + day;

	if (year % 4 == 3 && month > 1)
		days++; // add leap day in the current year
	return days;
}
Date Date::setDateFromDays(int _days)
{
	Date date;
	int daysPer4Years = 4 * 365 + 1;
	int full4Years = _days / daysPer4Years;
	date._year = 4 * full4Years;
	int daysLeft = _days - daysPer4Years * full4Years;
	date._year += daysLeft / daysPearYear;
	daysLeft = daysLeft - daysPearYear * (daysLeft / daysPearYear);
	date._month = 0;
	while (daysLeft >= getDaysInMonth(date._month, date._year))
	{
		
		daysLeft = daysLeft - getDaysInMonth(date._month, date._year);
		date._month++;
	}
	date._day = daysLeft;

	return date;
}
void Date::addDays(int days)
{
	int this_days = Date::getDaysFromDate(this->_year, this->_month, this->_day);
	if (this_days + days < 0)
		throw std::out_of_range("");

	Date temp = Date::setDateFromDays(this_days + days);
	this->_year = temp._year;
	this->_month = temp._month;
	this->_day = temp._day;
}
int Date::getDay()
{
	return _day;
}
int Date::getMonth()
{
	return _month;
}
int Date::getYear()
{
	return _year;
}
void Date::setDay(int day)
{
	if (day < 0 || day >= Date::getDaysInMonth(_month, _year))
		throw std::out_of_range("");
	_day = day;
}
void Date::setMonth(int month)
{
	if (month < 0 || month > 11)
		throw std::out_of_range("");
	_month = month;
}
int Date::setYear(int year)
{
	if (year < 0)
		throw std::out_of_range("");
	_year = year;
}
std::string Date::toString() const
{
	std::string s;
	s.append(std::to_string(_year));
	s.append(" years, ");
	s.append(std::to_string(_month));
	s.append(" months, "); 
	s.append(std::to_string(_day));
	s.append("days");
	return s;
}
Date::Date(int year, int month, int day)
{
	if (day < 0 || month < 0 || month > 11 || year < 0)
		throw std::out_of_range("");
	if (day >= days_in_month[month])
	{
		if (year % 4 != 3)
			throw std::out_of_range("");
		if (year % 4 == 3 && month == 1 && day >= 29)
			throw std::out_of_range("");
	}

	_day = day;
	_month = month;
	_year = year;
}
std::ostream& operator<<(std::ostream& os, const Date& date)
{
	using namespace std;
	//os << date._year << " years, " << date._month << " months, " << date._day << " days\n";
	os << date.toString() << "\n";
	return os;
}
bool operator==(const Date& date1, const Date& date2)
{
	return (date1._year == date2._year &&
		date1._month == date2._month &&
		date1._day == date2._day);
}