#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1703/B
        I am happy to code :)
*/

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 100)
		return (0);

	char **array = (char **)calloc(input, sizeof(char *));
	if (!array)
		return (0);
	int *lengths = (int *)calloc(input, sizeof(int));
	if (!lengths) {
		free(array);
		return (0);
	}
	bool flag = false;
	char alphabelt[MAX_LEN];

	for (int i = 0; i < input; ++i) {
		scanf("%d", lengths + i);
		if (lengths[i] < 0 || lengths[1] > 100) {
			free(lengths);
			flag = true;
			array[i] = NULL;
		}
		if (!flag) 
			array[i] = (char *)calloc(lengths[i] + 1, sizeof(char));
		if (!array[i]) {
			while (--i) {
				free(array[i]);
				array[i] = NULL;
			}
			free(array);
			free(lengths);
			array = NULL;
			lengths = NULL;
			return (0);
		}
		scanf("%s", array[i]);
	}

	int result = 0;
	char alphabet[MAX_LEN];
	int check;
	int index = 0;
	int counter = 0;
	int second = 0;

	result = 0;
	counter = 0;
	check = sizeof(alphabet);
	++check;
	while (check >= 0)
		alphabet[check--] = '\0';
	/*
		for each string, I compare each character to the character in alphabet
		if that letter is new, result increases two units
		else if that letter is not new, result increases only one unit
	*/

	int i = 0;
	while (i < input) {
		result = 0; // we need to restore the value
		index = 0; // here the index is zero to indicate the start of another string
		while (array[i][index]) { // here we need to check each character with the alphabelt
			second = 0;
			while (alphabet[second]) {
				if (array[i][index] == alphabet[second]) {
					++result; // add just one value because the value existed
					break ;
				}
				++second; // continues until check everything
			}
			if (alphabet[second] != array[i][index]) { // if we checked everything and does not match
				//printf("new character: %c\n", array[i][index]);
				alphabet[counter++] = array[i][index];
				result += 2; // add 2 for new and add the target value
			}
			++index;
		}
		putNumber(result);
		write(1, "\n", 1);
		check = sizeof(alphabet);
		++check;
		while (check >= 0)
			alphabet[check--] = '\0';
		//printf("alphabet: %s\n", alphabet);
		counter = 0;
		++i;
	}
	
	for (int i = 0; i < input; ++i) {
		free(array[i]);
		array[i] = NULL;
	}

	free(lengths);
	free(array);
	lengths = NULL;
	array = NULL;
	return (0);
}
