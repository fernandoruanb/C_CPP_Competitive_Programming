#include <stdio.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/214/A
        I am happy to code :)
*/

int main(void) {

	int n, m;

	scanf("%d %d", &n, &m);

	int counter = 0;

	for (int a = 0; a * a <= n; ++a) {
		for (int b = 0; b * b <= m; ++b) {
			if (a * a + b == n && a + b * b == m)
				++counter;
		}
	}
	printf("%d\n", counter);
	return (0);
}
