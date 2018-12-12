#ifndef FLOW_H
#define FLOW_H

#include "graph.h"

struct flows {
	struct graph *originalFlow;
	struct graph *residualNetwork;
	int sourceState;
	int sinkState;
	int **matrix;
};

void create_flows(struct flows *self, struct graph *origin, struct graph *residual, int source, int sink);

void destroy_flows(struct flows *self);

void initialize_matrix(struct flows *self);

void bfs(struct graph *gr, int start, int target);


#endif // FLOW_H
