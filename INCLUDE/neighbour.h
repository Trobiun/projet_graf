#ifndef NEIGHBOUR_H
#define NEIGHBOUR_H

#include "list.h"

struct neighbour {
	int neighbour;
	int weight;
	struct list_node* nextNeighbour;
	struct list_node* previousNeighbour;
};

void neighbour_create(struct neighbour *self, int neighbour, int weight);

void neighbour_destroy(struct neighbour *self);




#endif // NEIGHBOUR_H
