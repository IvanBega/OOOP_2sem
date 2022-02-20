#include "Date.h"
#include "Utils.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
/// <summary>
/// empty constructor
/// </summary>
Date::Date() : _day(0), _month(0), _year(0)
{

}
/// <summary>
/// destructor
/// </summary>
Date::~Date()
{

}
/// <summary>
/// stores amount of days in each month
/// </summary>
const int Date::days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
/// <summary>
/// stores total amount of days in months
/// </summary>
const int Date::total_days_in_month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
/// <summary>
/// gets amount of days in month
/// </summary>
/// <param name="month">month</param>
/// <param name="year">year</param>
/// <returns>returns amount of days in month</returns>
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
/// <summary>
/// gets total amount of days in date, starting from 0/0/0000
/// </summary>
/// <param name="date">date</param>
/// <returns>returns total amount of days</returns>
int Date::getDaysFromDate(const Date& date)
{
	return Date::getDaysFromDate(date._year, date._month, date._day);
}
/// <summary>
/// gets total amount of days in date, starting from 0-th day, 0-th month, 0-th year
/// </summary>
/// <param name="year">year</param>
/// <param name="month">month</param>
/// <param name="day">day</param>
/// <returns>returns total amount of days in date, starting from 0-th day, 0-th month, 0-th year</returns>
int Date::getDaysFromDate(int year, int month, int day)
{
	int days = 0;
	int leapDays = year / 4;

	days = year * daysPearYear + leapDays + total_days_in_month[month] + day;

	if (year % 4 == 3 && month > 1)
		days++; // add leap day in the current year
	return days;
}
/// <summary>
/// creates date from days, starting from 0-th day, 0-th month, 0-th year
/// </summary>
/// <param name="_days"></param>
/// <returns>returns Date from days</returns>
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
/// <summary>
/// adds days to date
/// </summary>
/// <param name="days">days to add</param>
void Date::addDays(int days)
{
	if (days == 0)
		return;
	int this_days = Date::getDaysFromDate(this->_year, this->_month, this->_day);
	if (this_days + days < 0)
		throw std::out_of_range("");

	Date temp = Date::setDateFromDays(this_days + days);
	this->_year = temp._year;
	this->_month = temp._month;
	this->_day = temp._day;
}
/// <summary>
/// gets day
/// </summary>
/// <returns>returns day</returns>
int Date::getDay()
{
	return _day;
}
/// <summary>
/// gets month
/// </summary>
/// <returns>returns month</returns>
int Date::getMonth()
{
	return _month;
}
/// <summary>
/// gets year
/// </summary>
/// <returns>returns year</returns>
int Date::getYear()
{
	return _year;
}
/// <summary>
/// sets day
/// </summary>
/// <param name="day">day</param>
void Date::setDay(int day)
{
	if (day < 0 || day >= Date::getDaysInMonth(_month, _year))
		throw std::invalid_argument("Day is out of range");
	_day = day;
}
/// <summary>
/// sets month
/// </summary>
/// <param name="month">month</param>
void Date::setMonth(int month)
{
	if (month < 0 || month > 11)
		throw std::invalid_argument("Month is out of range");
	_month = month;
}
/// <summary>
/// sets year
/// </summary>
/// <param name="year">year</param>
void Date::setYear(int year)
{
	if (year < 0 || year > 2999)
		throw std::invalid_argument("Year is out of range");
	_year = year;
}
/// <summary>
/// returns string representation of date
/// </summary>
/// <returns>returns string representation in format "X years, X months, X days"</returns>
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
/// <summary>
/// fills date randomly
/// </summary>
/// <param name="minYear">minimun year</param>
/// <param name="maxYear">maximum year</param>
void Date::randomFill(int minYear = 0, int maxYear = 10)
{
	_year = Utils::randInt(minYear, maxYear);
	_month = Utils::randInt(0, 11);
	_day = Utils::randInt(0, getDaysInMonth(_month, _year) - 1);
}
/// <summary>
/// checks whether the date is valid
/// </summary>
/// <param name="year">year</param>
/// <param name="month">month</param>
/// <param name="day">day</param>
/// <returns>returns true if date is valid, false otherwise</returns>
bool Date::isCorrect(int year, int month, int day)
{
	if (year < 0 || year > 9999)
		return false;
	if (month < 0 || month > 11)
		return false;
	if (day < 0 || day >= getDaysInMonth(month, year))
		return false;
	return true;
}
/// <summary>
/// parameterized constructor
/// </summary>
/// <param name="year">year to set</param>
/// <param name="month">month to set</param>
/// <param name="day">day to set</param>
Date::Date(int year, int month, int day)
{
	if (!isCorrect(year, month, day))
	{
		throw std::invalid_argument("Invalid argument for Date");
	}

	_day = day;
	_month = month;
	_year = year;
}
/// <summary>
/// output operator
/// </summary>
/// <param name="os"></param>
/// <param name="date"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const Date& date)
{
	using namespace std;
	os << date.toString();
	return os;
}
/// <summary>
/// compares dates by year, month and day
/// </summary>
/// <param name="date1">first date to compare</param>
/// <param name="date2">second date to compare</param>
/// <returns>returns true if dates are equal, false otherwise</returns>
bool operator==(const Date& date1, const Date& date2)
{
	return (date1._year == date2._year &&
		date1._month == date2._month &&
		date1._day == date2._day);
}