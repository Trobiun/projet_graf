#include "graph.h"
#include "list.h"
#include "neighbour.h"

int main(int argc, char **argv) {
	struct graph test;
	create_graph(&test, false, 10);
	struct neighbour node;
	neighbour_create(&node, 1, 1);
	return 0;
}
