#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack		*stackInit(void) {
	struct s_stack		*s;

	s = malloc(sizeof(struct s_stack));
	if (!s)
		return (NULL);
	s->item = NULL;
	return (s);
}

int			isEmpty(struct s_stack *stack) {
	return (!stack || !stack->item);
}

void			*pop(struct s_stack *stack) {
	struct s_item		*i;
	void			*content;

	if (isEmpty(stack))
		return (NULL);
	i = stack->item;
	content = i->word;
	stack->item = i->next;
	free(i);
	return (content);
}

void			push(struct s_stack *stack, char *word) {
	struct s_item		*i;

	if (!stack)
		return ;
	i = malloc(sizeof(struct s_item));
	if (!i)
		return ;
	i->word = word;
	i->next = stack->item;
	stack->item = i;
}

void			printReverseV2(struct s_node *lst) {
	struct s_stack		*s;

	s = stackInit();
	if (!s)
		return ;
	while (lst) {
		push(s, lst->word);
		lst = lst->next;
	}
	while (!isEmpty(s)) {
		printf("%s", (char *)pop(s));
		if (!isEmpty(s))
			printf(" ");
	}
	printf("\n");
}
