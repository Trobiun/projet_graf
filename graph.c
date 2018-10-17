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

// void graph_destroy(struct graph *self) {
// 	for (size_t i = 0; i < self->nbMaxNodes; i++) {
// 		
// 	}
// 	free(self->adjList);
// }

void graph_add_neighbour(struct graph *self, size_t nbNode, int neighbour, int weight) {
	struct neighbour *add = malloc(sizeof(struct neighbour));
	neighbour_create(add, neighbour, weight);
	if (self->adjList[nbNode] == NULL) {
		struct neighbour *sentinel = malloc(sizeof(struct neighbour));
		neighbour_create(sentinel, -1, 0);
		neighbour_add_front(add, sentinel);
		self->adjList[nbNode] = add;
	}
	else {
		neighbour_add_front(self->adjList[nbNode],add);
	}
}
