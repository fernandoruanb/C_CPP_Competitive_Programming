#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 22

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/785/A
        I am happy to code :)
*/

static int strCmp(char *s1, char *s2) {
	int index = 0;

	while (*(s1 + index) != '\0' && *(s2 + index) != '\0') {
		if (*s1 != *s2)
			return (*s1 - *s2);
		++index;
	}
	return (*s1 - *s2);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 200000)
		return (0);

	int *bank = (int *)calloc(input, sizeof(int));

	if (!bank)
		return (0);

	char polyhedrons[MAX_LEN];
	int counter = input;
	int index = 0;
	int check;

	while (input >= 0) {
		check = sizeof(polyhedrons);
		while (check--)
			polyhedrons[check] = '\0';

		fgets(polyhedrons, MAX_LEN, stdin);

		if (!strCmp(polyhedrons, "Tetrahedron"))
			bank[index++] = 4;
		else if (!strCmp(polyhedrons, "Cube"))
			bank[index++] = 6;
		else if (!strCmp(polyhedrons, "Octahedron"))
			bank[index++] = 8;
		else if (!strCmp(polyhedrons, "Dodecahedron"))
			bank[index++] = 12;
		else if (!strCmp(polyhedrons, "Icosahedron"))
			bank[index++] = 20;
		--input;
	}
	int result = 0;
	for (int i = 0; i < counter; ++i)
		result += bank[i];
	printf("%d\n", result);
	free(bank);
	return (0);
}
