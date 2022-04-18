#include "DateTime.h"
#include "Utils.h"
/// <summary>
/// empty constructor, initializes 2000:01:01 00:00:00
/// </summary>
DateTime::DateTime() : Date(1999,0,0), Time(0,0,0)
{
}
/// <summary>
/// destructor
/// </summary>
DateTime::~DateTime()
{
}
/// <summary>
/// parameterized constructor
/// </summary>
/// <param name="year">year</param>
/// <param name="month">month</param>
/// <param name="day">day</param>
DateTime::DateTime(int year, int month, int day) : Date(year-1, month-1, day-1)
{
}
/// <summary>
/// parameterized constructor
/// </summary>
/// <param name="year">year</param>
/// <param name="month">month</param>
/// <param name="day">day</param>
/// <param name="hour">hour</param>
/// <param name="minute">minute</param>
/// <param name="second">second</param>
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second) : Date(year-1, month-1, day-1), Time(hour, minute, second)
{
}
/// <summary>
/// gets month
/// </summary>
/// <returns>returns month</returns>
int DateTime::getMonth()
{
	return _month + 1;
}
/// <summary>
/// gets year
/// </summary>
/// <returns>returns year</returns>
int DateTime::getYear()
{
	return _year + 1;
}
/// <summary>
/// gets day
/// </summary>
/// <returns>returns day</returns>
int DateTime::getDay()
{
	return _day + 1;
}
/// <summary>
/// sets year
/// </summary>
/// <param name="year">year to set</param>
void DateTime::setYear(int year)
{
	Date::setYear(year - 1);
}
/// <summary>
/// sets month
/// </summary>
/// <param name="month">month to set</param>
void DateTime::setMonth(int month)
{
	Date::setMonth(month - 1);
}
/// <summary>
/// sets a day
/// </summary>
/// <param name="day">day to set</param>
void DateTime::setDay(int day)
{
	Date::setDay(day - 1);
}
/// <summary>
/// adds time represented in time object
/// </summary>
/// <param name="time">time object to add</param>
void DateTime::addTime(Time& time)
{
	addTime(time.getHour(), time.getMinute(), time.getSecond());
}
/// <summary>
/// adds time represented in hours, minutes and seconds
/// </summary>
/// <param name="hour">hour to add</param>
/// <param name="minute">minute to add</param>
/// <param name="second">second to add</param>
void DateTime::addTime(int hour, int minute, int second)
{
	int that_time = secPerHour * hour + secPerMinute * minute + second;
	int this_time = secPerHour * _hour + secPerMinute * _min + _sec;
	int result = this_time + that_time;
	int days_to_add;
	if (result < 0)
	{
		days_to_add = -1 + result / secPerDay;
	}
	else
		days_to_add = result / secPerDay;
	if (days_to_add != 0)
		addDays(days_to_add);
	addSeconds(that_time);
}
/// <summary>
/// subtracts time represented in time object
/// </summary>
/// <param name="time">time to subtract</param>
void DateTime::subtractTime(Time& time)
{
	addTime(-time.getHour(), -time.getMinute(), -time.getSecond());
}
/// <summary>
/// adds or subtracts days
/// </summary>
/// <param name="day">days to add or subtract</param>
void DateTime::addDays(int day)
{
	Date::addDays(day);
}
/// <summary>
/// adds date represented in date object
/// </summary>
/// <param name="date">date to add</param>
void DateTime::addDate(Date& date)
{
	addDays(Date::getDaysFromDate(date));
}
/// <summary>
/// adds or subtract years, months, days
/// </summary>
/// <param name="year">years</param>
/// <param name="month">months</param>
/// <param name="day">days</param>
void DateTime::addDate(int year, int month, int day)
{
	addDays(Date::getDaysFromDate(year, month, day));
}
/// <summary>
/// subtracts date represented in date object
/// </summary>
/// <param name="date">date to subtract</param>
void DateTime::subtractDate(Date& date)
{
	addDays(-Date::getDaysFromDate(date));
}
/// <summary>
/// adds or subtract  seconds. If resulted time exceeds
/// 24 hours, then corresponding amount of days are added.
/// </summary>
/// <param name="seconds">seconds to add or subtract</param>
void DateTime::addSeconds(int seconds)
{
	int days_to_add = seconds / secPerDay;
	addDays(days_to_add);
	Time::addSeconds(seconds);
}
/// <summary>
/// random filling
/// </summary>
void DateTime::randomFill()
{
	Date::randomFill(2016, 2022);
	Time::randomFill();
}
/// <summary>
/// returns date difference between two DateTime's
/// </summary>
/// <param name="dt1">first DateTime</param>
/// <param name="dt2">second DateTime</param>
/// <returns>returns Date object, which is a diffetence of two DateTime's</returns>
Date DateTime::dateBetween(DateTime& dt1, DateTime& dt2)
{
	int days1 = Date::getDaysFromDate(dt1);
	int days2 = Date::getDaysFromDate(dt2);
	int diff = abs(days1 - days2);
	return Date::setDateFromDays(diff);
}
/// <summary>
/// checks if date part of DateTime is correct
/// </summary>
/// <param name="year">year</param>
/// <param name="month">month</param>
/// <param name="day">day</param>
/// <returns>true if date if valid, false otherwise</returns>
bool DateTime::isDateCorrect(int year, int month, int day)
{
	return Date::isCorrect(year - 1, month - 1, day - 1);
}
/// <summary>
/// checks if time part of DateTime is correct
/// </summary>
/// <param name="hour">hour</param>
/// <param name="minute">minute</param>
/// <param name="second">second</param>
/// <returns>true if time is valid, false otherwise</returns>
bool DateTime::isTimeCorrect(int hour, int minute, int second)
{
	return Time::isCorrect(hour, minute, second);
}
/// <summary>
/// checks if both date and time part of DateTime are valid
/// </summary>
/// <param name="year">year</param>
/// <param name="month">month</param>
/// <param name="day">day</param>
/// <param name="hour">hour</param>
/// <param name="minute">minute</param>
/// <param name="second">second</param>
/// <returns>true if date and time part are correct, false otherwise</returns>
bool DateTime::isDateTimeCorrect(int year, int month, int day, int hour, int minute, int second)
{
	return isDateCorrect(year, month, day) && isTimeCorrect(hour, minute, second);
}
/// <summary>
/// returns string representation of DateTime
/// </summary>
/// <returns>returns string representation of DateTime in format DD.MM.YYYY HH:MM:SS</returns>
std::string DateTime::toString() const
{
	std::string s;
	if (_day < 9)
		s.append("0");
	s.append(std::to_string(_day+1));
	s.append(".");

	if (_month < 9)
		s.append("0");
	s.append(std::to_string(_month+1));
	s.append(".");
	s.append(std::to_string(_year + 1));

	s.append(" ");
	s.append(toStringTime());
	return s;
}
/// <summary>
/// returns string representation of time part
/// </summary>
/// <returns>returns string representation of time part in format HH:MM:SS</returns>
std::string DateTime::toStringTime() const
{
	return Time::toString();
}
/// <summary>
/// console output
/// </summary>
/// <param name="os"></param>
/// <param name="dateTime"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const DateTime& dateTime)
{
	os << dateTime.toString();
	return os;
}
/// <summary>
/// compares datetimes by year, month, day, hour, minute and second
/// </summary>
/// <param name="dt1">first datetime to compare</param>
/// <param name="dt2">second datetime to compare</param>
/// <returns>returns true if datetimes are equal, false otherwise</returns>
bool operator==(const DateTime& dt1, const DateTime& dt2)
{
	return (dt1._year == dt2._year && dt1._month == dt2._month && dt1._day == dt2._day &&
		dt1._hour == dt2._hour && dt1._min == dt2._min && dt1._sec == dt2._sec);
}
