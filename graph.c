#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void create_graph(struct graph *self, bool isDirected, size_t nbMaxNodes) {
	self->isDirected = isDirected;
	self->nbMaxNodes = nbMaxNodes;
	self->adjList[self->nbMaxNodes];
	for (size_t i = 0; i < self->nbMaxNodes; i++) {
		self->adjList[i] = NULL;
	}
}

void graph_destroy(struct graph *self) {
	
}

void graph_add(struct neighbour *self, size_t nbNodes, int neighbour, int weight) {
	struct neighbour *add = malloc(sizeof(struct neighbour));
	neighbour_create(add, neighbour, weight);
	if (self->adjList[i] == NULL) {
		struct neighbour *sentinel = malloc(sizeof(struct neighbour));
		neighbour_create(sentinel, -1, 0);
		neighbour_create(add, neighbour, weight);
		neighbour_add_front(add, sentinel);
		self->adjList[i] = add;
	}
}
