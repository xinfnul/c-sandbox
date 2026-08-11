#include "hashmap.h"

#include <stdio.h>

int main(void) {
  hashmap_t *map;

  map = hashmap_create(0);

  if (map == NULL) {
    fprintf(stderr, "Failed to create hashmap\n");
    return 1;
  }

  printf("Initial size: %zu\n", hashmap_size(map));

  hashmap_set(map, "name", "X");
  hashmap_set(map, "age", "00");
  hashmap_set(map, "language", "C");

  printf("Size after inserts: %zu\n", hashmap_size(map));

  printf("name: %s\n", hashmap_get(map, "name"));
  printf("age: %s\n", hashmap_get(map, "age"));
  printf("language: %s\n", hashmap_get(map, "language"));

  if (hashmap_contains(map, "name")) {
    printf("'name' exists\n");
  }

  if (!hashmap_contains(map, "random")) {
    printf("'random' does not exist\n");
  }

  hashmap_set(map, "name", "Z");

  printf("Updated name: %s\n", hashmap_get(map, "name"));

  if (hashmap_delete(map, "name")) {
    printf("'name' deleted successfully\n");
  } else {
    printf("Failed to delete 'name'\n");
  }

  printf("Size after delete: %zu\n", hashmap_size(map));

  if (!hashmap_contains(map, "name")) {
    printf("'name' no longer exists\n");
  }

  const char *value = hashmap_get(map, "random");

  if (value == NULL) {
    printf("'random' was not found\n");
  }

  hashmap_destroy(map);

  return 0;
}
