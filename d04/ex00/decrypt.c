#include "header.h"
#include <stdio.h>

char	*getSum(char *a, char *b) {
	int	carry = 0;
	int	bit_sum;

	for (int i = 5; i >= 0; i--) {
		bit_sum = carry + a[i] - '0' + b[i] - '0';
		if (bit_sum == 0)
			b[i] = '0';
		if (bit_sum == 1) {
			b[i] = '1';
			carry = 0;
		}
		if (bit_sum == 2) {
			b[i] = '0';
			carry = 1;
		}
		if (bit_sum == 3) {
			b[i] = '1';
			carry = 1;
		}
	}
	return b;
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
