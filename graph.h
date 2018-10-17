#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "array.h"
#include "neighbour.h"

struct graph {
	bool isDirected;
	size_t nbMaxNodes;
	struct neighbour *adjList;
};

void create_graph(struct graph *self, bool isDirected, size_t nbMaxNodes);

void graph_destroy(struct graph *self);


#endif // GRAPH_H
