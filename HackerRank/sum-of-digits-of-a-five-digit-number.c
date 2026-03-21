#include <stdio.h>
#include <unistd.h>

/*
	HACKERRANK CHALLENGES JOURNEY!!!

	Author: Fernando Ruan
	Country: Brazil
	Challenge: https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/problem?isFullScreen=true
	I am happy to code :)
*/

static void sumAllDigits(unsigned int n, unsigned int index) {
	static int result = 0;
	
	if (n >= 10)
		sumAllDigits(n / 10, ++index);
	result += n % 10;
	if (index == 1) // the first input index will be the final. The first will be the last, as in the Bible
		printf("%d\n", result);
}

int main(void) {
	unsigned int n;

	scanf("%u", &n);
	sumAllDigits(n, 0);
	return (0);
}
