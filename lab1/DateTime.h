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
	void subtractTime(Time& time);
	void addDays(int day);
	void addDate(Date& date);
	void subtractDate(Date& date);
	void addSeconds(int seconds);
	void randomFill();
	static Date dateBetween(DateTime& dt1, DateTime& dt2);
	static bool isDateCorrect(int year, int month, int day);
	static bool isTimeCorrect(int hour, int minute, int second);
	static bool isDateTimeCorrect(int year, int month, int day, int hour, int minute, int second);
	std::string toString() const;
	std::string toStringTime() const;
	friend std::ostream& operator<<(std::ostream& os, const DateTime& date);
	friend bool operator==(const DateTime& dt1, const DateTime& dt2);
};