#include <iostream>

#include "Date.h"

int main() {
	Date date = Date(15, 12, 2018);
	std::cout << date.getDate();
	return 0;
}