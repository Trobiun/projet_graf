#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


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
	int codeCommand;
	int result;
	char *text;
};

//structure pour les menus
struct menu {
	struct option **options;
	size_t nbOptions;
};

//structure pour gérer les deux menus
struct global_menu {
	struct menu *firstMenu; //premier menu pour créer ou charger un graphe, et quitter
	struct menu *mainMenu; //menu principal de l'application
	bool firstMenuToShow; //booléen pour savoir s'il faut afficher le premier menu ou le principal
	int selectedOption; //l'option sélectionnée par l'utilisateur, doit correspondre à une des constantes de préprocesseur commençant par "COMMAND_CODE"
};

void option_destroy(struct option *self);

void menu_create(struct menu *self);

void menu_destroy(struct menu *self);

/*
 * Définit une option pour un menu, seulement si celle-ci n'est pas déjà définie dans le menu
 */
void menu_set_option(struct menu *self, size_t index, int code, int result, char *text);

void global_menu_create(struct global_menu *self);

void global_menu_destroy(struct global_menu *self);

int menu_show(struct menu *menu);

int global_menu_show(struct global_menu *menu);

#endif // MENU_H
