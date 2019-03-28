#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_node	*nodeInit(int value) {
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	if (!n)
		return NULL;
	n->value = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct s_node	*createBST(int *arr, int n) {
	struct s_node	*root;
	int		mid;

	if (n == 0)
		return NULL;
	mid = (n > 2) ? n / 2 : 0;
	root = nodeInit(arr[mid]);
	root->left = createBST(arr, mid);
	root->right = createBST(arr + mid + 1, n - mid - 1);
	return root;
}
