#pragma once
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
private:
	int _sec;
	int _min;
	int _hour;
	static const int secPerHour = 3600;
	static const int secPerDay = 24 * secPerHour;
};
