#include "graph.h"
#include "neighbour.h"

int main(int argc, char **argv) {
	struct graph test;
	create_graph(&test, false, 10);
	graph_add_neighbour(&test, 0, 1, 0);
	graph_add_neighbour(&test, 0, 2, 0);
	graph_add_neighbour(&test, 0, 3, 0);
	graph_dump(&test);
	graph_destroy(&test);
// 	struct neighbour node;
// 	neighbour_create(&node, 1, 1);
	return 0;
}
