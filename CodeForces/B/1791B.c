#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 10000

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1791/B
        I am happy to code :)
*/

typedef struct s_candy {
	int candy_x;
	int candy_y;
	int x;
	int y;
} t_candy;

static t_candy *createNewMap(void) {
	t_candy *new_map;

	new_map = calloc(1, sizeof(t_candy));
	if (!new_map)
		return (NULL);
	new_map->candy_x = 1;
	new_map->candy_y = 1;
	new_map->x = 0;
	new_map->y = 0;
	return (new_map);
}

static void cleanMap(t_candy **map) {
	if (!map || !(*map))
		return ;
	(*map)->x = 0;
	(*map)->y = 0;
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 1000)
		return (0);

	int *lengths = (int *)calloc(input, sizeof(int));
	if (!lengths)
		return (0);
	char **arr = (char **)calloc(input, sizeof(char *));
	if (!arr) {
		free(lengths);
		return (0);
	}
	for (int i = 0; i < input; ++i) {
		scanf("%d", lengths + i);
		arr[i] = (char *)calloc(lengths[i] + 1, sizeof(char));
		if (!arr[i]) {
			while (i--)
				free(arr[i]);
			free(arr);
			free(lengths);
			return (0);
		}
		scanf("%s", arr[i]);
	}

	t_candy *map = createNewMap();

	if (!map) {
		free(lengths);
		for (int i = 0; i < input; ++i)
			free(arr[i]);
		free(arr);
		return (0);
	}

	int index = 0;
	int counter = 0;
	char result[MAX_LEN];
	int check = sizeof(result);

	while ((check + 1) >= 0)
		result[check--] = '\0';

	for (int i = 0; i < input; ++i) {
		index = 0;
		cleanMap(&map);
		while (arr[i][index]) {
			if (arr[i][index] == 'U')
				map->y += 1;
			else if (arr[i][index] == 'D')
				map->y -= 1;
			else if (arr[i][index] == 'R')
				map->x += 1;
			else if (arr[i][index] == 'L')
				map->x -= 1;
			if (map->x == 1 && map->y == 1) {
				result[counter++] = 'Y';
				break ;
			}
			++index;
		}
		if (arr[i][index] == '\0')
			result[counter++] = 'N';
	}
	result[counter] == '\0';

	for (int i = 0; i < counter; ++i) {
		if (result[i] == 'Y')
			write(1, "YES\n", 4);
		else if (result[i] == 'N')
			write(1, "NO\n", 3);
	}

	for (int i = 0; i < input; ++i)
		free(arr[i]);

	free(map);
	free(lengths);
	free(arr);
	return (0);
}
