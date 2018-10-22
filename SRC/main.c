#include "graph.h"
#include "neighbour.h"
#include "menu.h"

//taille d'un buffer pour les entrées de noms de fichiers (sauvegarder ou charger un fichier)
#define BUFSIZE 1024


/*
 * Demande à l'utilisateur les informations pour créer le graphe, et le crée s'il n'y a pas d'erreur
 * Returns : Retourne un pointeur sur le graphe créé
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
			fprintf(stdout, "Voulez-vous que le graphe soit dirigé ? [Y/n]\n");
			scanf("%c", &charDirected);
			if (charDirected != 'Y' && charDirected != 'y' && charDirected != '\n') {
				directed = false;
			}
			graph_create(res, directed, nbNodes);
		}
		else {
			fprintf(stderr, "Erreur dans la création du graphe.\n");
		}
	}
	return res;
}


/*
 * Demande à l'utilisateur les informations pour charger le graphe depuis un fichier.
 * Returns : Retourne un pointeur vers le graphe chargé
 */
struct graph *main_load_graph() {
	char filename[BUFSIZE];
	FILE *file;
	fprintf(stdout, "Entrez le nom du fichier à charger.\n");
	scanf("%s", filename);
	getchar();
	file = fopen(filename, "r");
	//faire le chargement du graphe
	fclose(file);
	return NULL;
}


/*
 * Demande à l'utilisateur les informations pour créer un noeud et le crée s'il n'y a pas d'erreur.
 * Params :	graph	: le graph dans lequel ajouter un noeud
 * Returns : Retourne un booléen, vrai si le noeud a bien été ajouté, faux sinon
 */
bool main_graph_add_node(struct graph *graph) {
	size_t nbNode = 0;
	fprintf(stdout, "Entrez le numéro du noeud que vous voulez ajouter.\n");
	scanf("%zu", &nbNode);
	getchar();
	bool res = graph_create_node(graph, nbNode);
	return res;
}


/*
 * Demande à l'utilisateur les informations pour ajouter une transition et la crée s'il n'y a pas d'erreur.
 * Params :	graph	: le graphe dans lequel ajouter la transition
 * Returns : Retourne un booléen, vrai si la transition a été ajoutée, faux sinon
 */
bool main_graph_add_edge(struct graph *graph) {
	size_t nbNodeSource = 0;
	fprintf(stdout, "Entrez le numéro du noeud source.\n");
	scanf("%zu", &nbNodeSource);
	bool nodeSourceExists = graph_node_exists(graph, nbNodeSource);
	if (!nodeSourceExists) {
		fprintf(stderr, "Le noeud source n'existe pas.\n");
		return false;
	}
	size_t nbNodeDestination = 0;
	fprintf(stdout, "Entrez le numéro du noeud destination.\n");
	scanf("%zu", &nbNodeDestination);
	getchar();
	bool nodeDestinationExists = graph_node_exists(graph, nbNodeDestination);
	if (!nodeDestinationExists) {
		fprintf(stderr, "Le noeud destination n'existe pas.\n");
		return false;
	}
	int weight = 0;
	fprintf(stdout, "Entrez le poids de la transition.\n");
	scanf("%d", &weight);
	getchar();
	bool symetrique = !graph->isDirected;
	if (!symetrique) {
		char charSymetrique = 'Y';
		fprintf(stdout, "La transition est-elle symétrique ? [Y/n]\n");
		scanf("%c", &charSymetrique);
		if (charSymetrique == 'Y' || charSymetrique == 'y' || charSymetrique == '\n') {
			symetrique = true;
		}
	}
	graph_add_edge(graph, nbNodeSource, nbNodeDestination, weight, symetrique);
	return true;
}


/*
 * Demande à l'utilisateur les informations pour supprimer un noeud et le supprime s'il existe.
 * Params :	graph	: le graphe dans lequel supprimer le noeud
 * Returns : Retourne un booléen, vrai si la suppression a été effectuée, faux sinon
 */
bool main_graph_remove_node(struct graph *graph) {
	size_t nbNode = 0;
	fprintf(stdout, "Entrez le numéro du noeud à supprimer.\n");
	scanf("%zu", &nbNode);
	getchar();
	bool nodeExists = graph_node_exists(graph, nbNode);
	if (!nodeExists) {
		fprintf(stderr, "Le noeud %zu n'existe pas.\n", nbNode);
		return false;
	}
	graph_remove_node(graph, nbNode);
	return true;
}


/*
 * Demande à l'utilisateur les informations pour supprimer une transition et la supprime si elle existe.
 * Params :	graph	: le graphe dans lequel supprimer la transition
 * Returns : Retourne un booléen, vrai si la suppression a été effectuée, faux sinon
 */
bool main_graph_remove_edge(struct graph *graph) {
	size_t nbNodeSource = 0, nbNodeDestination = 0;
	fprintf(stdout, "Entrez le numéro du noeud source de la transition.\n");
	scanf("%zu", &nbNodeSource);
	getchar();
	bool nodeSourceExists = graph_node_exists(graph, nbNodeSource);
	if (!nodeSourceExists) {
		fprintf(stderr, "Le noeud source n'existe pas.\n");
		return false;
	}
	fprintf(stdout, "Entrez le numéro du noeud source de la transition.\n");
	scanf("%zu", &nbNodeDestination);
	getchar();
	bool nodeDestinationExists = graph_node_exists(graph, nbNodeDestination);
	if (!nodeDestinationExists) {
		fprintf(stderr, "Le noeud desination n'existe pas.\n");
		return false;
	}
	bool symetrique = !graph->isDirected;
	if (!symetrique) {
		char charSymetrique = 'Y';
		fprintf(stdout, "La transition est-elle symétrique ? [Y/n]\n");
		scanf("%c", &charSymetrique);
		if (charSymetrique == 'Y' || charSymetrique == 'y' || charSymetrique == '\n') {
			symetrique = true;
		}
	}
	graph_remove_edge(graph, nbNodeSource, nbNodeDestination, symetrique);
	return true;
}


/*
 * Affiche un graphe sur la sortie standard du terminal.
 * Params : 	graph	: le graphe à afficher
 */
void main_view_graph(struct graph *graph) {
	graph_dump(graph, stdout);
}


/*
 * Sauvegarde un graphe dans un fichier (le nom du fichier est entré par l'utilisateur)
 * Params :	graph	: le graph à sauvegarder
 */
void main_save_graph(struct graph *graph) {
	char filename[BUFSIZE];
	FILE *file;
	fprintf(stdout, "Entrez le nom de fichier pour sauvegarder le graph\n");
	scanf("%s", filename);
	file = fopen(filename, "w");
	if (file != NULL) {
		graph_dump(graph, file);
		fclose(file);
	}
	else {
		fprintf(stderr, "Le fichier n'a pas pu être ouvert.\n");
	}
}


int main(int argc, char **argv) {
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
					fprintf(stdout, "Création du graphe réussie.\n");
					global_menu_activate_main_menu(&testMenu);
				}
				break;
			case COMMAND_CODE_LOAD :
				fprintf(stderr, "Non implémenté");
				break;
			case COMMAND_CODE_ADD_NODE :
				main_graph_add_node(main_graph);
				break;
			case COMMAND_CODE_ADD_EDGE :
				main_graph_add_edge(main_graph);
				break;
			case COMMAND_CODE_REMOVE_NODE :
				main_graph_remove_node(main_graph);
				break;
			case COMMAND_CODE_REMOVE_EDGE :
				main_graph_remove_edge(main_graph);
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



