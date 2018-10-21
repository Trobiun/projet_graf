#include "neighbour.h"


void neighbour_create(struct neighbour *self, int neighbour, int weight) {
	if (self != NULL) {
		self->neighbour = neighbour;
		self->weight = weight;
		self->nextNeighbour = NULL;
		self->previousNeighbour = NULL;
	}
}

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

void neighbour_add_start(struct neighbour **start, struct neighbour *add) {
	if (start != NULL && *start != NULL && add != NULL) {
		struct neighbour *last = (*start)->previousNeighbour;
		add->nextNeighbour = *start;
		add->previousNeighbour = last;
		last->nextNeighbour = add;
		(*start)->previousNeighbour = add;
		*start = add;
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

void neighbour_remove(struct neighbour *self, int nbNode) {
	if (self != NULL) {
		struct neighbour *node = self;
		while (node->neighbour > -1) {
			if (node->neighbour == nbNode) {
				node->nextNeighbour->previousNeighbour = node->previousNeighbour;
				node->previousNeighbour->nextNeighbour = node->nextNeighbour;
				neighbour_destroy_start(&node);
				free(node);
			}
			node = node->nextNeighbour;
		}
	}
}

bool has_neighbour(struct neighbour *self, int neighbour) {
	if (self != NULL) {
		struct neighbour *node = self;
		while (node->neighbour > -1) {
			if (node->neighbour == neighbour) {
				return true;
			}
			node = node->nextNeighbour;
		}
	}
	return false;
}

void neighbour_dump(struct neighbour *self, FILE* file) {
	if (self != NULL) {
		struct neighbour *node;
		node = self;
		while (node->neighbour != -1) {
			fprintf(file, "(%d/%d)", self->neighbour, node->weight);
			node = node->nextNeighbour;
			if (node->neighbour > -1) {
				fprintf(file, ", ");
			}
		}
	}
}

