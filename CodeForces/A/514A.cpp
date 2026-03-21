#include <iostream>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/514/A
        I am happy to code :)
*/

static void printResult(unsigned long long number, unsigned long long minNumber, int length, int flag = 0) {

	if (number >= 10)
		printResult(number / 10, minNumber, length, flag + 1);
	if (flag == length - 1 && number == 9) 
		std::cout << number;
	else if ((number % 10) > 4)
		std::cout << 9 - (number % 10);
	else
		std::cout << (number % 10);
}

int main(void) {
	unsigned long long number;

	std::cin >> number;

	if (!number || number < 1)
		return (0);

	unsigned long long tmp = number;
	unsigned long long length = 0;
	unsigned long long minNumber = 9;

	while (tmp) {
		if ((tmp % 10) < minNumber)
			minNumber = tmp % 10;
		tmp /= 10;
		++length;
	}

	printResult(number, minNumber, length);

	std::cout << std::endl;
	return (0);
}
