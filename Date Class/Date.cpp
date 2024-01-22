#include "Date.h"

Date::Date() {
	time_t* ptrTime_t = new time_t;
	*ptrTime_t = time(0);
	tm* ptrTm = new tm;
	localtime_s(ptrTm, ptrTime_t);
	_day = ptrTm->tm_mday;
	_month = ptrTm->tm_mon + 1;
	_year = ptrTm->tm_year + 1900;
	delete ptrTime_t;
	delete ptrTm;
}

Date::Date(int day, int month, int year) {
	_day = day;
	_month = month;
	_year = year;
}

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}

std::string Date::getDate() {
	std::string day, month, year;

	if (_day / 10 == 0) day = '0' + std::to_string(_day) + '.';
	else day = std::to_string(_day) + '.';

	if (_month / 10 == 0) month = '0' + std::to_string(_month) + '.';
	else month = std::to_string(_month) + '.';

	return day + month + std::to_string(_year);
}

bool Date::isLeapYear() {
	if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0) return true;
	else return false;
}

bool Date::isCorrectDate() {
	std::set <int> month31 = { 1, 3, 5, 7, 8, 10, 12 };
	std::set <int> month30 = { 4, 6, 9, 11 };

	if (month31.count(_month) && _day >= 1 && _day <= 31) return true;
	else if (month30.count(_month) && _day >= 1 && _day <= 30) return true;
	else if (_month == 2 && this->isLeapYear() && _day >= 1 && _day <= 29) return true;
	else if (_month == 2 && !this->isLeapYear() && _day >= 1 && _day <= 28) return true;
	else return false;
}

bool operator == (Date& date1, Date& date2) {
	return date1._day == date2._day &&
		date1._month == date2._month &&
		date1._year == date2._year;
}

bool operator != (Date& date1, Date& date2) {
	return !(date1 == date2);
}

bool operator > (Date& date1, Date& date2) {
	if (date1._year > date2._year) return true;
	else if (date1._month > date2._month) return true;
	else if (date1._day > date2._day) return true;
	else return false;
}

bool operator < (Date& date1, Date& date2) {
	if (date1._year < date2._year) return true;
	else if (date1._month < date2._month) return true;
	else if (date1._day < date2._day) return true;
	else return false;
}

bool operator >= (Date& date1, Date& date2) {
	if (date1._year >= date2._year) return true;
	else if (date1._month >= date2._month) return true;
	else if (date1._day >= date2._day) return true;
	else return false;
}

bool operator <= (Date& date1, Date& date2) {
	if (date1._year <= date2._year) return true;
	else if (date1._month <= date2._month) return true;
	else if (date1._day <= date2._day) return true;
	else return false;
}