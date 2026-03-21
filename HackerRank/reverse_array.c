#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
	HACKERRANK CHALLENGES JOURNEY!!!

	Author: Fernando Ruan
	Country: Brazil
	Challenge: https://www.hackerrank.com/challenges/reverse-array-c/problem?isFullScreen=true 
	I am happy to code :)
*/

int main(void) {
	int index;

	scanf("%d", &index);

	if (!index)
		return (0);

	int *arr = (int *)calloc(index, sizeof(int));

	if (!arr)
		return (0);

	for (int i = 0; i < index; i++)
		scanf("%d", arr + i);

	/* DEBUG

	for (int i = 0; i < index; i++)
		printf("%d\n", arr[i]);

	write(1, "\n", 1);

	*/


	/*
		Functionality

		We need to have a integer variable tmp to store the value that we are changing, avoiding to lost it.
		arr[i] -> it is the first number like in 1,2,3,4,5,6
		arr[i] starts with 1 and we need to change 1 to 6. How can I do it?
		The position of 6 is index (length of the integer array input) - 1. Why do we need to subtract 1?
		It is because the correction to a valid index. Ok, but what about the loop?
		We can always know the next value using that approach index - i - 1 and to complete everything
		the maximum index must need to be half of the original one because when we reach the centre
		everything is already organized
	*/

	int tmp = 0;

	for (int i = 0; i < index / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[index - i - 1];
		arr[index - i - 1] = tmp;
	}

	for (int i = 0; i < index; i++) {
		if (i + 1 == index)
			printf("%d\n", arr[i]);
		else
			printf("%d ", arr[i]);
	}

	free(arr);
	return (0);
}
