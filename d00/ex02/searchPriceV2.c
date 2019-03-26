#include "header.h"
#include <string.h>
#include <stdio.h>

int	searchPrice(struct s_art **arts, int n, char *name) {
	int	cmp;
	int	first, middle, last;

	first = 0;
	last = n - 1;
	middle = (first + last) / 2;
	while (first <= last) {
		cmp = strcmp(arts[middle]->name, name);
		if (cmp == 0)
			return (arts[middle]->price);
		else if (cmp > 0)
			last = middle - 1;
		else
			first = middle + 1;
		middle = (first + last) / 2;
	}
	return (-1);
}
