#include "graph.h"
#include "neighbour.h"
#include "menu.h"

#define BUFSIZE 1024

struct graph *main_create_graph() {
	size_t nbNodes =  0;
	printf("Entrez le nombre maximal de noeuds pour le graph\n");
	scanf("%zu",&nbNodes);
	struct graph *res = NULL;
	if (nbNodes > 0) {
		res = malloc(sizeof(struct graph));
		if (res != NULL) {
			graph_create(res, false, nbNodes);
		}
	}
	return res;
}

void main_view_graph(struct graph *graph) {
	graph_dump(graph, stdout);
}

void main_save_graph(struct graph *graph) {
	printf("Entrez le nom de fichier pour sauvegarder le graph\n");
	char buffer[BUFSIZE];
	scanf("%s", buffer);
	FILE *file = fopen(buffer, "w");
	graph_dump(graph, file);
	fclose(file);
}


int main(int argc, char **argv) {
// 	struct graph *main_graph = malloc(sizeof(struct graph));
// 	create_graph(main_graph, false, 10);
// 	graph_add_neighbour(main_graph, 0, 1, 0);
// 	graph_add_neighbour(main_graph, 0, 2, 0);
// 	graph_add_neighbour(main_graph, 0, 3, 0);
// 	
// // 	save_graph(&test);
// // 	graph_dump(main_graph, stdout);
// 	graph_destroy(main_graph);
// 	free(main_graph);
// 	return 0;
	struct graph *main_graph = NULL;
	struct global_menu testMenu;
	global_menu_create(&testMenu);
	testMenu.selectedOption = 0;
	do {
		global_menu_show(&testMenu);
		switch(testMenu.selectedOption) {
			case COMMAND_CODE_CREATE :
				main_graph = main_create_graph();
				if (main_graph == NULL) {
					fprintf(stderr, "Échec dans la création du graphe\n");
				}
				else {
					
				}
				break;
			case COMMAND_CODE_LOAD :
				printf("Non implémenté");
				break;
			case COMMAND_CODE_ADD_NODE :
				printf("Non implémenté");
				break;
			case COMMAND_CODE_ADD_EDGE :
				printf("Non implémenté");
				break;
			case COMMAND_CODE_REMOVE_NODE :
				printf("Non implémenté");
				break;
			case COMMAND_CODE_REMOVE_EDGE :
				printf("Non implémenté");
				break;
			case COMMAND_CODE_VIEW_GRAPH :
				main_view_graph(main_graph);
				break;
			case COMMAND_CODE_SAVE_GRAPH :
				main_save_graph(main_graph);
				break;
			
		}
	} while (testMenu.selectedOption != COMMAND_CODE_QUIT);
	if (main_graph != NULL) {
		graph_destroy(main_graph);
		free(main_graph);
	}
	global_menu_destroy(&testMenu);
	return 0;
}

