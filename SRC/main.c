#include "graph.h"
#include "neighbour.h"
#include "menu.h"

#define BUFSIZE 1024

/*
 * 
 */
struct graph *main_create_graph() {
	struct graph *res = NULL;
	size_t nbNodes =  0;
	bool directed = true;
	char charDirected = 'Y';
	fprintf(stdout, "Entrez le nombre maximal de noeuds pour le graph\n");
	scanf("%zu",&nbNodes);
	getchar();
	if (nbNodes > 0) {
		res = malloc(sizeof(struct graph));
		if (res != NULL) {
			fprintf(stdout, "Voulez-vous que le graphe soit dirigé ? [Y/n]");
			scanf("%c", &charDirected);
			if (charDirected != 'Y' && charDirected != 'y' && charDirected != '\n') {
				directed = false;
			}
// 			if (directed) {
// 				printf("true");
// 			}
// 			else {
// 				printf("false");
// 			}
			graph_create(res, directed, nbNodes);
		}
		else {
			fprintf(stderr, "Erreur dans la création du graphe.\n");
		}
	}
	return res;
}

struct graph *main_load_graph() {
	char filename[BUFSIZE];
	FILE *file;
	fprintf(stdout, "Entrez le nom du fichier à charger.\n");
	scanf("%s", filename);
	file = fopen(filename, "r");
	//faire le chargement du graphe
	fclose(file);
	return NULL;
}

bool main_graph_add_node(struct graph *graph) {
	size_t nbNode = 0;
	fprintf(stdout, "Entrez le numéro du noeud que vous voulez ajouter.\n");
	scanf("%zu", &nbNode);
	bool res = graph_create_node(graph, nbNode);
	return res;
}

bool main_graph_add_edge(struct graph *graph) {
	size_t nbNodeSource = 0;
	fprintf(stdout, "Entrez le numéro du noeud source.\n");
	scanf("%zu", &nbNodeSource);
	bool nodeSourceExists = graph_node_exists(graph, nbNodeSource);
	if (!nodeSourceExists) {
		fprintf(stderr, "Le noeud source n'existe pas.");
		return false;
	}
	size_t nbNodeDestination = 0;
	fprintf(stdout, "Entrez le numéro du noeud destination.\n");
	scanf("%zu", &nbNodeDestination);
	bool nodeDestinationExists = graph_node_exists(graph, nbNodeDestination);
	if (!nodeDestinationExists) {
		fprintf(stderr, "Le noeud destination n'existe pas.");
		return false;
	}
	graph_add_edge(graph, nbNodeSource, nbNodeDestination , 1);
	return true;
}

void main_view_graph(struct graph *graph) {
	graph_dump(graph, stdout);
}

void main_save_graph(struct graph *graph) {
	char filename[BUFSIZE];
	FILE *file;
	fprintf(stdout, "Entrez le nom de fichier pour sauvegarder le graph\n");
	scanf("%s", filename);
	file = fopen(filename, "w");
	graph_dump(graph, file);
	fclose(file);
}


int main(int argc, char **argv) {
// 	struct graph *main_graph = malloc(sizeof(struct graph));
// 	graph_create(main_graph, false, 10);
// 	graph_create_neighbour(main_graph, 1);
// 	graph_create_neighbour(main_graph, 2);
// 	graph_create_neighbour(main_graph, 3);
// 	graph_add_neighbour(main_graph, 1, 1, 0);
// 	graph_add_neighbour(main_graph, 1, 2, 0);
// 	graph_add_neighbour(main_graph, 1, 3, 0);
// 	
// // 	save_graph(&test);
// 	graph_dump(main_graph, stdout);
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
					fprintf(stderr, "Échec dans la création du graphe.\n");
				}
				else {
					fprintf(stdout, "Création du graphe avec réussite.\n");
					global_menu_activate_main_menu(&testMenu);
				}
				break;
			case COMMAND_CODE_LOAD :
				printf("Non implémenté");
				break;
			case COMMAND_CODE_ADD_NODE :
				main_graph_add_node(main_graph);
// 				printf("Non implémenté");
				break;
			case COMMAND_CODE_ADD_EDGE :
				main_graph_add_edge(main_graph);
// 				printf("Non implémenté");
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

