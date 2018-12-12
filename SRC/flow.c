#include <stdio.h>
#include <stdlib.h>
#include "flow.h"
#include "queue.h"

void create_flows(struct flows *self, struct graph *origin, struct graph *residual, int source, int sink) {
	if (self != NULL) {
		self->originalFlow = origin;
		self->residualNetwork = residual;
		self->sourceState = source;
		self->sinkState = sink;
	}
}

void destroy_flows(struct flows *self) {
	graph_destroy(self->originalFlow);
	free(self->originalFlow);
	graph_destroy(self->residualNetwork);
	free(self->residualNetwork);
}

void initialize_matrix(struct flows *self) {
	struct graph *gr = self->originalFlow;
	for (int i = 0; i < gr->nbMaxNodes; i++) {
		for (int j = 0; j <gr->nbMaxNodes; j++) {
			
		}
	}
}

void bfs(struct graph *gr, int start, int target) {
	int u, v;
	for (u = 0; u < gr->nbMaxNodes; u++) {
		
	}
}
