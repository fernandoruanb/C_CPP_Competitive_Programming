#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_tree {
	int value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

static t_tree *createNewBranch(void) {
	t_tree *newBranch;

	newBranch = calloc(1, sizeof(t_tree));
	if (!newBranch)
		return (NULL);
	newBranch->left = NULL;
	newBranch->right = NULL;
	return (newBranch);
}

static void clearTheTree(t_tree **tree) {
	if (!tree || !(*tree))
		return ;
	clearTheTree(&(*tree)->left);
	clearTheTree(&(*tree)->right);
	free(*tree);
	*tree = NULL;
}

/*
	Linked Lists -> we insert new lists in the middle
	Trees -> we do not put in the middle
*/

static void insertNewBranch(t_tree **tree, t_tree *new) {
	if (!tree || !new)
		return ;
	if (!(*tree)) {
		*tree = new;
		return ;
	}

	t_tree *tmp = *tree;
	t_tree *prev = NULL; // we always need to know the previous value in trees

	/*
		BST insertion (Binary Search Tree)
		Left -> values less than the actual branch
		Right -> values greater than the actual branch
		(we avoid duplicates erasing the branch duplicated attempt of insertion)

	*/

	while (tmp) {
		prev = tmp;
		if (tmp->value > new->value)
			tmp = tmp->left;
		else if (tmp->value < new->value)
			tmp = tmp->right;
		else if (tmp->value == new->value) {
			free(new);
			puts("We cannot allow duplicates in that tree");
			return ;
		}
	}
	if (prev->value > new->value)
		prev->left = new;
	else
		prev->right = new;
}

static void printAllBranchesOrganized(t_tree *tree) {
	if (!tree)
		return ;

	/*
		First, we show all the values in the left position
		Second, we print the root value
		Third, we show all the values in the right position
	*/

	// the branches are not totally organized like we change and adjust the tree and sub-trees but the order put them, the structure, the hierarchy, makes seem like organized

	printAllBranchesOrganized(tree->left); // less values first
	printf("%d\n", tree->value); // the root branch
	printAllBranchesOrganized(tree->right); // high values in the final
}

int main(void) {

	int input;

	puts("How many branches do you intend to build? Insert each value after it");

	scanf("%d", &input);

	t_tree *myBeautifulTree = NULL;
	int value;

	for (int i = 0; i < input; ++i) {
		scanf("%d", &value);
		if (value < 0 || value > 10000) {
			clearTheTree(&myBeautifulTree);
			return (1);
		}
		t_tree *new_branch = createNewBranch();
		if (!new_branch) {
			clearTheTree(&myBeautifulTree);
			return (1);
		}
		new_branch->value = value;
		insertNewBranch(&myBeautifulTree, new_branch);
	}
	puts("Printing all branches organized");
	printAllBranchesOrganized(myBeautifulTree);
	clearTheTree(&myBeautifulTree);
	return (0);
}
