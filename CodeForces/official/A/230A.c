#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/230/A
        I am happy to code :)
*/

int main(void) {
	int *room = (int *)calloc(2, sizeof(int));

	for (int i = 0; i < 2; ++i)
		scanf("%d", room + i);

	if (room[0] < 1 || room[0] > 10000 || room[1] < 1 || room[1] > 1000) {
		free(room);
		return (0);
	}

	int *dragonStrength = (int *)calloc(room[1], sizeof(int));

	if (!dragonStrength) {
		free(room);
		return (0);
	}

	int *bonusWinBattle = (int *)calloc(room[1], sizeof(int));

	if (!bonusWinBattle) {
		free(room);
		free(dragonStrength);
		return (0);
	}

	int kiritoStrength = room[0];
	int dragons = 0;
	int bonus = 0;

	for (int i = 0; i < room[1]; ++i) {
		scanf("%d", dragonStrength + dragons);
		++dragons;
		scanf("%d", bonusWinBattle + bonus);
		++bonus;
	}
	int counter = 0;
	bool flag = false;
	for (int i = 0; i < room[1]; ++i) {
		counter = 0;
		while (counter < room[1]) {
			if (kiritoStrength > dragonStrength[counter] && dragonStrength[counter] != -1)
				break ;
			++counter;
		}
		if (counter != room[1]) {
			dragonStrength[counter] = -1;
			kiritoStrength += bonusWinBattle[counter];
			flag = true;
		} else 
			flag = false;
	}
	free(bonusWinBattle);
	free(dragonStrength);
	free(room);
	if (flag)
		write(1, "YES\n", 4);
	else
		write(1, "NO\n", 3);
	return (0);
}
