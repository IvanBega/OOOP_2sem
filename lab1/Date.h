#pragma once
#include <iostream>
/// <summary>
/// Class for representing date - years, months, days.
/// Months are starting from zero. Julian calendar is used.
/// Leap days are supported, with each leap February
/// contains 29 days.
/// Accepted years are between 1 and 9999 in order
/// to prevent overflow.
/// </summary>
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
	void setYear(int year);
	std::string toString() const;
	void randomFill(int minYear, int maxYear);
	static bool isCorrect(int year, int month, int day);
protected:
	const static int days_in_month[12];
	const static int total_days_in_month[12];
	/// <summary>
	/// amount of days in a year
	/// </summary>
	static const int daysPerYear = 365;
	static int getDaysInMonth(int month,int year);
	/// <summary>
	/// day
	/// </summary>
	int _day;
	/// <summary>
	/// month
	/// </summary>
	int _month;
	/// <summary>
	/// year
	/// </summary>
	int _year;
};