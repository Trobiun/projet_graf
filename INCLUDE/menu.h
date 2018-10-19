#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//pour les commandes utilisées
#define COMMAND_CODE_QUIT -1

#define COMMAND_CODE_CREATE 1
#define COMMAND_CODE_LOAD 2
#define COMMAND_CODE_ADD_NODE 3
#define COMMAND_CODE_ADD_EDGE 4
#define COMMAND_CODE_REMOVE_NODE 5
#define COMMAND_CODE_REMOVE_EDGE 6
#define COMMAND_CODE_VIEW_GRAPH 7
#define COMMAND_CODE_SAVE_GRAPH 8


struct option {
	int codeCommand;
	int result; //pour l'option quitter
	char *text;
};

struct menu {
	struct option **options;
	size_t nbOptions;
};

struct global_menu {
	struct menu *firstMenu;
	struct menu *mainMenu;
	bool firstMenuToShow;
	int selectedOption;
};

void option_create(struct option *self, int code, char* text);

void option_destroy(struct option *self);

void menu_create(struct menu *self);

void menu_destroy(struct menu *self);

void menu_set_option(struct menu *self, size_t index, int code, int result, char *text);

void global_menu_create(struct global_menu *self);

void global_menu_destroy(struct global_menu *self);

int menu_show(struct menu *menu);

int global_menu_show(struct global_menu *menu);

#endif // MENU_H
