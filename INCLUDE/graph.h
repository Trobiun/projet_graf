#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "array.h"

struct neighbour;

struct graph {
	bool isDirected;
	size_t nbMaxNodes;
	struct array adjList;
}

void create_graph(struct graph *self);

void graph_destroy(struct graph *self);


#endif // GRAPH_H
