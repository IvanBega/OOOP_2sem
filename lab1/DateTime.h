#pragma once

#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
class Date
{
public:
	Date(unsigned short _year, unsigned short _month, unsigned short _day,
		unsigned short _hour, unsigned short _minute, unsigned short _second) :
		year(_year), month(_month), day(_day), hour(_hour), minute(_minute), second(_second)
	{

	}
	Date()
	{
	}
	void print();
	void print2();
	void print3();
	bool isCorrect();
	int getDayByDate();
	static int dateDiff(Date date1, Date date2);
	void addDate(Date date);
	void addDate(short Year, short Month, short Day);
	void addDate(short Year, short Month, short Day, short Hour, short Minute, short Second);
	void subtractDate(short Year, short Month, short Day);
	void subtractDate(short Year, short Month, short Day, short Hour, short Minute, short Second);
	void subtractDate(Date date);
	static int toDays(short Year, short Month, short Day);
	bool operator >(const Date& date) const;
	void fillWithRandom();
	void fillFromConsole();
	void subtractYear(short Year);
private:
	static constexpr const char* days_of_week[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	static constexpr const short days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static const int sec_in_day = 86400;
	short year = 0;
	short day = 1;
	short month = 1;
	short hour = 0;
	short minute = 0;
	short second = 0;
};


