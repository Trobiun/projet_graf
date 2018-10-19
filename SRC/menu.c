#include "menu.h"


#define NB_OPTIONS_FIRST_MENU 2
#define NB_OPTIONS_MAIN_MENU 6

//pour différencier le premier menu du menu principal
#define COMMAND_CODE_QUIT_FIRST_MENU 3
#define COMMAND_CODE_QUIT_MAIN_MENU 9


void option_create_full(struct option *self, int code, int result, char *text) {
	if (self != NULL) {
		self->codeCommand = code;
		self->result = result;
		if (text != NULL) {
			self->text = strdup(text);
		}
	}
}

void option_create(struct option *self, int code, char *text) {
	if (self != NULL) {
		option_create_full(self, code, code, text);
	}
}

void option_destroy(struct option *self) {
	if (self != NULL) {
		free(self->text);
	}
}

void menu_set_option(struct menu *self, size_t index, int code, int result, char *text) {
	if (self != NULL && index >= 0 && index < self->nbOptions) {
		self->options[index] = malloc(sizeof(struct option));
		option_create_full(self->options[index], code, result, text);
	}
}



void create_first_menu(struct menu *self) {
	self->nbOptions = NB_OPTIONS_FIRST_MENU + 1;
	self->options = calloc(self->nbOptions, sizeof(struct option*));
	
	size_t codeCommand = COMMAND_CODE_CREATE;
	size_t index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "create graph");
	
	codeCommand = COMMAND_CODE_LOAD;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "load graph");
	
	codeCommand = COMMAND_CODE_QUIT_FIRST_MENU;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, COMMAND_CODE_QUIT, "quit");
	
	
// 	menu_set_option(self, index, COMMAND_CODE_LOAD, COMMAND_CODE_CREATE, "create graph");
// 	self->options[COMMAND_CODE_CREATE - 1] = malloc(sizeof(struct option));
// 	option_create(self->options[COMMAND_CODE_CREATE - 1], COMMAND_CODE_CREATE, "create graph");
// 	self->options[COMMAND_CODE_LOAD - 1] = malloc(sizeof(struct option));
// 	option_create(self->options[COMMAND_CODE_LOAD - 1], COMMAND_CODE_LOAD, "load graph");
// 	self->options[COMMAND_CODE_QUIT_FIRST_MENU - 1] = malloc(sizeof(struct option));
// 	option_create_full(self->options[COMMAND_CODE_QUIT_FIRST_MENU - 1], COMMAND_CODE_QUIT_FIRST_MENU, COMMAND_CODE_QUIT, "quit");
}

void create_main_menu(struct menu *self) {
	self->nbOptions = NB_OPTIONS_MAIN_MENU + 1;
	self->options = calloc(self->nbOptions, sizeof(struct option*));
	
	size_t codeCommand = COMMAND_CODE_ADD_NODE;
	size_t index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "add node");
	
	codeCommand = COMMAND_CODE_ADD_EDGE;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "add edge");
	
	codeCommand = COMMAND_CODE_REMOVE_NODE;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "remove node");
	
	codeCommand = COMMAND_CODE_REMOVE_EDGE;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "remove edge");
	
	codeCommand = COMMAND_CODE_VIEW_GRAPH;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "view graph");
	
	codeCommand = COMMAND_CODE_SAVE_GRAPH;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, codeCommand, "save graph");
	
	codeCommand = COMMAND_CODE_QUIT_MAIN_MENU;
	index = codeCommand - 1;
	menu_set_option(self, index, codeCommand, COMMAND_CODE_QUIT, "quit");
	
// 	self->options[COMMAND_CODE_ADD_NODE] = malloc(sizeof(struct option));
// 	option_create_full(self->options[COMMAND_CODE_ADD_NODE], COMMAND_CODE_ADD_NODE - 2, COMMAND_CODE_ADD_NODE, "add node");
// 	self->options[1] = malloc(sizeof(struct option));
// 	option_create(self->options[1], COMMAND_CODE_ADD_EDGE, "add edge");
// 	self->options[2] = malloc(sizeof(struct option));
// 	option_create(self->options[2], COMMAND_CODE_REMOVE_NODE, "remove node");
// 	self->options[3] = malloc(sizeof(struct option));
// 	option_create(self->options[3], COMMAND_CODE_REMOVE_EDGE, "remove edge");
// 	self->options[4] = malloc(sizeof(struct option));
// 	option_create(self->options[4], COMMAND_CODE_VIEW_GRAPH, "view graph");
// 	self->options[5] = malloc(sizeof(struct option));
// 	option_create(self->options[5], COMMAND_CODE_SAVE_GRAPH, "save graph");
// 	self->options[6] = malloc(sizeof(struct option));
// 	option_create_full(self->options[6], COMMAND_CODE_QUIT_MAIN_MENU, COMMAND_CODE_QUIT, "quit");
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

bool menu_is_valid_option(struct menu *self, int option) {
	return option >= 0 && option < self->nbOptions;
}

int menu_show(struct menu *self) {
	int choix = 0;
	int res;
	size_t index = -2;
	printf("\n");
	for (index = 0; index < self->nbOptions; index++) {
		printf("%d : %s\n", self->options[index]->codeCommand, self->options[index]->text);
	}
	scanf("%d", &choix);
	if (menu_is_valid_option(self, choix)) {
		res =  self->options[choix - 1]->result;
	}
	return res;
}

int global_menu_show(struct global_menu *self) {
	int choix = 0;
	int res = 0;
	if (self->firstMenuToShow) {
		choix = menu_show(self->firstMenu);
		self->firstMenuToShow = false;
	}
	else {
		choix = menu_show(self->mainMenu);
	}
	self->selectedOption = choix;
	return res;
}
