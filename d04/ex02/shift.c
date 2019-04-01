#include "header.h"

char	*rightShift(char *bin, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 5; j > 0; j--) {
			bin[j] = bin[j - 1];
		}
	}
	return bin;
}

char	*leftShift(char *bin, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 5; j++) {
			bin[j] = bin[j + 1];
		}
		bin[5] = '0';
	}
	return bin;
}

int	toInt(char *bits) {
	int	ret = 0;
	int	bit = 32;

	for (int i = 0; i < 6; i++) {
		if (bits[i] - '0')
			ret += bit;
		bit /= 2;
	}
	return (bits[0] - '0' ? ret - 64 : ret);
}
