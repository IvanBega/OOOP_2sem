#pragma once
#include <iostream>
#include <string>
/// <summary>
/// Class for representing time in hours, minutes, seconds
/// </summary>
class Time
{
public:
	int getSecond();
	int getMinute();
	int getHour();
	void setSecond(int second);
	void setMinute(int minute);
	void setHour(int hour);
	static int getSeconds(Time& time);
	static int getSeconds(int hour, int minute, int second);
	Time();
	~Time();
	Time(int hour, int minute, int second);
	void addTime(int hour, int minute, int second);
	void addTime(Time& time);
	void addSeconds(int seconds);
	friend std::ostream& operator<<(std::ostream& os, const Time& time);
	friend bool operator==(const Time& time1, const Time& time2);
	std::string toString() const;
	void randomFill();
	static bool isCorrect(int hour, int minute, int second);
protected:
	/// <summary>
	/// second
	/// </summary>
	int _sec;
	/// <summary>
	/// minute
	/// </summary>
	int _min;
	/// <summary>
	/// hour
	/// </summary>
	int _hour;
	/// <summary>
	/// seconds per minute
	/// </summary>
	static const int secPerMinute = 60;
	/// <summary>
	/// seconds per hour
	/// </summary>
	static const int secPerHour = 60 * secPerMinute;
	/// <summary>
	/// seconds per day
	/// </summary>
	static const int secPerDay = 24 * secPerHour;
};
