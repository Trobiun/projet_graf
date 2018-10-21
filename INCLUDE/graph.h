#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "neighbour.h"

struct graph {
	bool isDirected;
	size_t nbMaxNodes;
	struct neighbour **adjList;
};

void graph_create(struct graph *self, bool isDirected, size_t nbMaxNodes);

void graph_destroy(struct graph *self);

bool graph_is_valid_nb_node(struct graph *self, size_t nbNode);

bool graph_node_exists(struct graph *self, size_t nbNode);

bool graph_create_node(struct graph *self , size_t nbNode);

void graph_add_edge(struct graph *self, size_t nbNode, size_t neighbour, int weight);

void graph_dump(struct graph *self, FILE* file);

#endif // GRAPH_H
