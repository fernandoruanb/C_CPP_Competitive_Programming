#include <stdio.h>
#include <stdlib.h>

typedef struct s_numbers {
	int index;
	int num;
	struct s_numbers *next;
} t_num;

static t_num *createNewList(void) {
	t_num *new_list;
	static int index = 1;

	new_list = calloc(1, sizeof(t_num));
	if (!new_list)
		return (NULL);
	new_list->index = index;
	new_list->next = NULL;
	++index;
	return (new_list);
}

static void printAllValues(t_num *list) {
	if (!list)
		return ;
	puts("Printing in a regular way");
	t_num *tmp = list;
	while (tmp) {
		printf("List[%d]: %d\n", tmp->index, tmp->num);
		tmp = tmp->next;
	}
}

static void printReverseValues(t_num *list) {
	if (!list)
		return ;
	if (list)
		printReverseValues(list->next);
	if (list != NULL)
		printf("List [%d]: %d\n", list->index, list->num);
}

static void clearAllLists(t_num **list) {
	if (!list || !(*list))
		return ;
	t_num *tmp = *list;
	t_num *aux;
	while (tmp) {
		aux = tmp->next;
		free(tmp);
		tmp = aux;
	}
}

static int countHowManyLists(t_num *list) {
	if (!list)
		return (0);
	t_num *tmp = list;
	int length = 0;
	while (tmp) {
		++length;
		tmp = tmp->next;
	}
	return (length);
}

static void reorganizeIndexSystem(t_num **list) {
	if (!list || (!(*list)))
		return ;

	int index = 1;

	t_num *tmp = *list;

	while (tmp) {
		tmp->index = index;
		++index;
		tmp = tmp->next;
	}
}

static void insertInBackTarget(t_num **list, t_num *new, int index) {
	if (!list || !new || !index || index <= 0)
		return ;
	if (!(*list)) {
		*list = new;
		return ;
	}
	t_num *tmp = *list;
	t_num *aux;
	while (tmp) {
		if (tmp->index == index) {
			if (!tmp->next) {
				tmp->next = new;
				return ;
			}
			else {
				/*
					1 2 3 (I want to insert 1 again in the back of 2)
					1 2 1 3
					for two tmp->next = new; (it needs to see the new member)
					for the new member, the next will be the tmp->next (3) in that case
				*/
				new->next = tmp->next;
				tmp->next = new;
				reorganizeIndexSystem(list);
				return ;
			}
		}
		tmp = tmp->next;
	}
	free(new);
	new = NULL;
	printf("Unfortunately, that index %d does not exist", index);
}

static void insertInFrontTarget(t_num **list, t_num *new, int index) {
	if (!list || !new || index <= 0)
		return ;
	if (!(*list)) {
		*list = new;
		return ;
	}
	t_num *tmp = *list;
	t_num *prev = NULL; // the first must need to be NULL

	/*
		1 2 3 (I want to insert 4 in index 1)
		the result must need to be 4 1 2 3
		if the index is 1, the value will be in the first position and it does not have a previous value
		but if the value is in index 2, for example,
		1 2 3
		1 4 2 3
		then new->next = tmp (index 2)
		and the prev->next = new (the new list)
	*/

	while (tmp) {
		if (tmp->index == index) {
			new->next = tmp;
			if (prev == NULL) 
				*list = new;
			else if (prev != NULL)
				prev->next = new;
			reorganizeIndexSystem(list);
			return ;
		}
		puts("Hi");
		prev = tmp;
		tmp = tmp->next;
	}
	free(new);
	new = NULL;
	printf("Unfortunately, the index %d does not exist", index);
}

int main(void) {
	int input;

	puts("Insert the quantity of inputs and after direction Front (F) or Back (B) and position (1, 2, 3...)");
	scanf("%d", &input);

	if (!input || input < 0 || input > 1000) 
		return (1);
	

	char direction;
	int position, value;

	t_num *myNumberList = NULL;

	for (int i = 0; i < input; ++i) {
		scanf(" %c", &direction); // the %c reads until the \n of the last scanf we need a space to ignore
		if (!direction || (direction != 'F' && direction != 'B')) {
			clearAllLists(&myNumberList);
			return (1);
		}
		scanf("%d", &position);
		if (!position || position < 0 || position > 1000) {
			clearAllLists(&myNumberList);
			return (1);
		}
		scanf("%d", &value);
		if (!value || value < 0 || value > 10000) {
			clearAllLists(&myNumberList);
			return (1);
		}
		t_num *new_list = createNewList();
		if (!new_list) {
			clearAllLists(&myNumberList);
			return (1);
		}
		new_list->num = value;
		if (direction == 'F')
			insertInFrontTarget(&myNumberList, new_list, position);
		else
			insertInBackTarget(&myNumberList, new_list, position);
	}
	printAllValues(myNumberList);
	puts("Printing in reverse order");
	printReverseValues(myNumberList);
	clearAllLists(&myNumberList);
	return (0);
}
