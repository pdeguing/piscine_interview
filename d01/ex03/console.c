#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN		255

struct s_stack		*initStack(void) {
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

int			pop(struct s_stack *stack) {
	struct s_item		*i;
	int			idx;

	if (isEmpty(stack))
		return (0);
	i = stack->item;
	idx = i->idx;
	stack->item = i->next;
	free(i);
	return (idx);
}

void			push(struct s_stack *stack, int idx) {
	struct s_item		*i;

	if (!stack)
		return ;
	i = malloc(sizeof(struct s_item));
	if (!i)
		return ;
	i->idx = idx;
	i->next = stack->item;
	stack->item = i;
}


char	*console(void) {
	char		input[MAX_LEN + 1];
	char		msg[MAX_LEN + 1];	
	int		len_input;
	int		i = 0;
	struct s_stack	*stack;

	memset(input, 0, MAX_LEN + 1);
	memset(msg, 0, MAX_LEN + 1);
	stack = initStack();
	while (1) {
		printf("please be prompt: ");
		fgets(input, MAX_LEN, stdin);
		len_input = strlen(input);
		if (len_input) {
			input[len_input - 1] = '\0';
			if (strcmp(input, "SEND") == 0)
				break ;
			else if (strcmp(input, "UNDO") == 0) {
				i = pop(stack);
				memset(msg + i, 0 , MAX_LEN - i);

			} else {
				push(stack, i);
				if (i > 0)
					msg[i++] = ' ';
				memmove(msg + i, input, len_input);
				i += len_input - 1;
			}
		}
		printf("%s\n", msg);
	}
	return (strdup(msg));
}
