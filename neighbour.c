#include "neighbour.h"

void neighbour_create(struct neighbour *self, int neighbour, int weight) {
	self->neighbour = neighbour;
	self->weight = weight;
	self->nextNeighbour = NULL;
	self->previousNeighbour = NULL;
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

void neighbour_add_end(struct neighbour **end, struct neighbour *add) {
	if (end == NULL) {
// 		struct neighbour *ajout = malloc(sizeof(struct neighbour));
// 		ajout->neighbour = neighbour;
// 		ajout->weight = weight;
// 		ajout->nextNeighbour = ajout;
// 		ajout->previousNeighbour = ajout;
// 		*self = ajout;
		
	}
	else {
		struct neighbour *last = (*end)->previousNeighbour;
// 		struct neighbour *ajout = malloc(sizeof(struct neighbour));
// 		if (ajout != NULL) {
// 			ajout->neighbour = neighbour;
// 			ajout->weight = weight;
			
			(*end)->nextNeighbour = add;
			
			add->nextNeighbour = (*end);
			add->previousNeighbour = last;
			
			last->nextNeighbour = add;
// 		}
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

bool has_neighbour(struct neighbour *self) {
	if (self != NULL) {
		
	}
}

void neighbour_dump(struct neighbour *self) {
	struct neighbour *node;
	if (self != NULL) {
		node = self;
		do {
			printf("%d, ", node->neighbour);
			node = node->nextNeighbour;
		}
		while (node->neighbour != -1);
	}
}
