#include "Time.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Utils.h"
using namespace std;
/// <summary>
/// gets the second
/// </summary>
/// <returns>returns the second</returns>
int Time::getSecond()
{
	return _sec;
}
/// <summary>
/// gets the minute
/// </summary>
/// <returns>returns the minute</returns>
int Time::getMinute()
{
	return _min;
}
/// <summary>
/// gets the hour
/// </summary>
/// <returns>returns the hour</returns>
int Time::getHour()
{
	return _hour;
}
/// <summary>
/// sets the second
/// </summary>
/// <param name="second">second to set</param>
void Time::setSecond(int second)
{
	if (second >= 0 && second <= 59)
		_sec = second;
	else
		_sec = 0;
}
/// <summary>
/// sets the minute
/// </summary>
/// <param name="minute">minute to set</param>
void Time::setMinute(int minute)
{
	if (minute >= 0 && minute <= 59)
		_min = minute;
	else
		_min = 0;
}
/// <summary>
/// sets the hour
/// </summary>
/// <param name="hour">hour to set</param>
void Time::setHour(int hour)
{
	if (hour >= 0 && hour <= 23)
		_hour = hour;
	else
		_hour = 0;
}
/// <summary>
/// gets total amount of seconds
/// </summary>
/// <param name="time">time to get total amount of seconds</param>
/// <returns>return total amount of seconds of Time object</returns>
int Time::getSeconds(Time& time)
{
	return getSeconds(time.getHour(), time.getMinute(), time.getSecond());
}
/// <summary>
/// gets total amount of seconds
/// </summary>
/// <param name="hour">hour</param>
/// <param name="minute">minute</param>
/// <param name="second">second</param>
/// <returns>return total amount of seconds</returns>
int Time::getSeconds(int hour, int minute, int second)
{
	return second + minute * secPerMinute + hour * secPerHour;
}
/// <summary>
/// empty constructor
/// </summary>
Time::Time() : _sec(0), _min(0), _hour(0)
{

}
/// <summary>
/// destructor
/// </summary>
Time::~Time()
{
}
/// <summary>
/// construstor with parameters
/// </summary>
/// <param name="hour">hour to set</param>
/// <param name="minute">minute to set</param>
/// <param name="second">second to set</param>
Time::Time(int hour, int minute, int second)
{
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}
/// <summary>
/// adds time represented in hours, minutes, seconds
/// </summary>
/// <param name="hour">hours to add</param>
/// <param name="minute">minutes to add</param>
/// <param name="second">seconds to add</param>
void Time::addTime(int hour, int minute, int second)
{
	int that_time = Time::getSeconds(hour, minute, second);
	addSeconds(that_time);
}
/// <summary>
/// adds time represented in time object
/// </summary>
/// <param name="time">time to add</param>
void Time::addTime(Time& time)
{
	addTime(time.getHour(), time.getMinute(), time.getSecond());
}
/// <summary>
/// adds seconds
/// </summary>
/// <param name="seconds">seconds to add</param>
void Time::addSeconds(int seconds)
{
	int this_seconds = Time::getSeconds(_hour, _min, _sec);
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
/// <summary>
/// gets string represntation
/// </summary>
/// <returns>returns string representation of time</returns>
std::string Time::toString() const
{
	std::string s;
	if (_hour < 10)
		s.append("0");
	
	s.append(std::to_string(_hour));
	s.append(":");
	if (_min < 10)
		s.append("0");
	
	s.append(std::to_string(_min));
	s.append(":");
	if (_sec < 10)
		s.append("0");
	s.append(std::to_string(_sec));
	return s;
}
/// <summary>
/// fills time randomly
/// </summary>
void Time::randomFill()
{
	_hour = Utils::randInt(0, 23);
	_min = Utils::randInt(0, 59);
	_sec = Utils::randInt(0, 59);
}
/// <summary>
/// checks whether the time is valid
/// </summary>
/// <param name="hour">hour</param>
/// <param name="minute">minute</param>
/// <param name="second">second</param>
/// <returns>returns bool that indicates correctness</returns>
bool Time::isCorrect(int hour, int minute, int second)
{
	if (hour < 0 || hour > 23)
		return false;
	if (minute < 0 || minute > 59)
		return false;
	if (second < 0 || second > 59)
		return false;
	return true;
}
/// <summary>
/// output operator
/// </summary>
/// <param name="os"></param>
/// <param name="time"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const Time& time)
{
	using namespace std;
	os << time.toString();
	//os << setfill('0') << setw(2) << time._hour << ":" << setfill('0') << setw(2) << time._min << ":" << setfill('0') << setw(2) << time._sec;
	return os;
}
/// <summary>
/// compares times by hour, minute and second
/// </summary>
/// <param name="time1">left time to check</param>
/// <param name="time2">right time to check</param>
/// <returns>returns true if times are equal, false if otherwise</returns>
bool operator==(const Time& time1, const Time& time2)
{
	return (time1._hour == time2._hour &&
		time1._min == time2._min &&
		time1._sec == time2._sec);
}
