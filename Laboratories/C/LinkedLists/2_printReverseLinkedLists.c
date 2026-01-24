#include <stdio.h>
#include <stdlib.h>

typedef struct s_num {
	int index;
	int num;
	struct s_num *next;
} t_num;

static t_num *createNewList(void) {
	t_num *new_list;
	static int index = 0;

	new_list = calloc(1, sizeof(t_num));
	if (!new_list)
		return (NULL);
	new_list->index = index;
	++index;
	new_list->next = NULL;
	return (new_list);
}

static void insertNewValue(t_num **myNumberList, t_num *new) {
	if (!myNumberList || !new)
		return ;
	if (!(*myNumberList)) {
		*myNumberList = new;
		return ;
	}
	t_num *tmp = *myNumberList;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static void printReverseList(t_num *myNumberList) {
	t_num *tmp = myNumberList;

	if (tmp) {
		tmp = tmp->next;
		printReverseList(tmp);
	}
	if (myNumberList != NULL)
		printf("List[%d]: %d\n", myNumberList->index, myNumberList->num);
}

static void clearMyNumberList(t_num **myNumberList) {
	if (!myNumberList || !(*myNumberList))
		return ;
	t_num *tmp = *myNumberList;
	t_num *aux;
	while (tmp) {
		aux = tmp->next;
		free(tmp);
		tmp = aux;
	}
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (input < 1 || input > 1000)
		return (1);

	t_num *myNumberList = NULL;
	int num;

	for (int i = 0; i < input; ++i) {
		num = i;
		t_num *new = createNewList();
		if (!new) {
			clearMyNumberList(&myNumberList);
			return (1);
		}
		new->num = i;
		insertNewValue(&myNumberList, new);
	}
	printReverseList(myNumberList);
	clearMyNumberList(&myNumberList);
	return (0);
}
