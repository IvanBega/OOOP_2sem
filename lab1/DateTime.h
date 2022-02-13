#pragma once
#include <iostream>
#include "Date.h"
#include "Time.h"
class DateTime : public Date, public Time
{
public:
	DateTime();
	~DateTime()
	{

	}
	DateTime(int year, int month, int day);
	DateTime(int year, int month, int day, int hour, int minute, int second);
	int getMonth();
	int getYear();
	int getDay();
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void addTime(Time& time);
	void addTime(int hour, int minute, int second);
	void addSeconds(int seconds);
	std::string toString() const;
	std::string toStringTime() const;
	friend std::ostream& operator<<(std::ostream& os, const DateTime& date);
	friend bool operator==(const DateTime& dt1, const DateTime& dt2);
};