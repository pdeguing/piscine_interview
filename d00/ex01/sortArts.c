#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void	sortArts(struct s_art **arts) {
	struct s_art	*tmp;
	int	j;

	for (int i = 1; arts[i]; i++) {
		tmp = arts[i];
		j = i - 1;
		while (j >= 0 && strcmp(arts[j]->name, tmp->name) > 0) {
				arts[j + 1] = arts[j];
				j--;
		}
		arts[j + 1] = tmp;
	}
}
