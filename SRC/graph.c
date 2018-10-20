#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void graph_create(struct graph *self, bool isDirected, size_t nbMaxNodes) {
	if (self != NULL) {
		self->isDirected = isDirected;
		self->nbMaxNodes = nbMaxNodes;
		self->adjList = calloc(self->nbMaxNodes, sizeof(struct neighbour *));
		for (size_t i = 0; i < self->nbMaxNodes; i++) {
			self->adjList[i] = NULL;
		}
	}
}

void graph_destroy(struct graph *self) {
	if (self != NULL) {
		for (size_t i = 0; i < self->nbMaxNodes; i++) {
			while (self->adjList[i] != NULL) {
				neighbour_destroy_start(&self->adjList[i]);
			}
		}
		free(self->adjList);
	}
}

void graph_add_neighbour(struct graph *self, size_t nbNode, int neighbour, int weight) {
	if (self != NULL) {
		struct neighbour *add = malloc(sizeof(struct neighbour));
		neighbour_create(add, neighbour, weight);
		if (self->adjList[nbNode] == NULL) {
			struct neighbour *sentinel = malloc(sizeof(struct neighbour));
			neighbour_create(sentinel, -1, -1);
			sentinel->nextNeighbour = add;
			sentinel->previousNeighbour = add;
			add->nextNeighbour = sentinel;
			add->previousNeighbour = sentinel;
			neighbour_add_end(&add, sentinel);
			self->adjList[nbNode] = add;
		}
		else {
			neighbour_add_end(self->adjList + nbNode, add);
		}
	}
}

void graph_dump(struct graph *self, FILE* file) {
	if (self != NULL && file != NULL) {
		fprintf(file, "# maximum number of nodes\n%zu\n", self->nbMaxNodes);
		fprintf(file, "# directed\n");
		if (self->isDirected) {
			fprintf(file, "y");
		}
		else {
			fprintf(file, "n");
		}
		fprintf(file, "\n# nodes: neighbours\n");
		size_t i;
		for (i = 0; i < self->nbMaxNodes; i++) {
			fprintf(file, "%zu: ", i);
			if (self->adjList[i] != NULL) {
				neighbour_dump(self->adjList[i], file);
			}
			fprintf(file, "\n");
		}
	}
}









