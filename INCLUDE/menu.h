#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ERREUR_SAISIE_OPTION -2

//les codes des commandes disponibles pour les menus
#define COMMAND_CODE_QUIT -1

#define COMMAND_CODE_CREATE 1
#define COMMAND_CODE_LOAD 2
#define COMMAND_CODE_ADD_NODE 3
#define COMMAND_CODE_ADD_EDGE 4
#define COMMAND_CODE_REMOVE_NODE 5
#define COMMAND_CODE_REMOVE_EDGE 6
#define COMMAND_CODE_VIEW_GRAPH 7
#define COMMAND_CODE_SAVE_GRAPH 8

//structure pour les options des menus
struct option {
	int codeCommand;	//le code de commande pour différencier les options, utilise les constantes de préprocesseur en haut du fichier
	int result;			//le code de commande, valeur renvoyée quand l'option est sélectionnée, utilise les constantes de préprocesseur en haut du fichier
	char *text;			//le texte à afficher dans le menu
};

//structure pour les menus
struct menu {
	struct option **options;	//un tableau de pointeurs d'options, qui seront affichées et utilisées pour le menu
	size_t nbOptions;			//le nombre d'options du menu
};

//structure pour gérer les deux menus
struct global_menu {
	struct menu *firstMenu;	//premier menu pour créer ou charger un graphe, et quitter
	struct menu *mainMenu;	//menu principal de l'application
	bool firstMenuToShow;	//booléen pour savoir s'il faut afficher le premier menu ou le principal
	int selectedOption;		//l'option sélectionnée par l'utilisateur, doit correspondre à une des constantes de préprocesseur commençant par "COMMAND_CODE"
};

/*
 * Initialise une option de menu.
 * Params :	self	: l'option de menu à initialiser
 * 			code	: le code de la commande de l'option
 * 			result	: le résultat de l'option quand elle est sélectionnée
 * 			text	: le texte de l'option qui sera affichée dans le menu
 */
void option_create(struct option *self, int code, int result, char *text);

/*
 * Détruit une option;
 * Params :	self : l'option à détruire
 */
void option_destroy(struct option *self);

/*
 * Initialise un menu.
 * Params :	self	: le menu à initialiser
 */
void menu_create(struct menu *self);

/*
 * Détruit un menu.
 * Params :	self	: le menu à détruire
 */
void menu_destroy(struct menu *self);

/*
 * Définit une option pour un menu, seulement si celle-ci n'est pas déjà définie dans le menu
 * Params :	self	: le menu auquel définir une option
 * 			index	: l'indice de l'option à définir
 * 			code	: le code de commande de l'option
 * 			result	: le code de commande résultat de l'option
 * 			text	: le texte de l'option
 */
void menu_set_option(struct menu *self, size_t index, int code, int result, char *text);

/*
 * Initialise le menu global.
 * Params :	self	: le menu global à initialiser
 */
void global_menu_create(struct global_menu *self);

/*
 * Détruit le menu global.
 * Params :	self	: le menu global à détruire
 */
void global_menu_destroy(struct global_menu *self);

/*
 * Affiche un menu et retourne la valeur donnée par l'utilisateur
 * Params :	menu	: le menu à afficher
 * Returns : Retourne un entier donné par l'utilisateur, 
 */
int menu_show(struct menu *menu);

/*
 * Affiche le menu global (affiche le menu principal ou le premier menu)
 * Params :	self	: le menu global à afficher
 */
void global_menu_show(struct global_menu *self);

/*
 * Crée et active le menu principal (le premier menu n'est plus utile une fois le graphe créé ou chargé).
 * Params :	self	: le menu global dans lequel activer le menu principal.
 */
void global_menu_activate_main_menu(struct global_menu *self);

#endif // MENU_H
