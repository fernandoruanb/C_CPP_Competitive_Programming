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
	new_list->next = NULL;
	new_list->index = index;
	++index;
	return (new_list);
}

static void printAllValues(t_num *myNumberList) {
	puts("Priting everything in regular order");

	while(myNumberList) {
		printf("List[%d]: %d\n", myNumberList->index, myNumberList->num);
		myNumberList = myNumberList->next;
	}
}

static void printReverseValues(t_num *myNumberList) {
	if (myNumberList)
		printReverseValues(myNumberList->next);
	if (myNumberList != NULL)
		printf("List[%d]: %d\n", myNumberList->index, myNumberList->num);
}

static void insertValueInBack(t_num **myNumberList, t_num *new) {
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

static void insertValueInFront(t_num **myNumberList, t_num *new) {
	if (!myNumberList || !new)
		return ;
	if (!(*myNumberList)) {
		*myNumberList = new;
		return ;
	}
	new->next = *myNumberList;
	*myNumberList = new;
}

static void clearAllLists(t_num **myNumberList) {
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
	if (!myNumberList)
		return ;

	t_num *tmp = myNumberList;
	int length = 0;

	while (tmp) {
		tmp = tmp->next;
		++length;
	}
	printf("Total Nodes: %d\n", length);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (input < 0 || input > 1000)
		return (1);

	t_num *myNumberList = NULL;

	for (int i = 0; i < input; ++i) {
		t_num *new_list = createNewList();
		if (!new_list) {
			clearAllLists(&myNumberList);
			return (1);
		}
		new_list->num = i;
		insertValueInFront(&myNumberList, new_list);
		//insertValueInBack(&myNumberList, new_list);
	}
	printAllValues(myNumberList);
	puts("Printing reverse values");
	printReverseValues(myNumberList);
	countAllNodes(myNumberList);
	clearAllLists(&myNumberList);
	return (0);
}
