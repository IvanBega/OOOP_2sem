#pragma once
#include <iostream>

class Date
{
public:
	~Date();
	Date();
	Date(int day, int month, int year);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend bool operator==(const Date& date1, const Date& date2);
	int daysFromDate();
private:
	const static int days_in_month[12];
	const static int total_days_in_month[12];
	static const int daysPearYear = 365;
	int getDaysInMonth(int month);
	int _days;
	int _day;
	int _month;
	int _year;
};