#include "header.h"
#include <stdlib.h>
#include <string.h>

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

struct s_dict	*dictInit(int capacity) {
	struct s_dict		*dict;

	dict = malloc(sizeof(struct s_dict));
	if (!dict)
		return (NULL);
	dict->items = malloc(sizeof(struct s_item *) * capacity);
	if (!dict->items) {
		free(dict);
		return (NULL);
	}
	for (int i = 0; i < capacity; i++) {
		dict->items[i] = NULL;
	}
	dict->capacity = capacity;
	return (dict);
}

int		dictInsert(struct s_dict *dict, char *key, struct s_art *value) {
	size_t			hash_val;
	int			index;
	struct s_item		*item;

	item = malloc(sizeof(struct s_item));
	if (!item)
		return (-1);
	hash_val = hash(key);
	index = hash_val % dict->capacity;
	item->key = key;
	item->value = value;
	item->next = dict->items[index];
	dict->items[index] = item;
	return (0);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key) {
	size_t			hash_val;
	int			index;
	struct s_item		*item;

	hash_val = hash(key);
	index = hash_val % dict->capacity;
	item = dict->items[index];
	while (item != NULL) {
		if (strcmp(item->key, key) == 0)
			return (item->value);
		item = item->next;
	}
	return (NULL);
}

int		searchPrice(struct s_dict *dict, char *name) {
	struct s_art		*art;

	art = dictSearch(dict, name);
	if (!art)
		return (-1);
	return (art->price);
}
