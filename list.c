#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct list_node {
  int value;
  struct list_node *next;
  struct list_node *prev;
};

void list_create(struct list *self) {
	self->first = NULL;
}

void list_destroy(struct list *self) {
	while (!list_is_empty(self)) {
		list_remove(self, 0);
	}
}

bool list_equals(const struct list *self, const int *data, size_t size) {
	if (list_is_empty(self) && !size) {
		return true;
	}
	
	struct list_node *curr = self->first;
	size_t i = 0;
	
	while (curr != NULL) {
		if (curr->value != data[i]) {
			return false;
		}
		i++;
		curr = curr->next;
	}
	
	return (i == size);
}

void list_add_back(struct list *self, int value) {
	struct list_node *ajout = malloc(sizeof(struct list_node));
	ajout->value = value;
	ajout->next = NULL;
	
	if (self->first == NULL) {
		self->first = ajout;
		return;
	}
	
	struct list_node *curr = self->first;
	
	while (curr != NULL && curr->next != NULL) {
		curr = curr->next;
	}
	
	curr->next = ajout;
}

void list_add_front(struct list *self, int value) {
	struct list_node *ajout = malloc(sizeof(struct list_node));
	ajout->value = value;
	ajout->next = self->first;
	self->first = ajout;
}

void list_insert(struct list *self, int value, size_t index) {
	if (!index) {
		list_add_front(self, value);
		return;
	}
	
	struct list_node *curr = self->first, *ajout;
	
	if (curr == NULL) {
		return;
	}
	curr = curr->next;
	
	ajout = malloc(sizeof(struct list_node));
	ajout->value = value;
	ajout->next = NULL;
	
	size_t curr_index = 1;
	
	while (curr->next != NULL && curr_index+1 < index) {
		curr = curr->next;
		curr_index++;
	}
	
	ajout->next = curr->next;
	
	curr->next = ajout;
}

void list_remove(struct list *self, size_t index) {
	struct list_node *curr = self->first, *other;
	size_t curr_index = 0;
	
	if (curr == NULL || index < 0) {
		return;
	}
	
	if (!index) {
		other = self->first;
		self->first = other->next;
		free(other);
		return;
	}
	
	while (curr->next != NULL && curr_index+1 < index) {
		curr = curr->next;
		curr_index++;
	}
	
	other = curr->next;
	if (curr->next != NULL) {
		curr->next = curr->next->next;
	}
	free(other);
}

int *list_get(const struct list *self, size_t index) {
	struct list_node *curr = self->first;
	size_t curr_index = 0;
	
	while (curr->next != NULL && curr_index < index) {
		curr = curr->next;
		curr_index++;
	}
	if (curr_index != index) {
		return NULL;
	}
	return &(curr->value);
}

bool list_is_empty(const struct list *self) {
	return self->first == NULL;
}

size_t list_size(const struct list *self) {
	size_t size = 0;
	struct list_node *curr = self->first;
	
	while (curr != NULL) {
		curr = curr->next;
		size++;
	}
	
	return size;
}

size_t list_search(const struct list *self, int value) {
	struct list_node *curr = self->first;
	size_t i = 0;
	
	while (curr != NULL) {
		if (curr->value == value) {
			return i;
		}
		curr = curr->next;
		i++;
	}
	
	return i;
}

void list_import(struct list *self, const int *other, size_t size) {
	list_destroy(self);
	for (size_t i = size-1; i > 0; i--) {
		list_add_front(self, other[i]);
	}
	list_add_front(self, other[0]);
}

void list_dump(const struct list *self) {
	struct list_node *curr = self->first;
	
	fprintf(stdout,"[");
	
	while (curr != NULL) {
		fprintf(stdout,"%i,",curr->value);
	}
	
	fprintf(stdout,"]");
}

bool list_is_sorted(const struct list *self) {
	struct list_node *curr = self->first;
	
	while (curr != NULL) {
		if (curr->next != NULL && (curr->value > curr->next->value)) {
			return false;
		}
		curr = curr->next;
	}
	
	return true;
}
