#include "neighbour.h"

void neighbour_create(struct neighbour *self, int neighbour, int weight) {
	self->neighbour = neighbour;
	self->weight = weight;
	self->nextNeighbour = NULL;
	self->previousNeighbour = NULL;
}

void neighbour_destroy(struct neighbour *self) {
	if (self->nextNeighbour != NULL) {
		neighbour_destroy(self->nextNeighbour);
	}
	if (self->previousNeighbour != NULL) {
		neighbour_destroy(self->previousNeighbour);
	}
}

