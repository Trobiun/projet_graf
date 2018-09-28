#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdbool.h>
#include "neighbour.h"

struct array {
  struct neighbour *data;
  size_t capacity;
  size_t size;
};

/*
 * Create an empty array
 */
void array_create(struct array *self);

/*
 * Destroy an array
 */
void array_destroy(struct array *self);

/*
 * Compare the array to another array (content and size)
 */
bool array_equals(const struct array *self, const int *content, size_t size);

/*
 * Add an element at the end of the array
 */
void array_add(struct array *self, struct neighbour *value);

/*
 * Insert an element in the array (preserving the order)
 */
void array_insert(struct array *self, struct neighbour *value, size_t index);

/*
 * Remove an element in the array (preserving the order)
 */
void array_remove(struct array *self, size_t index);

/*
 * Get a pointer to the element at the specified index in the array
 */
struct neighbour *array_get(const struct array *self, size_t index);

/*
 * Tell if the array is empty
 */
bool array_is_empty(const struct array *self);

/*
 * Get the size of the array
 */
size_t array_size(const struct array *self);

/*
 * Search for an element in the array.
 */
size_t array_search(const struct array *self, struct neighbour *value);

/*
 * Print an array to stdout
 */
void array_dump(const struct array *self);

#endif // ARRAY_H
