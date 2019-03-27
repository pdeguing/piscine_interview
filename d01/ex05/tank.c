#include "header.h"
#include <stdlib.h>

struct s_tank		*initTank(void) {
	struct s_tank		*t;

	t = malloc(sizeof(struct s_tank));
	if (!t)
		return (NULL);
	t->stacks = NULL;
	t->n = 0;
	return (t);
}

void			tankPush(struct s_tank *tank, int energy) {
	struct s_elem		*e;
	struct s_stack		*s;
	struct s_stack		**tmp;

	e = malloc(sizeof(struct s_elem));
	if (!e)
		return ;
	e->energy = energy;
	e->next = NULL;
	s = NULL;
	if (tank->n > 0)
		s = tank->stacks[tank->n - 1];
	if (s && s->sum + energy <= 1000) {
		e->next = s->elem;
		s->elem  = e;
		s->sum += e->energy;
	} else {
		s = malloc(sizeof(struct s_stack));
		if (!s) {
			free(e);
			return ;
		}
		s->elem = e;
		s->sum = e->energy;
		tank->n++;
		tmp = realloc(tank->stacks, sizeof(struct s_stack *) * tank->n);
		if (!tmp) {
			free(e);
			free(s);
			return ;
		}
		tank->stacks = tmp;
		tank->stacks[tank->n - 1] = s;
	}
}

int			tankPop(struct s_tank *tank) {
	struct s_elem		*e;
	struct s_stack		*s;
	int			energy;

	if (tank->n == 0)
		return (0);
	s = tank->stacks[tank->n - 1];
	e = s->elem;
	energy = e->energy;
	s->elem = e->next;
	s->sum -= energy;
	free(e);
	if (!s->elem) {
		free(s);
		tank->stacks[tank->n - 1] = NULL;
		tank->n--;
	}
	return (energy);
}
