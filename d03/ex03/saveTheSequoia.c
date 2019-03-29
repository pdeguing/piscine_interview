#include "header.h"
#include <stdio.h>

void	swapLeft(struct s_node **root, struct s_node **left) {
	struct s_node	*tmp;

	tmp = *root;
	*root = *left;
	*left = tmp;
	tmp = (*root)->right;
	(*root)->right = (*left)->right;
	(*left)->right = tmp;
	tmp = (*root)->left;
	(*root)->left = (*left)->left;
	(*left)->left = tmp;
}

void	swapRight(struct s_node **root, struct s_node **right) {
	struct s_node	*tmp;

	tmp = *root;
	*root = *right;
	*right = tmp;
	tmp = (*root)->left;
	(*root)->left = (*right)->left;
	(*right)->left = tmp;
	tmp = (*root)->right;
	(*root)->right = (*right)->right;
	(*right)->right = tmp;
}

void	saveTheSequoia(struct s_node **root) {
	if (!root || !*root)
		return ;
	saveTheSequoia(&((*root)->left));
	if ((*root)->left && (*root)->value < (*root)->left->value) {
		swapLeft(root, &((*root)->left));
		//saveTheSequoia(&((*root)->left));
		//saveTheSequoia(&((*root)->right));
		saveTheSequoia(root);
	}
	saveTheSequoia(&((*root)->right));
	if ((*root)->right && (*root)->value < (*root)->right->value) {
		swapRight(root, &((*root)->right));
		//saveTheSequoia(&((*root)->left));
		//saveTheSequoia(&((*root)->right));
		saveTheSequoia(root);
	}
}
