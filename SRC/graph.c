#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


size_t nb_node_to_index(size_t nbNode) {
	if (nbNode > 0) {
		return nbNode - 1;
	}
	return 0;
}

size_t index_to_nb_node(size_t index) {
	return index + 1;
}

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

bool graph_node_is_valid_nb(struct graph *self, size_t nbNode) {
	bool res = false;
	if (self != NULL) {
		res = nbNode >= 0 && nbNode < self->nbMaxNodes;
	}
	return res;
}

bool graph_node_is_valid_index(struct graph *self, size_t indexNode) {
	bool res = false;
	if (self != NULL) {
		res = indexNode >= 0 && indexNode < self->nbMaxNodes;
	}
	return res;
}

bool graph_node_exists(struct graph *self, size_t nbNode) {
	size_t indexNode = nb_node_to_index(nbNode);
	return graph_node_is_valid_nb(self, nbNode) && self->adjList[indexNode] != NULL;
}

bool graph_node_exists_index(struct graph *self, size_t indexNode) {
	return graph_node_is_valid_index(self, indexNode) && self->adjList[indexNode] != NULL;
}

bool graph_create_node(struct graph *self, size_t nbNode) {
	size_t indexNode = nb_node_to_index(nbNode);
	if (self != NULL && graph_node_is_valid_index(self, indexNode) && self->adjList[indexNode] == NULL) {
		struct neighbour *sentinel = malloc(sizeof(struct neighbour));
		neighbour_create(sentinel, -1, -1);
		sentinel->nextNeighbour = sentinel;
		sentinel->previousNeighbour = sentinel;
		self->adjList[indexNode] = sentinel;
		return true;
	}
	return false;
}

bool graph_add_edge(struct graph *self, size_t nbNodeSource, size_t nbNodeDestination, int weight) {
	size_t indexNodeSource = nb_node_to_index(nbNodeSource);
	size_t indexNodeDest = nb_node_to_index(nbNodeDestination);
	if (self != NULL) {
		if (graph_node_exists_index(self, indexNodeSource) && graph_node_exists_index(self, indexNodeDest)) {
			if (self->adjList != NULL) {
				//ajoute le neighbour seulement s'il n'est pas déjà présent
				if (!has_neighbour(self->adjList[indexNodeSource], nbNodeDestination)) {
					struct neighbour *add = malloc(sizeof(struct neighbour));
					neighbour_create(add, nbNodeDestination, weight);
// 					if (self->adjList[nbNode] == NULL) {
// 						struct neighbour *sentinel = malloc(sizeof(struct neighbour));
// 						neighbour_create(sentinel, -1, -1);
// 						sentinel->nextNeighbour = add;
// 						sentinel->previousNeighbour = add;
// 						add->nextNeighbour = sentinel;
// 						add->previousNeighbour = sentinel;
// 						neighbour_add_end(&add, sentinel);
// 						self->adjList[nbNode] = add;
// 					}
// 					else {
						neighbour_add_start(self->adjList + indexNodeSource, add);
						return true;
// 					}
				}
			}
		}
	}
	return false;
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
		size_t index;
		for (index = 0; index < self->nbMaxNodes; index++) {
			if (self->adjList[index] != NULL) {
				fprintf(file, "%zu: ", index_to_nb_node(index));
				neighbour_dump(self->adjList[index], file);
				fprintf(file, "\n");
			}
		}
	}
}









