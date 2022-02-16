#include "DateTime.h"
#include "Utils.h"
DateTime::DateTime() : Date(1999,0,0), Time(0,0,0)
{
}

DateTime::DateTime(int year, int month, int day) : Date(year-1, month-1, day-1)
{
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second) : Date(year-1, month-1, day-1), Time(hour, minute, second)
{
}

int DateTime::getMonth()
{
	return _month + 1;
}

int DateTime::getYear()
{
	return _year + 1;
}

int DateTime::getDay()
{
	return _day + 1;
}

void DateTime::setYear(int year)
{
	Date::setYear(year - 1);
}

void DateTime::setMonth(int month)
{
	Date::setMonth(month - 1);
}

void DateTime::setDay(int day)
{
	Date::setDay(day - 1);
}

void DateTime::addTime(Time& time)
{
	addTime(time.getHour(), time.getMinute(), time.getSecond());
}

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

void DateTime::subtractTime(Time& time)
{
	addTime(-time.getHour(), -time.getMinute(), -time.getSecond());
}

void DateTime::addDays(int day)
{
	Date::addDays(day);
}

void DateTime::addDate(Date& date)
{
	addDays(Date::getDaysFromDate(date));
}

void DateTime::subtractDate(Date& date)
{
	addDays(-Date::getDaysFromDate(date));
}

void DateTime::addSeconds(int seconds)
{
	int days_to_add = seconds / secPerDay;
	addDays(days_to_add);
	Time::addSeconds(seconds);
}

void DateTime::randomFill()
{
	Date::randomFill(2016, 2022);
	Time::randomFill();
}

Date DateTime::dateBetween(DateTime& dt1, DateTime& dt2)
{
	int days1 = Date::getDaysFromDate(dt1);
	int days2 = Date::getDaysFromDate(dt2);
	int diff = abs(days1 - days2);
	return Date::setDateFromDays(diff);
}

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

std::string DateTime::toStringTime() const
{
	return Time::toString();
}

std::ostream& operator<<(std::ostream& os, const DateTime& dateTime)
{
	os << dateTime.toString();
	return os;
}

bool operator==(const DateTime& dt1, const DateTime& dt2)
{
	return (dt1._year == dt2._year && dt1._month == dt2._month && dt1._day == dt2._day &&
		dt1._hour == dt2._hour && dt1._min == dt2._min && dt1._sec == dt2._sec);
}
