#include <stdio.h>
#include <unistd.h>
#include <math.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/486/A
        I am happy to code :)
*/

static unsigned long long getNumber(long long power) {
	unsigned long long result = 0;

	while (power) {
		if ((power & 1) == 0) 
			result += power;
		
		else  
			result -= power;
		--power;
	}

	return (result);
}

int main (void) {
	unsigned long long input;

	scanf("%lld", &input);

	if (!input)
		return (0);

	printf("%lld\n", getNumber(input));
	return (0);
}
