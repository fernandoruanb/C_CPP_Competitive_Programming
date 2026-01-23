#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_phases {
	int dragonStrength;
	int bonusWinBattle;
	t_list *next;
} t_list;

static t_list *createNewList(void) {
	t_list *new_list;

	new_list = calloc(1, sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->dragonStrength = -1;
	new_list->bonusWinBattle = -1;
	new_list->next = NULL;
	return (new_list);
}

static void addNewListInFinal(t_list **list, t_list *new) {

	if (!list || !new || !(*list))
		return ;
	while ((*list)->next)
		*list = list->next;
	*list = new;
}

static void addNewListInStart(t_list **list, t_list *new) {
	if (list && new) {
		new->next = *list;
		*lst = new;
	}
}

static void clearTheListOfPhases(t_list **list) {
	t_list *next;
	t_list *tmp;

	while (list) {
		tmp = *list;
		while (tmp) {
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		*list = NULL;
	}
}

static t_list getTheLastList(t_list *list) {
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

static void putInOrderList(t_list **list, t_list *new) {
	if (!list || !new)
		return ;
	if (!(*list)) {
		*list = new;
		return ;
	}
	while ((*list)->next) {
		if ((*list)->dragonStrength <= new->dragonStrength) {
			(*list)->next = new;
			return ;	
		} else if ((*list)->dragonStrength > new->dragonStrength){
			new->next = *list;
			*list = new;
			return ;
		}
		(*list) = (*list)->next;
	}
}

static char checkResult(int kiritoStrength, t_list *list) {
	if (!list)
		return ('\0');

	char result = '\0';

	while (list->next) {
		if (kiritoStrength >= list->dragonStrength) {
			kiritoStrength += list->bonusWinBattle;
			result = 'Y';
		} else {
			result = 'N';
			break ;
		}
		list = list->next;
	}
	return (result);
}

int main(void) {
	int *room = (int *)calloc(2, sizeof(int));

	if (!room)
		return (0);

	for (int i = 0; i < 2; ++i)
		scanf("%d", room + i);

	if (room[0] < 0 || room[0] > 10000 || room[1] < 0 || room[1] > 1000) {
		free(room);
		return (0);
	}

	int phases = room[1];
	char result = '\0';
	int kiritoStrength = room[0];
	int maxDragonStrength = 0;
	int *phase = NULL;
	t_list *new_phase = createNewList();

	if (!new_phase) {
		free(room);
		return (0);
	}

	while (phases--) {
		phase = (int *)calloc(2, sizeof(int));
		if (!phase) {
			free(room);
			free(phase);
			return (0);
		}
		for (int i = 0; i < 2; ++i)
			scanf("%d", phase + i);

		t_list *new = createNewList();
		if (!new) {
			clearTheListOfPhases(&new_phase);
			free(room);
			free(phase);
			return (0);
		}
		new->dragonStrength = phase[0];
		new->bonusWinBattle = phase[1];
		putInOrderList(&new_phase, new);
		free(phase);
		phase = NULL;
	}
	result = checkResult(kiritoStrength, new_phase);
	if (result == 'Y')
		write(1, "YES\n", 4);
	else if (result == 'N')
		write(1, "NO\n", 3);
	free(room);
	return (0);
}
