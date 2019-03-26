#include "header.h"

#include <string.h>
#include <stdlib.h>

#define FNV_offset_basis	0xcbf29ce484222325
#define FNV_prime		0x100000001b3

size_t		hash(char *input) {
	size_t			hash_val = FNV_offset_basis;

	for (int i = 0; input[i]; i++) {
		hash_val *= FNV_prime;
		hash_val ^= input[i];
	}
	return (hash_val);
}

int	rabinKarp(char *string, char *pattern) {
	size_t	hash_pattern, hash_sub;
	char	*sub;
	int	len_pattern, len_string;

	len_pattern = strlen(pattern);
	len_string = strlen(string);
	if (*pattern == 0)
		return (len_string);
	hash_pattern = hash(pattern);
	for (int i = 0; i < len_string - len_pattern; i++) {
		sub = malloc(sizeof(char) * (len_pattern + 1));
		sub[len_pattern] = 0;
		strncpy(sub, string + i, len_pattern);
		hash_sub = hash(sub);
		if (hash_pattern == hash_sub)
			if (strcmp(pattern, sub) == 0)
				return (i);
	}
	return (-1);
}

int	howManyJesus(char *bible, char *jesus) {
	int	i = 0;
	int	count = 0;
	int	occ = 0;

	while (bible[i]) {
		occ = rabinKarp(bible + i, jesus);
		if (occ == -1)
			return count;
		i += occ + 1;
		count++;
	}
	return (count);
}
