#include "header.h"
#include <stdio.h>

void	printReverse(struct s_node *lst) {
	if (!lst)
		return ;
	if (!lst->next)
		printf("%s", lst->word);
	else {
		printReverse(lst->next);
		printf(" %s", lst->word);
	}
}
