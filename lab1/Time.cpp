#include "Time.h"

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
}

void Time::setMinute(int minute)
{
	if (minute >= 0 && minute <= 59)
		_min = minute;
}

void Time::setHour(int hour)
{
	if (hour >= 0 && hour <= 23)
		_hour = hour;
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
	int this_time = _hour * 3600 + _min * 60 + _sec;
	int that_time = hour * 3600 + minute * 60 + second;
	int result = (this_time + that_time) % secPerDay;

	_hour = result / 24;
	result = result - 3600 * _hour;
	_min = result / 60;
	result = result - 60 * _min;
	_sec = result;
}

void Time::addTime(Time& time)
{
	addTime(time.getHour(), time.getMinute(), time.getSecond());
}
