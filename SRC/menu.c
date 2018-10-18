#include "menu.h"

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

//pour définir quel menu lancer
#define COMMAND_CODE_QUIT_FIRST_MENU 3
#define COMMAND_CODE_QUIT_MAIN_MENU 9

void option_create(struct option *self, int code, char* text) {
	if (self != NULL) {
		self->codeCommand = code;
		self->text = strdup(text);
	}
}

void option_destroy(struct option *self) {
	free(self->text);
}

// void create_menu(struct menu *self) {
// 	self->firstMenuToShow = true;
// 	self->COMMAND_QUIT = COMMAND_CODE_QUIT;
// 	self->COMMAND_CREATE = COMMAND_CODE_CREATE;
// 	self->COMMAND_LOAD = COMMAND_CODE_LOAD;
// 	self->COMMAND_ADD_NODE = COMMAND_CODE_ADD_NODE;
// 	self->COMMAND_ADD_EDGE = COMMAND_CODE_ADD_EDGE;
// 	self->COMMAND_REMOVE_NODE = COMMAND_CODE_REMOVE_NODE;
// 	self->COMMAND_REMOVE_EDGE = COMMAND_CODE_REMOVE_EDGE;
// 	self->COMMAND_VIEW_GRAPH = COMMAND_CODE_VIEW_GRAPH;
// 	self->COMMAND_SAVE_GRAPH = COMMAND_CODE_SAVE_GRAPH;
// }

// int add_line_menu(int index, char *s) {
// 	printf("%d : %s\n", index, s);
// 	return 0;
// }

// int show_first_menu() {
// 	int choix;
// 	add_line_menu(COMMAND_CODE_CREATE, "create graph");
// 	add_line_menu(COMMAND_CODE_LOAD, "load graph");
// 	add_line_menu(COMMAND_CODE_QUIT_FIRST_MENU, "quit");
// 	scanf("%d",&choix);
// 	if (choix == COMMAND_CODE_QUIT_FIRST_MENU) {
// 		choix = -1;
// 	}
// 	return choix;
// }
// 
// int show_main_menu() {
// 	int choix;
// 	add_line_menu(COMMAND_CODE_CREATE, "create graph");
// 	add_line_menu(COMMAND_CODE_LOAD, "load graph");
// 	add_line_menu(COMMAND_CODE_ADD_NODE, "add node");
// 	add_line_menu(COMMAND_CODE_ADD_EDGE, "add edge");
// 	add_line_menu(COMMAND_CODE_REMOVE_NODE, "remove node");
// 	add_line_menu(COMMAND_CODE_REMOVE_EDGE, "remove edge");
// 	add_line_menu(COMMAND_CODE_VIEW_GRAPH, "view graph");
// 	add_line_menu(COMMAND_CODE_SAVE_GRAPH, "save graph");
// 	add_line_menu(COMMAND_CODE_QUIT_MAIN_MENU, "quit");
// 	scanf("%d", &choix);
// 	if (choix == COMMAND_CODE_QUIT_MAIN_MENU) {
// 		choix = -1;
// 	}
// 	return choix;
// }

void create_first_menu(struct menu *self) {
	self->nbOptions = 3;
	self->options = calloc(self->nbOptions, sizeof(struct option*));
	self->options[0] = malloc(sizeof(struct option));
	option_create(self->options[0], COMMAND_CODE_CREATE, "1 : create graph");
	self->options[1] = malloc(sizeof(struct option));
	option_create(self->options[1], COMMAND_CODE_LOAD, "2 : load graph");
	self->options[2] = malloc(sizeof(struct option));
	option_create(self->options[2], COMMAND_CODE_QUIT_FIRST_MENU, "3 : quit");
}

// void menu_set_option(struct menu* self, struct option* option, size_t index) {
// 	if (index >= 0 && index < self->nbOptions && option != NULL) {
// 		self->options[index] = option;
// 	}
// }


void create_main_menu(struct menu *self) {
	self->nbOptions = 9;
	self->options = calloc(self->nbOptions, sizeof(struct option*));
	self->options[0] = malloc(sizeof(struct option));
	option_create(self->options[0], COMMAND_CODE_CREATE, "1 : create graph");
	self->options[1] = malloc(sizeof(struct option));
	option_create(self->options[1], COMMAND_CODE_LOAD, "2 : load graph");
	self->options[2] = malloc(sizeof(struct option));
	option_create(self->options[2], COMMAND_CODE_ADD_NODE, "3 : add node");
	self->options[3] = malloc(sizeof(struct option));
	option_create(self->options[3], COMMAND_CODE_ADD_EDGE, "4 : add edge");
	self->options[4] = malloc(sizeof(struct option));
	option_create(self->options[4], COMMAND_CODE_REMOVE_NODE, "5 : remove node");
	self->options[5] = malloc(sizeof(struct option));
	option_create(self->options[5], COMMAND_CODE_REMOVE_EDGE, "6 : remove edge");
	self->options[6] = malloc(sizeof(struct option));
	option_create(self->options[6], COMMAND_CODE_VIEW_GRAPH, "7 : view graph");
	self->options[7] = malloc(sizeof(struct option));
	option_create(self->options[7], COMMAND_CODE_SAVE_GRAPH, "8 : save graph");
	self->options[8] = malloc(sizeof(struct option));
	option_create(self->options[8], COMMAND_CODE_QUIT_MAIN_MENU, "9 : quit");
}

void menu_destroy(struct menu *self) {
	for (size_t i = 0; i < self->nbOptions; i++) {
		option_destroy(self->options[i]);
		free(self->options[i]);
	}
	free(self->options);
}

void global_menu_create(struct global_menu *self) {
	self->firstMenuToShow = true;
	self->selectedOption = 0;
	self->firstMenu = malloc(sizeof(struct menu));
	self->mainMenu = malloc(sizeof(struct menu));
	create_first_menu(self->firstMenu);
	create_main_menu(self->mainMenu);
}

void global_menu_destroy(struct global_menu *self) {
	menu_destroy(self->firstMenu);
	free(self->firstMenu);
	menu_destroy(self->mainMenu);
	free(self->mainMenu);
}

int menu_show(struct menu *self) {
	int choix = 0;
	for (size_t i = 0; i < self->nbOptions; i++) {
		printf("%s\n", self->options[i]->text);
	}
	scanf("%d",&choix);
	return choix;
}

void global_menu_show(struct global_menu *menu) {
	if (menu->firstMenuToShow) {
		menu_show(menu->firstMenu);
	}
	else {
		menu_show(menu->mainMenu);
	}
}
