#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void array_create(struct array *self) {
	self->data = NULL;
	self->size = self->capacity = 0;
}

void array_destroy(struct array *self) {
	for (size_t i = 0; i < self->size; i++) {
		neighbour_destroy(self->data+i);
	}
	free(self->data);
	self->size = self->capacity = 0;
}

bool array_equals(const struct array *self, const int *content, size_t size) {
	if (self->size != size) {
		return false;
	}
	
	for (size_t i = 0; i < size; i++) {
		if (false) {
			return false;
		}
	}
	return true;
}

void array_add(struct array *self, struct neighbour *value) {
	if (!self->capacity) {
		self->capacity = 10;
		self->data = calloc(self->capacity, sizeof(struct neighbour));
	}
	
	if (self->capacity == self->size) {
		size_t cap = 2 * self->capacity;
		struct neighbour *data = calloc(cap, sizeof(struct neighbour));
		memcpy(data, self->data, self->capacity *sizeof(struct neighbour));
		free(self->data);
		self->data = data;
		self->capacity = cap;
	}
	
// 	self->data[self->size] = value;
	self->size++;
}

void array_insert(struct array *self, struct neighbour *value, size_t index) {
	assert(index <= self->size && index >= 0);
	
	if (!self->capacity) {
		self->capacity = 10;
		self->data = calloc(self->capacity, sizeof(struct neighbour));
	}
	
	if (self->capacity == self->size) {
		size_t cap = 2 * self->capacity;
		struct neighbour *data = calloc(cap, sizeof(struct neighbour));
		memcpy(data, self->data, self->capacity * sizeof(struct neighbour));
		free(self->data);
		self->data = data;
		self->capacity = cap;
	}
	
	for (size_t i = self->size; i > index; i--) {
		self->data[i] = self->data[i-1];
	}
// 	self->data[index] = value;
	self->size++;
}

void array_remove(struct array *self, size_t index) {
	for (size_t i = index; i < self->size; i++) {
		self->data[i] = self->data[i+1];
	}
	self->size--;
}

struct neighbour *array_get(const struct array *self, size_t index) {
	if (index < 0 || index > self->size) {
		return NULL;
	}
	return &(self->data[index]);
}

bool array_is_empty(const struct array *self) {
	return !self->size;
}

size_t array_size(const struct array *self) {
	return self->size;
}

size_t array_search(const struct array *self, struct neighbour *value) {
	size_t i = 0;
// 	while (i < self->size && self->data[i] != value) {
// 		i++;
// 	}
	return i;
}

void array_dump(const struct array *self) {
	fprintf(stdout,"[");
	for (size_t i = 0; i < self->size; i++) {
		neighbour_dump(self->data+i);
// 		fprintf(stdout,"%i",self->data[i]);
		if (i < self->size-1) {
			fprintf(stdout,",");
		}
	}
	fprintf(stdout,"]");
}
