#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void create_graph(struct graph *self) {
	array_create(&self->adjList);
}

void graph_destroy(struct graph *self) {
	array_destroy(&self->adjList);
}
