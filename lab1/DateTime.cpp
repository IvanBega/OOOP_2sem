#include "DateTime.h"

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

void DateTime::addTime(Time& time)
{
	int that_sec = secPerHour * time.getHour() + secPerMinute * time.getMinute() + time.getSecond();
}

void DateTime::addTime(int hour, int minute, int second)
{
	int that_time = secPerHour * hour + secPerMinute * minute + second;
	int this_time = secPerHour * _hour + secPerMinute * _min + _sec;
	int result = this_time + that_time;
	int days_to_add = result / secPerDay;
	if (days_to_add != 0)
		addDays(days_to_add);
	addSeconds(that_time);
}

void DateTime::addSeconds(int seconds)
{
	int days_to_add = seconds / secPerDay;
	addDays(days_to_add);
	Time::addSeconds(seconds);
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
