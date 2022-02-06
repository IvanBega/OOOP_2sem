#include "Time.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int Time::getSecond()
{
	return _sec;
}

int Time::getMinute()
{
	return _min;
}

int Time::getHour()
{
	return _hour;
}

void Time::setSecond(int second)
{
	if (second >= 0 && second <= 59)
		_sec = second;
	else
		_sec = 0;
}

void Time::setMinute(int minute)
{
	if (minute >= 0 && minute <= 59)
		_min = minute;
	else
		_min = 0;
}

void Time::setHour(int hour)
{
	if (hour >= 0 && hour <= 23)
		_hour = hour;
	else
		_hour = 0;
}

Time::Time() : _sec(0), _min(0), _hour(0)
{

}

Time::~Time()
{
}

Time::Time(int hour, int minute, int second)
{
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

void Time::addTime(int hour, int minute, int second)
{
	int that_time = hour * secPerHour + minute * secPerMinute + second;
	addSeconds(that_time);
}

void Time::addTime(Time& time)
{
	addTime(time.getHour(), time.getMinute(), time.getSecond());
}

void Time::addSeconds(int seconds)
{
	int this_seconds = _hour * secPerHour + _min * secPerMinute + _sec;
	int result = (this_seconds + seconds) % secPerDay;
	if (result < 0)
	{
		result = secPerDay + result;
	}
	_hour = result / secPerHour;
	result = result - secPerHour * _hour;
	_min = result / secPerMinute;
	result = result - secPerMinute * _min;
	_sec = result;
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
	using namespace std;
	os << setfill('0') << setw(2) << time._hour << ":" << setfill('0') << setw(2) << time._min << ":" << setfill('0') << setw(2) << time._sec;
	return os;
}

bool operator==(const Time& time1, const Time& time2)
{
	return (time1._hour == time2._hour &&
		time1._min == time2._min &&
		time1._sec == time2._sec);
}
