#include <stdio.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/630/A
        I am happy to code :)
*/

unsigned long long nowPowerFive(unsigned long long power) {
	unsigned long long result = 5;
	/*while (--power)
		result *= 5;*/
	result = 25; // Yes, that is the answer, the answer will be 25 :D every time
	return (result);
}

int main(void) {
	unsigned long long power;

	scanf("%llu", &power);

	if (!power || power < 2)
		return (0);
	unsigned long long result = nowPowerFive(power);
	printf("%llu\n", result);
	return (0);
}
