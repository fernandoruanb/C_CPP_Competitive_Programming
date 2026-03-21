#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/705/A
        I am happy to code :)
*/

int main(void) {
	int input;

	scanf("%d", &input);

	if (input < 1 || input > 100)
		return (0);
	int timer = 1;
	char *hateFinal = "I hate it\n";
	char *loveFinal = "I love it\n";
	char *hateMiddle = "I hate that ";
	char *loveMiddle = "I love that ";

	bool hateFlag = true;
	bool loveFlag = false;
	while (input--) {
		if (input == 0 && hateFlag)
			printf("%s", hateFinal);
		else if (input == 0 && loveFlag)
			printf("%s", loveFinal);
		if (input != 0 && hateFlag) {
			printf("%s", hateMiddle);
			hateFlag = false;
			loveFlag = true;
		} else if (input != 0 && loveFlag) {
			printf("%s", loveMiddle);
			hateFlag = true;
			loveFlag = false;
		}
	}
	return (0);
}
