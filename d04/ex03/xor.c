#include "header.h"
#include <stdlib.h>

char	*getXor(char *a, char *b) {
	char	*prod;

	prod = malloc(sizeof(char) * 7);
	if (!prod)
		return NULL;
	prod[6] = '\0';
	for (int i = 0; i < 6; i++) {
		if ((a[i] == '1') + (b[i] == '1') == 1)
			prod[i] = '1';
		else
			prod[i] = '0';
	}
	return prod;
}

int	toInt(char *bits) {
	int	ret = 0;
	int	bit = 32;

	for (int i = 0; i < 6; i++) {
		if (bits[i] - '0')
			ret += bit;
		bit /= 2;
	}
	return ret;
}
