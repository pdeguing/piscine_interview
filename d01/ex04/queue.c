#include "header.h"
#include <stdlib.h>

int	isEmpty(struct s_queue *queue) {
	return (!queue || !queue->first);
}

struct s_queue		*queueInit(void) {
	struct s_queue		*q;

	q = malloc(sizeof(struct s_queue));
	if (!q)
		return (NULL);
	q->first = NULL;
	q->last = NULL;
	return (q);
}

char			*dequeue(struct s_queue *queue) {
	struct s_node		*n;
	char			*content;

	if (isEmpty(queue))
		return (NULL);
	n = queue->first;
	queue->first = n->next;
	if (!n->next)
		queue->last = NULL;
	content = n->message;
	free(n);
	return (content);
}

void			enqueue(struct s_queue *queue, char *message) {
	struct s_node		*n;

	n = malloc(sizeof(struct s_node));
	if (!n)
		return ;
	n->message = message;
	n->next = NULL;
	if (isEmpty(queue)) {
		queue->first = n;
		queue->last = n;
	} else {
		queue->last->next = n;
		queue->last = n;
	}
}

char			*peek(struct s_queue *queue) {
	if (isEmpty(queue))
		return (NULL);
	return (queue->first->message);
}
