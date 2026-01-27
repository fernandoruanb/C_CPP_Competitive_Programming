#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_map {
	int price;
	int quality;
	struct s_map *next;
} t_map;


static t_map *createNewMap(void) {
	t_map *new_map;

	new_map = calloc(1, sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->next = NULL;
	return (new_map);
}

static void insertNewLaptop(t_map **map, t_map *laptop) {
	if (!map || !laptop)
		return ;
	if (!(*map)) {
		*map = laptop;
		return ;
	}

	t_map *tmp = *map;
	t_map *prev = NULL;

	while (tmp) {
		/*
			1 2 (I want to insert 4)
			1 2 4 (NULL) 3
			1 2 3 4 
		*/
		if (tmp->price <= laptop->price) {
			if (tmp->next != NULL) {
				while (tmp->next && tmp->next->price <= laptop->price) {
					prev = tmp;
					tmp = tmp->next;
				}
				if (prev != NULL) {
					/*
						1 2 4
						1 2 3 4 (2 -> prev)
						laptop->next = prev->next (4)
						prev->next = laptop (3)
					*/
					laptop->next = prev->next;
					prev->next = laptop;
					break ;
				} else if (prev == NULL) {
					/*
						1 2 4 (insert 0)
						0 1 2 4
						laptop->next = tmp;
						tmp = laptop; now laptop is the head of map
					*/
					laptop->next = tmp;
					tmp->next = laptop;
					break ;
				}
			} else if (tmp->next == NULL) {
				/*
					2 (insert 3)
					2 3
				*/
				tmp->next = laptop;
				break ;
			}
		} else if (tmp->price > laptop->price) {
			/*
				1 2 3 4 (insert 0)
				0 1 2 3 4
			*/
			if (prev != NULL) {
				laptop->next = prev->next;
				prev->next = laptop;
				break ;
			} else {
				laptop->next = tmp;
				*map = laptop;
				break ;
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

static void printAllLaptops(t_map *map) {
	if (!map)
		return ;
	t_map *tmp = map;
	while (tmp) {
		printf("Laptop Price: %d\n", tmp->price);
		tmp = tmp->next;
	}
}

static void clearAllLaptops(t_map **map) {
	if (!map || !(*map))
		return ;

	t_map *tmp = *map;
	t_map *aux;

	while (tmp) {
		aux = tmp->next;
		free(tmp);
		tmp = aux;
	}
}

static bool checkMatch(t_map *map, int *test) {
	if (!map || !test)
		return (false);
	t_map *tmp = map;
	while (tmp) {
		while (tmp && tmp->quality < test[1])
			tmp = tmp->next;
		if (!tmp)
			return (false);
		if (tmp->price < test[0] && tmp->quality >= test[1])
			return (true);
		if (tmp->price > test[0])
			return (false);
		tmp = tmp->next;
	}
	return (false);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 100000)
		return (0);
	int **test = (int **)calloc(input, sizeof(int *));
	if (!test)
		return (0);
	for (int i = 0; i < input; ++i) {
		test[i] = (int *)calloc(2, sizeof(int));
		if (!test[i]) {
			while (i--)
				free(test[i]);
			free(test);
			return (0);
		}
	}

	for (int i = 0; i < input; ++i) {
		for (int j = 0; j < 2; ++j)
			scanf("%d", &test[i][j]);
	}

	t_map *mainMap = NULL;

	for (int i = 0; i < input; ++i) {
		t_map *map = createNewMap();
		if (!map) {
			clearAllLaptops(&mainMap);
			for (int i = 0; i < input; ++i)
				free(test[i]);
			free(test);
			return (0);
		}
		map->price = test[i][0];
		map->quality = test[i][1];
		insertNewLaptop(&mainMap, map);
	}
	//printAllLaptops(mainMap);
	/*
		First checking is about to look if there are values where the price is less and the laptop is better
		if the price of a laptop is higher than another laptop and the quality is equal or above, Alex
		wins more one point
	

	for (int i = 0; i < input; ++i) {
		for (int j = i + 1; j < input; ++j) {
			if (test[j][0] > test[i][0] && test[i][1] > test[j][1]) {
				// For now, if just one option found Alex is the champion
				puts("Happy Alex");
				for (int i = 0; i < input; ++i)
					free(test[i]);
				free(test);
				return (0);
			}
		}
	}
	puts("Poor Alex");*/
	for (int i = 0; i < input; ++i) {
		if (checkMatch(mainMap, test[i])) {
			puts("Happy Alex");
			for (int i = 0; i < input; ++i)
				free(test[i]);
			free(test);
			clearAllLaptops(&mainMap);
			return (0);
		}
	}
	puts("Poor Alex");
	for (int i = 0; i < input; ++i)
		free(test[i]);
	free(test);
	clearAllLaptops(&mainMap);
	return (0);
}
