#pragma once
#include <iostream>

class Date
{
public:
	~Date();
	Date();
	Date(int year, int month, int day);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend bool operator==(const Date& date1, const Date& date2);
	static int getDaysFromDate(const Date& date);
	static int getDaysFromDate(int year, int month, int day);
	static Date setDateFromDays(int _days);
	void addDays(int days);
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int day);
	void setMonth(int month);
	int setYear(int year);
private:
	const static int days_in_month[12];
	const static int total_days_in_month[12];
	static const int daysPearYear = 365;
	static int getDaysInMonth(int month,int year);
	int _day;
	int _month;
	int _year;
};