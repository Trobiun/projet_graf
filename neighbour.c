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

void neighbour_add_back(struct neighbour **self, int neighbour, int weight) {
	if (self == NULL) {
		/*struct neighbour *ajout = malloc(sizeof(struct neighbour));
		ajout->neighbour = neighbour;
		ajout->weight = weight;
		ajout->nextNeighbour = ajout;
		ajout->previousNeighbour = ajout;
		*self = ajout;*/
	}
	else {
		struct neighbour *last = (*self)->previousNeighbour;
		struct neighbour *ajout = malloc(sizeof(struct neighbour));
		if (ajout != NULL) {
			ajout->neighbour = neighbour;
			ajout->weight = weight;
			
			(*self)->nextNeighbour = ajout;
			
			ajout->nextNeighbour = *self;
			ajout->previousNeighbour = last;
			
			last->nextNeighbour = ajout;
		}
	}
}

void neighbour_add_front(struct neighbour *self, int neighbour, int weight) {
	if (self != NULL) {
		struct neighbour *ajout = malloc(sizeof(struct neighbour));
		ajout->weight = weight;
		ajout->neighbour = neighbour;
	}
}

void neighbour_remove(struct neighbour *self, int value) {
	if (self != NULL) {
		
	}
}

bool has_neighbour(struct neighbour *self) {
	if (self != NULL) {
		
	}
}

void neighbour_dump(struct neighbour *self) {
	if (self != NULL) {
		
	}
}
