#include <iostream>
#include <map>
#include <climits>

int main(void) {
	
	std::string input;

	std::map<std::string, long long> myMap = {
		{"int_max", INT_MAX},
		{"int_min", INT_MIN},
		{"unsigned_int", UINT_MAX},
		{"long_long_max", LLONG_MAX},
		{"long_long_min", LLONG_MIN},
		{"char_bit", CHAR_BIT},
		{"char_max", CHAR_MAX},
		{"char_min", CHAR_MIN},
		{"signed_char_max", SCHAR_MAX},
		{"signed_char_min", SCHAR_MIN},
		{"unsigned_char_max", UCHAR_MAX},
		{"short_min", SHRT_MIN},
		{"short_max", SHRT_MAX},
		{"unsigned_short", USHRT_MAX}
	};

	std::cout << "Type the type of data you want to know the maximum or minimum size: " << std::endl;
	std::cin >> input;

	std::map<std::string, long long>::iterator it;

	for (it = myMap.begin(); it != myMap.end(); ++it) {
		if (it->first == input) {
			std::cout << "The size is: " << it->second << std::endl;
			return (0);
		}
	}
	if (input == "unsigned_long_long") {
		std::cout << "The size is: " << ULLONG_MAX << std::endl;
		return (0);
	}
	std::cout << "Unfortunately, the input " << input << " does not exist" << std::endl;
	return (0);
}
