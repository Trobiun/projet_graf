#ifndef NEIGHBOUR_H
#define NEIGHBOUR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//structure d'un élément dans la liste chaînée
struct neighbour {
	int neighbour;
	int weight;
	struct neighbour* nextNeighbour;
	struct neighbour* previousNeighbour;
};


/*
 * Initialise une structure de type neighbour avec comme voisin 'neighbour' et comme poids de transition 'weight'.
 * Params :	self		: un pointeur vers une structure neighbour à initialiser
 * 			neighbour	: le noeud destination de la transition
 * 			weight		: le poids de la transition entre le noeud self et le noeud neighbour
 */
void neighbour_create(struct neighbour *self, int neighbour, int weight);

/*
 * Détruit le noeud start (en début de liste).
 * Params :	start	: le noeud à détruire
 */
void neighbour_destroy_start(struct neighbour **start);

/*
 * Ajoute un noeud au début de la liste chaînée.
 * Params :	start	: le pointeur du pointeur du début de liste
 * 			add		: le pointeur vers la structure neighbour à ajouter en fin de liste
 */
void neighbour_add_start(struct neighbour **start, struct neighbour *add);

/*
 * Ajoute un noeud à la fin de la liste chaînée.
 * Params :	start	: le pointeur vers le pointeur du début de liste
 * 			add		: le pointeur vers la structure neighbour à ajouter en fin de liste
 */
void neighbour_add_end(struct neighbour **start, struct neighbour *add);

/*
 * Supprime un noeud dans une liste chaînée
 * Params :	self	: le pointeur vers la structure de type neighbour auquel il faut supprimer un noeud
 * 			nbNode	: le numéro du noeud à supprimer dans la liste chaînée
 */
void neighbour_remove(struct neighbour *self, int nbNode);

/*
 * Vérifie si un noeud est déjà présent dans une liste chaînée.
 * Params :	self		: le pointeur vers la structure de type neighbour sur lequel vérifier la présence du noeud
 * 			neighbour	: le numéro du noeud à vérifier la présence
 * Returns : Retourne un booléen, vrai si le noeud 'neighbour' est déjà la liste chaînée 'self', faux sinon
 */
bool has_neighbour(struct neighbour *self, int neighbour);

/*
 * Affiche une liste chaînée.
 * Params :	self	: la structure de la liste chaînée à afficher
 * 			file	: le fichier dans lequel afficher la liste (par exemple stdout, ou un fichier pour sauvegarder)
 */
void neighbour_dump(struct neighbour *self, FILE* file);


#endif // NEIGHBOUR_H
