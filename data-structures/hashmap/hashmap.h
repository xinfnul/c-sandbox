#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct hashmap hashmap_t;

hashmap_t *hashmap_create(size_t initial_size);

void hashmap_destroy(hashmap_t *map);

bool hashmap_set(hashmap_t *map, const char *key, const char *value);

const char *hashmap_get(const hashmap_t *map, const char *key);

bool hashmap_delete(hashmap_t *map, const char *key);

bool hashmap_contains(const hashmap_t *map, const char *key);

size_t hashmap_size(const hashmap_t *map);

#endif
