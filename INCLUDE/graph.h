#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "neighbour.h"


struct graph {
	bool isDirected;
	size_t nbMaxNodes;
	struct neighbour **adjList;
};


/*
 * 'Convertit' un numéro de node en son équivalent en indice d'un tableau
 * Params : 	nbNode	: le numéro de noeud
 * Returns : Retourne l'indice dans lequel est censé se trouver le noeud qui a pour numéro 'nbNode' ou -1 en cas d'erreur
 */
int nb_node_to_index(size_t nbNode);


/*
 * 'Convertit' un indice en son équivalent en numéro de noeud
 * Params : 	index	: l'indice du noeud dans le tableau
 * Returns : Retourne le numéro de noeud qui a pour indice 'index'
 */
size_t index_to_nb_node(size_t index);


/*
 * Initialise un graphe dirigé ou non, et avec un nombre maximum de noeuds
 * Params :	self		: le graphe à initialiser
 * 			isDirected	: booléen pour déterminer si le graphe est dirigé ou non
 * 			nbMaxNodes	: le nombre maximum de noeuds que pourra avoir le graphe
 */
void graph_create(struct graph *self, bool isDirected, size_t nbMaxNodes);


/*
 * Détruit un noeud dans un graphe.
 * Params :	self		: le graphe dans lequel supprimer un noeud (donc la liste chaînée correspondante)
 * 			indexNode	: l'indice du noeud à supprimer
 */
void graph_destroy_node_index(struct graph *self, size_t indexNode);


/*
 * Détruit un graphe.
 * Params : 	self	: le graphe à détruire
 */
void graph_destroy(struct graph *self);


/*
 * Détermine si un numéro de noeud est valide dans un graphe.
 * Params :	self	: le graphe dans lequel vérifier le numéro de noeud
 * 			nbNode	: le numéro du noeud à vérifier dans le graphe
 * Returns : Retourne un booléen, vrai si le numéro du noeud est valide, faux sinon
 */
bool graph_node_is_valid_nb(struct graph *self, size_t nbNode);


/*
 * Détermine si un indice de noeud est valide dans un graphe.
 * Params :	self		: le graphe dans lequel vérifier le numéro de noeud
 * 			indexNoe	: l'indice du noeud à vérifier dans le graphe
 * Returns : Retourne un booléen, vrai si l'indice du noeud est valide, faux sinon
 */
bool graph_node_is_valid_index(struct graph *self, size_t indexNode);


/*
 * Détermine si un noeud existe dans un graphe.
 * Params :	self	: le graphe dans lequel vérifier l'existence du noeud
 * 			nbNode	: le numéro du noeud à vérifier dans le graphe
 * Returns : Retourne un booléen, vrai si le noeud existe, faux sinon
 */
bool graph_node_exists(struct graph *self, size_t nbNode);


/*
 * Détermine si un indice de noeud existe dans un graphe.
 * Params :	self		: le graphe dans lequel vérifier l'existence du noeud
 * 			indexNode	: l'indice du noeud à vérifier dans le graphe
 * Returns : Retourne un booléen, vrai si le noeud existe, faux sinon
 */
bool graph_node_exists_index(struct graph *self, size_t indexNode);


/*
 * Crée un noeud (s'il n'est pas déjà présent) dans un graphe.
 * Params :	self	: le graphe dans lequel créer le noeud
 * 			nbNode	: le numéro du noeud à créer
 * Returns : Retourn un booléen, vrai si le noeud a été ajouté, faux sinon
 */
bool graph_create_node(struct graph *self , size_t nbNode);


/*
 * Ajoute une transition entre deux noeuds (si elle n'est pas déjà présente) dans un graphe.
 * Params :	self				: le graphe dans lequel ajouter une transition
 * 			nbNodeSource		: le numéro du noeud source
 * 			nbNodeDesination	: le numéro du noeud destination
 * 			weight				: le poids de la transition
 * 			symetrique			: booléen qui détermine si la transition est symétrique ou non
 * Returns : Retourne un booléen, vrai si la transition a été ajoutée, faux sinon
 */
bool graph_add_edge(struct graph *self, size_t nbNodeSource, size_t nbNodeDesination, int weight, bool symetrique);


/*
 * Supprime un noeud dans un graphe.
 * Params :	self	: le graphe auquel supprimer un noeud
 * 			nbNode	: le numéro du noeud à supprimer
 */
void graph_remove_node(struct graph *self, size_t nbNode);


/*
 * Supprime une transition dans un graphe.
 * Params :	self				: le graphe dans lequel supprimer la transition
 * 			nbNodeSource		: le numéro du noeud source de la transition
 * 			nbNodeDesination	: le numéro du noeud destination de la transition
 * 			symetrique			: booléen qui détermine si la transition est symétrique, et supprimer la transition dans les deux sens ou non
 */
void graph_remove_edge(struct graph *self, size_t nbNodeSource, size_t nbNodeDestination, bool symetrique);


/*
 * Affiche un graphe.
 * Params :	self	: la structure du graphe à afficher
 * 			file	: le fichier dans lequel afficher le graphe (par exemple stdout, ou un fichier pour sauvegarder)
 */
void graph_dump(struct graph *self, FILE* file);

#endif // GRAPH_H
