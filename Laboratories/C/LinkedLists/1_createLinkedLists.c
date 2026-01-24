#include <stdio.h>
#include <stdlib.h>

typedef struct s_number {
	int index;
	int num;
	struct s_number *next;
} t_num;

static t_num *createNewList(void) {
	static int index = 0;
	t_num *new_list;

	new_list = calloc(1, sizeof(t_num));
	if (!new_list)
		return (NULL);
	new_list->index = index;
	new_list->next = NULL;
	++index;
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

static void printAllValues(t_num *myNumberList) {
	if (!myNumberList)
		return ;
	while (myNumberList) {
		printf("List[%d]: %d\n", myNumberList->index, myNumberList->num);
		myNumberList = myNumberList->next;
	}
}

static void clearAllValues(t_num **myNumberList) {
	t_num *tmp;
	t_num *aux;

	if (!myNumberList || !(*myNumberList))
		return ;

	tmp = *myNumberList;
	while (tmp) {
		aux = tmp->next;
		free(tmp);
		tmp = aux;
	}
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (input < 0 || input > 1000)
		return (1);
	int value;
	t_num *myNumberList = NULL;
	for (int i = 0; i < input; ++i) {
		scanf("%d", &value);
		t_num *new = createNewList();
		if (!new) {
			clearAllValues(&myNumberList);
			return (1);
		}
		new->num = value;
		insertNewValue(&myNumberList, new);
	}
	printAllValues(myNumberList);
	clearAllValues(&myNumberList);
	return (0);
}
