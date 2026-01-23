#include <stdio.h>
#include <unistd.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/148/A
        I am happy to code :)
*/

int main(void) {
	int k, l, m, n, d; // multiple variable declaration

	/*int l;
	int m;
	int n;
	int d;*/

	scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);

	//Test multiple scanf
	//printf("%d %d %d %d %d\n", k, l, m , n, d);

	if (k < 1 || k > 10 || l < 1 || l > 10 || m < 1 || m > 10 || n < 1 || n > 10 || d < 1 || d > 100000)
		return (0);

	int starter = 1;
	int harmed = 0;

	while (starter <= d) {
		if (starter % k == 0 || starter % l == 0 || starter % m == 0 || starter % n == 0)
			++harmed;
		++starter;
	}
	printf("%d\n", harmed);
	return (0);
}
