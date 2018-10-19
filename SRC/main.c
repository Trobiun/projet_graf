#include "graph.h"
#include "neighbour.h"
#include "menu.h"

struct graph *main_create_graph() {
	size_t nbNodes =  0;
	printf("Entrez le nombre maximal de noeuds pour le graph\n");
	scanf("%zu",&nbNodes);
	if (nbNodes > 0) {
		struct graph *res = malloc(sizeof(struct graph));
		return res;
	}
	return NULL;
}

void main_view_graph(struct graph *graph) {
	graph_dump(graph, stdout);
}

void main_save_graph(struct graph *graph) {
	char buffer[BUFSIZ];
	scanf("%s", buffer);
	FILE *file = fopen(buffer, "w");
	graph_dump(graph, file);
	fclose(file);
}


int main(int argc, char **argv) {
	struct graph *main_graph = NULL;
// 	create_graph(&main_graph, false, 10);
// 	graph_add_neighbour(&main_graph, 0, 1, 0);
// 	graph_add_neighbour(&main_graph, 0, 2, 0);
// 	graph_add_neighbour(&main_graph, 0, 3, 0);
	
// 	save_graph(&test);
// 	graph_dump(&test, stdout);
	
	struct global_menu testMenu;
	global_menu_create(&testMenu);
	testMenu.selectedOption = 0;
	do {
		global_menu_show(&testMenu);
// 		switch(testMenu.selectedOption) {
// 			case COMMAND_CODE_CREATE :
// 				main_graph = main_create_graph();
// 				if (main_graph == NULL) {
// 					fprintf(stderr, "Échec dans la création du graphe\n");
// 				}
// 				break;
// 				
// 		}
	} while (testMenu.selectedOption != COMMAND_CODE_QUIT);
	if (main_graph != NULL) {
		graph_destroy(main_graph);
	}
	global_menu_destroy(&testMenu);
	return 0;
}

