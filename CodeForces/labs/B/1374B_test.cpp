#include <iostream>
#include <vector>
#include <climits>

static bool is_primer(unsigned long long number) {
	int starter = 2;
	if (number < 2)
		return (false);
	while (starter * starter <= number) {
		if (number % starter == 0)
			return (false);
		++starter;
	}
	return (true);
}

static int getResult(unsigned long long number) {
	unsigned long long steps = 0;

	if (number % 2 != 0 && number % 3 != 0)
		return (-1);
	else if (is_primer(number))
		return (0);

	while (number != 1) {
		if (steps > INT_MAX)
			break ;
		if (number % 6 == 0) {
			number /= 6;
			++steps;
		}
		else if (number % 2 == 0) {
			number *= 2;
			++steps;
		}
		else
			return (-1);
		if (number == 1)
			return (steps);
		std::cout << number << std::endl;
	}
	return (steps);
}

int main(void) {
	std::vector<int> results;
	std::vector<unsigned long long> numbers;
	int input;
	int tmp;

	std::cin >> input;

	if (!input || input < 1 || input > 1000)
		return (0);

	for (int i = 0; i < input; ++i) {
		std::cin >> tmp;
		if (!tmp || tmp < 1 || tmp > 1000000000)
			return (0);
		numbers.push_back(tmp);
	}

	std::vector<unsigned long long>::iterator it;
	int target;
	int result;

	for (it = numbers.begin(); it != numbers.end(); ++it) {
		target = *it;
		result = getResult(*it);
		results.push_back(result);
	}

	std::vector<int>::iterator itr;

	for (itr = results.begin(); itr != results.end(); ++itr)
		std::cout << *itr << std::endl;

	return (0);
}
