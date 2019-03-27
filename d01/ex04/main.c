#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue	*q;

	q = queueInit();
	enqueue(q, "bonjour");
	printf("peek = %s\n", peek(q));
	enqueue(q, "au revoir");
	printf("peek = %s\n", peek(q));
	printf("dequeue = %s\n", dequeue(q));
	printf("peek = %s\n", peek(q));
	printf("dequeue = %s\n", dequeue(q));
	printf("isEmpty = %d\n", isEmpty(q));
	return (0);
}



// Function used for the test
// Don't go further :)

