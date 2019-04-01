#include "header.h"
#include <stdlib.h>

char	*getAnd(char *a, char *b) {
	char	*new;
	int	neg_a = 0, neg_b = 0;

	new = malloc(sizeof(char) * 5);
	if (!new)
		return NULL;
	new[4] = '\0';
	if (a[0] == '~') {
		neg_a = 1;
		a += 1;
	}
	if (b[0] == '~') {
		neg_b = 1;
		b += 1;
	}
	for (int i = 0; i < 4; i++) {
		if ((neg_a ? a[i] == '0' : a[i] == '1')
				&& (neg_b ? b[i] == '0' : b[i] == '1'))
			new[i] = '1';
		else
			new[i] = '0';
	}
	return new;
}

char	*getOr(char *a, char *b) {
	char	*new;
	int	neg_a = 0, neg_b = 0;

	new = malloc(sizeof(char) * 5);
	if (!new)
		return NULL;
	if (a[0] == '~') {
		neg_a = 1;
		a += 1;
	}
	if (b[0] == '~') {
		neg_b = 1;
		b += 1;
	}
	for (int i = 0; i < 4; i++) {
		if ((neg_a ? a[i] == '0' : a[i] == '1')
				|| (neg_b ? b[i] == '0' : b[i] == '1'))
			new[i] = '1';
		else
			new[i] = '0';
	}
	return new;
}

int	toInt(char *bits) {
	int	ret = 0;
	int	bit = 8;

	for (int i = 0; i < 4; i++) {
		if (bits[i] - '0')
			ret += bit;
		bit /= 2;
	}
	return ret;
}
