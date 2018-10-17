#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "neighbour.h"

struct graph {
	bool isDirected;
	size_t nbMaxNodes;
	struct neighbour **adjList;
};

void create_graph(struct graph *self, bool isDirected, size_t nbMaxNodes);

void graph_destroy(struct graph *self);

void graph_add_neighbour(struct graph *self, size_t nbNode, int neighbour, int weight);

#endif // GRAPH_H
