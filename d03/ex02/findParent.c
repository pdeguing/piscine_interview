#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	findAnc(struct s_node *root, char *first, char *second, struct s_node **anc) {
	int	found = 0;
	int	ret = 0;

	if (!strcmp(root->name, first) || !strcmp(root->name, second)) {
		return 1;
	}
	for (int i = 0; root->children[i]; i++) {
		ret = findAnc(root->children[i], first, second, anc);
		if (ret == 2)
			return 2;
		if (ret == 1)
			found++;
		if (found >= 2) {
			*anc = root;
			return 2;
		}
	}
	if (found > 0)
		return 1;
	return 0;
}

struct s_node	*findParent(struct s_node *root, char *firstSpecies, char *secondSpecies) {
	struct s_node	*anc;

	if (!root || !firstSpecies || !secondSpecies)
		return NULL;
	anc = NULL;
	findAnc(root, firstSpecies, secondSpecies, &anc); 
	return anc;
}
