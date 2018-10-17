#ifndef NEIGHBOUR_H
#define NEIGHBOUR_H

#include <stdlib.h>
#include <stdbool.h>

struct neighbour {
	int neighbour;
	int weight;
	struct neighbour* nextNeighbour;
	struct neighbour* previousNeighbour;
};

void neighbour_create(struct neighbour *self, int neighbour, int weight);

void neighbour_destroy(struct neighbour *self);

void neighbour_add_back(struct neighbour *self, struct neighbour *add);

void neighbour_add_front(struct neighbour *self, struct neighbour *add);

void neighbour_remove(struct neighbour *self, int remove);

bool has_neighbour(struct neighbour *self);

void neighbour_dump(struct neighbour *self);


#endif // NEIGHBOUR_H
