#pragma once

#include <string>
#include <set>
#include <ctime>

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
	std::string getDate();
	bool isLeapYear();
	bool isCorrectDate();
	friend bool operator == (Date& date1, Date& date2);
	friend bool operator != (Date& date1, Date& date2);
	friend bool operator > (Date& date1, Date& date2);
	friend bool operator < (Date& date1, Date& date2);
	friend bool operator >= (Date& date1, Date& date2);
	friend bool operator <= (Date& date1, Date& date2);
};