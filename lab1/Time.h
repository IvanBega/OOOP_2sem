#pragma once
#include <iostream>
#include <string>
class Time
{
public:
	int getSecond();
	int getMinute();
	int getHour();
	void setSecond(int second);
	void setMinute(int minute);
	void setHour(int hour);
	Time();
	~Time();
	Time(int hour, int minute, int second);
	void addTime(int hour, int minute, int second);
	void addTime(Time& time);
	void addSeconds(int seconds);
	friend std::ostream& operator<<(std::ostream& os, const Time& time);
	friend bool operator==(const Time& time1, const Time& time2);
	std::string toString() const;
protected:
	int _sec;
	int _min;
	int _hour;
	static const int secPerMinute = 60;
	static const int secPerHour = 60 * secPerMinute;
	static const int secPerDay = 24 * secPerHour;
};
