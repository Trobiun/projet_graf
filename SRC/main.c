#include "graph.h"
#include "neighbour.h"
#include "menu.h"

int main(int argc, char **argv) {
// 	int choix = 0;
	struct graph test;
	create_graph(&test, false, 10);
	graph_add_neighbour(&test, 0, 1, 0);
	graph_add_neighbour(&test, 0, 2, 0);
	graph_add_neighbour(&test, 0, 3, 0);
// 	graph_dump(&test);
	graph_destroy(&test);
	
	struct global_menu testMenu;
	global_menu_create(&testMenu);
	menu_show(testMenu.firstMenu);
	global_menu_destroy(&testMenu);
	
	return 0;
}

