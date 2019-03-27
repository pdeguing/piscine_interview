#include "header.h"
#include <stdlib.h>

char		*NthLastCity(struct s_city *city, int n) {
	struct s_city		*c;
	int			i = 0;

	if (!city)
		return (NULL);
	c = city;
	while (city) {
		if (i >= n && city->next)
			c = c->next;
		city = city->next;
		i++;
	}
	if (i <= n)
		return (NULL);
	return (c->name);
}
