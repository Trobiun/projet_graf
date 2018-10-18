#ifndef NEIGHBOUR_H
#define NEIGHBOUR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct neighbour {
	int neighbour;
	int weight;
	struct neighbour* nextNeighbour;
	struct neighbour* previousNeighbour;
};

void neighbour_create(struct neighbour *self, int neighbour, int weight);

// void neighbour_destroy(struct neighbour *self);

void neighbour_destroy_start(struct neighbour **start);

void neighbour_add_end(struct neighbour **end, struct neighbour *add);

void neighbour_add_start(struct neighbour **start, struct neighbour *add);

void neighbour_remove(struct neighbour *self, int remove);

bool has_neighbour(struct neighbour *self);

void neighbour_dump(struct neighbour *self);


#endif // NEIGHBOUR_H
