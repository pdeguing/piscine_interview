#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	tankPrint(struct s_tank *tank) {
	struct s_stack 		*s;
	struct s_elem		*e;

	printf("tank: n = %d\n", tank->n);
	for (int i = 0; i < tank->n; i++) {
		s = tank->stacks[i];
		printf("	stack%d: sum = %d -> ", i, s->sum);
		e = s->elem;
		while (e) {
			printf("[%d]", e->energy);
			e = e->next;
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	tankPrint(tank);
	tankPush(tank, 50);
	tankPrint(tank);
	for (int i = 0; i <= 10; i++)
		tankPush(tank, 100);
	tankPrint(tank);
	tankPop(tank);
	tankPrint(tank);
	tankPop(tank);
	tankPrint(tank);
	return (0);
}



// Function used for the test
// Don't go further :)
