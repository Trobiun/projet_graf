#include "neighbour.h"

void neighbour_create(struct neighbour *self, int neighbour, int weight) {
	if (self != NULL) {
		self->neighbour = neighbour;
		self->weight = weight;
		self->nextNeighbour = NULL;
		self->previousNeighbour = NULL;
	}
}

// void neighbour_destroy(struct neighbour *self) {
// 	if (self != NULL) {
// 		struct neighbour *next = self->previousNeighbour;
// 		next->nextNeighbour = self->nextNeighbour;
// 		(next->nextNeighbour)->previousNeighbour = next;
// 		self = next;
// 	}
// }

void neighbour_destroy_start(struct neighbour **start) {
	if (start != NULL) {
		struct neighbour *last = (*start)->previousNeighbour;
		if (last == *start) {
			free(*start);
			*start = NULL;
		}
		else {
			struct neighbour *next = (*start)->previousNeighbour;
			next->nextNeighbour = (*start)->nextNeighbour;
			(next->nextNeighbour)->previousNeighbour = next;
			free(*start);
			*start = next;
		}
	}
}

void neighbour_add_end(struct neighbour **start, struct neighbour *add) {
	if (start != NULL && *start != NULL && add != NULL) {
		struct neighbour *last = (*start)->previousNeighbour;
		add->nextNeighbour = (*start);
		(*start)->previousNeighbour = add;
		add->previousNeighbour = last;
		last->nextNeighbour = add;
	}
}

void neighbour_add_start(struct neighbour **start, struct neighbour *add) {
	if (start != NULL && add != NULL) {
		struct neighbour *last = (*start)->previousNeighbour;
		add->nextNeighbour = *start;
		add->previousNeighbour = last;
		last->nextNeighbour = add;
		(*start)->previousNeighbour = add;
		*start = add;
	}
}

void neighbour_remove(struct neighbour *self, int neighbour) {
	if (self != NULL) {
		
	}
}

bool has_neighbour(struct neighbour *self, int neighbour) {
	if (self != NULL) {
		struct neighbour *node = self;
		struct neighbour *last = self->previousNeighbour;
		while (node != last) {
			if (node->neighbour == neighbour) {
				return true;
			}
		}
	}
	return false;
}

void neighbour_dump(struct neighbour *self, FILE* file) {
	if (self != NULL) {
		struct neighbour *node;
		struct neighbour *last = self->previousNeighbour;
		node = self;
		do {
			printf("%d, ", node->neighbour);
			node = node->nextNeighbour;
		}
		while (node != last);
	}
}

