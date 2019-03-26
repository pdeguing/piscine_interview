#include "header.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_node	*engrave_letter(char letter) {
	struct s_node	*node;

	node = malloc(sizeof(struct s_node));
	node->c = letter;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

struct s_node	*forge_ring(char *lettering) {
	struct s_node	*ring;

	ring = NULL;
	for (int i = 0; lettering[i]; i++) {
		if (!ring) {
			ring = engrave_letter(lettering[i]);
			ring->prev = ring;
			ring->next = ring;
		} else {
			ring->prev->next = engrave_letter(lettering[i]);
			ring->prev->next->prev = ring->prev;
			ring->prev = ring->prev->next;
			ring->prev->next = ring;
		}
	}
	return (ring);
}

char	*read_lettering(struct s_node *ring, int *text, int size) {
	int		direction;
	char		*str;
	int		rot;

	str = malloc(sizeof(char) * (size + 1));
	memset(str, 0, size + 1);
	for (int i = 0; i < size; i++) {
		rot = text[i];
		direction = (rot < 0) ? -1 : 1;
		rot *= direction;
		for (int i = 0; i < rot; i++) {
			if (direction == 1)
				ring = ring->next;
			else
				ring = ring->prev;
		}
		str[i] = ring->c;
	}
	return (str);
}

char	*precious(int *text, int size) {
	struct s_node	*ring; 
	char		*str;

	ring = forge_ring(CS);
	str = read_lettering(ring, text, size);
	return (str);
}
