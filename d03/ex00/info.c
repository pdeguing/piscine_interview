#include "header.h"
#include <limits.h>

int	getMin(struct s_node *root) {
	int	min, min_left, min_right;

	if (!root)
		return INT_MAX;
	min = root->value;
	min_left = getMin(root->left);
	min_right = getMin(root->right);
	if (min_left < min)
		min = min_left;
	if (min_right < min)
		min = min_right;
	return min;
}

int	getMax(struct s_node *root) {
	int	max, max_left, max_right;

	if (!root)
		return INT_MIN;
	max = root->value;
	max_left = getMax(root->left);
	max_right = getMax(root->right);
	if (max_left > max)
		max = max_left;
	if (max_right > max)
		max = max_right;
	return max;
}

int	getElements(struct s_node *root) {
	int	elements;

	if (!root)
		return 0;
	elements = 1;
	elements += getElements(root->left);
	elements += getElements(root->right);
	return elements;
}

int	getHeight(struct s_node *root) {
	int	height, height_left, height_right;

	if (!root)
		return -1;
	height = 1;
	height_left = getHeight(root->left);
	height_right = getHeight(root->right);
	if (height_left > height_right)
		height += height_left;
	else
		height += height_right;
	return height;
}

int	isBSTUtil(struct s_node *root, int min, int max) {
	if (!root)
		return 1;
	if (root->value < min || root->value > max)
		return 0;
	if(!isBSTUtil(root->left, min, root->value))
		return 0;
	if (!isBSTUtil(root->right, root->value + 1, max))
		return 0;
	return 1;
}

int	isBST(struct s_node *root) {
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

int	isBalanced(struct s_node *root) {
	int	height_left, height_right;

	if (!root)
		return 1;
	height_left = (root->left) ? getHeight(root->left) : 0;
	height_right = (root->right) ? getHeight(root->right) : 0;
	if (height_left - height_right >= -1
			&& height_left - height_right <= 1
			&& isBalanced(root->left)
			&& isBalanced(root->right))
		return 1;
	return 0;
}

struct s_info	getInfo(struct s_node *root) {
	struct s_info	info;

	info.min = getMin(root);
	info.max = getMax(root);
	info.elements = getElements(root);
	info.height = getHeight(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root);
	return info;
}
