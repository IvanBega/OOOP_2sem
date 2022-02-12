#pragma once
#include <iostream>
#include "Date.h"
#include "Time.h"
class DateTime : public Date, public Time
{
public:
	DateTime()
	{

	}
	~DateTime()
	{

	}
	DateTime(int year, int month, int day);
	DateTime(int year, int month, int day, int hour, int minute, int second);
	int getMonth();
	int getYear();
	int getDay();
	void addTime(Time& time);
	void addTime(int hour, int minute, int second);
	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& os, const DateTime& date);
};