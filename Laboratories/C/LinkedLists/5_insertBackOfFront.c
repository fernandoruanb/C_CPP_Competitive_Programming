#include <stdio.h>
#include <stdlib.h>

typedef struct s_num {
	int index;
	int num;
	struct s_num *next;
} t_num;

static t_num *createNewList(void) {
	t_num *new_list = calloc(1, sizeof(t_num));
	static int index = 0;

	if (!new_list)
		return (NULL);
	new_list->index = index;
	new_list->next = NULL;
	++index;
	return (new_list);
}

static void printAllValues(t_num *myNumberList) {

	if (!myNumberList)
		return ;

	puts("Printing in regular order");

	t_num *tmp = myNumberList;

	while (tmp) {
		printf("List[%d]: %d\n", tmp->index, tmp->num);
		tmp = tmp->next;
	}
}

static void printReverseValues(t_num *myNumberList) {
	if (!myNumberList)
		return ;
	if (myNumberList)
		printReverseValues(myNumberList->next);
	if (myNumberList != NULL)
		printf("List [%d]: %d\n", myNumberList->index, myNumberList->num);
}

static void insertInFront(t_num **myNumberList, t_num *new) {
	if (!myNumberList || !new)
		return ;
	if (!(*myNumberList)) {
		*myNumberList = new;
		return ;
	}
	new->next = *myNumberList;
	*myNumberList = new;
}

static void insertInBack(t_num **myNumberList, t_num *new) {
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

static void clearAllValues(t_num **myNumberList) {
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

static void countAllNodes(t_num *myNumberList) {
	int length = 0;
	t_num *tmp = myNumberList;

	while (tmp) {
		++length;
		tmp = tmp->next;
	}
	printf("Total nodes: %d\n", length);
}

int main(void) {
	int input, position;

	puts("The first will be the quantity and the rest the position? 0 -> FRONT, 1 -> BACK");
	fflush(stdout);
	scanf("%d\n", &input);

	if (!input || input < 0 || input > 1000)
		return (1);
	
	t_num *myNumberList = NULL;

	for (int i = 0; i < input; ++i) {
		scanf("%d", &position);
		t_num *new_list = createNewList();
		if (!new_list) {
			clearAllValues(&myNumberList);
			return (1);
		}
		new_list->num = i;
		if (position)
			insertInBack(&myNumberList, new_list);
		else
			insertInFront(&myNumberList, new_list);
	}
	printAllValues(myNumberList);
	puts("Printing in reverse order");
	printReverseValues(myNumberList);
	countAllNodes(myNumberList);
	clearAllValues(&myNumberList);
	return (0);
}
