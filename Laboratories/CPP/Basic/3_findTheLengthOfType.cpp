#include <iostream>
#include <map>
#include <algorithm>

int main(void) {

	std::string input; // correct way to represent null or putting "" in C++

	// use {} instead of []

	std::map<std::string, size_t> myMap = {
		{"int", sizeof(int)},
		{"char", sizeof(char)},
		{"long", sizeof(long)},
		{"long long", sizeof(long long)},
		{"double", sizeof(double)},
		{"float", sizeof(float)},
		{"long double", sizeof(long double)}
	};

	std::cout << "Type one type of data you want to discover the size: ";
	std::cin >> input;

	// creating an iterator to check if the type is a valid one or not

	std::map<std::string, size_t>::iterator it;

	for (it = myMap.begin(); it != myMap.end(); ++it) {
		if (it->first == input)
			break ;
	}
	if (it == myMap.end()) {
		std::cout << "Unfortunately " << input << " is not a valid type of data" << std::endl;
		return (0);
	}
	std::cout << "Size of " << input << ": " << myMap[input] << std::endl;
	return (0);
}
