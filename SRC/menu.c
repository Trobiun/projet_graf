#include "menu.h"

#define NB_OPTIONS_FIRST_MENU 2
#define NB_OPTIONS_MAIN_MENU 6

//pour différencier le premier menu du menu principal
#define COMMAND_CODE_QUIT_FIRST_MENU 3
#define COMMAND_CODE_QUIT_MAIN_MENU 9


void option_create(struct option *self, int code, int result, char *text) {
	if (self != NULL) {
		self->codeCommand = code;
		self->result = result;
		if (text != NULL) {
			self->text = strdup(text);
		}
	}
}

void option_destroy(struct option *self) {
	if (self != NULL) {
		free(self->text);
	}
}

void menu_set_option(struct menu *self, size_t index, int code, int result, char *text) {
	if (self != NULL && index >= 0 && index < self->nbOptions && self->options[index] == NULL) {
		self->options[index] = malloc(sizeof(struct option));
		option_create(self->options[index], code, result, text);
	}
}

void create_first_menu(struct menu *self) {
	if (self != NULL) {
		self->nbOptions = NB_OPTIONS_FIRST_MENU + 1;
		self->options = calloc(self->nbOptions, sizeof(struct option*));
		size_t i;
		for (i = 0; i < self->nbOptions; i++) {
			self->options[i] = NULL;
		}
		
		size_t codeCommand = COMMAND_CODE_CREATE;
		//les numéros d'option pour les menus commençant par 1
		//et les indices de tableaux commençant par 0, on décrémente de 1 pour avoir l'indice
		size_t index = codeCommand - 1;
		menu_set_option(self, index, codeCommand, codeCommand, "create graph");
		
		codeCommand = COMMAND_CODE_LOAD;
		index = codeCommand - 1;
		menu_set_option(self, index, codeCommand, codeCommand, "load graph");
		
		codeCommand = COMMAND_CODE_QUIT_FIRST_MENU;
		index = codeCommand - 1;
		menu_set_option(self, index, codeCommand, COMMAND_CODE_QUIT, "quit");
	}
}

void create_main_menu(struct menu *self) {
	if (self != NULL) {
		self->nbOptions = NB_OPTIONS_MAIN_MENU + 1;
		self->options = calloc(self->nbOptions, sizeof(struct option*));
		size_t i;
		for (i = 0; i < self->nbOptions; i++) {
			self->options[i] = NULL;
		}
		
		//utilisé pour afficher le menu principal avec des options commençant par 1 au lieu de 3
		//(les options pour créer ou charger un graphe n'étant plus utiles)
		size_t decrement = NB_OPTIONS_FIRST_MENU + 1;
		
		size_t codeCommand = COMMAND_CODE_ADD_NODE;
		size_t index = codeCommand - decrement;
		menu_set_option(self, index, index + 1, codeCommand, "add node");
		
		codeCommand = COMMAND_CODE_ADD_EDGE;
		index = codeCommand - decrement;
		menu_set_option(self, index, index + 1, codeCommand, "add edge");
		
		codeCommand = COMMAND_CODE_REMOVE_NODE;
		index = codeCommand - decrement;
		menu_set_option(self, index, index + 1, codeCommand, "remove node");
		
		codeCommand = COMMAND_CODE_REMOVE_EDGE;
		index = codeCommand - decrement;
		menu_set_option(self, index, index + 1, codeCommand, "remove edge");
		
		codeCommand = COMMAND_CODE_VIEW_GRAPH;
		index = codeCommand - decrement;
		menu_set_option(self, index, index + 1, codeCommand, "view graph");
		
		codeCommand = COMMAND_CODE_SAVE_GRAPH;
		index = codeCommand - decrement;
		menu_set_option(self, index, index + 1, codeCommand, "save graph");
		
		codeCommand = COMMAND_CODE_QUIT_MAIN_MENU;
		index = codeCommand - decrement;
		menu_set_option(self, index, index + 1, COMMAND_CODE_QUIT, "quit");
	}
}

void menu_destroy(struct menu *self) {
	if (self != NULL) {
		for (size_t i = 0; i < self->nbOptions; i++) {
			option_destroy(self->options[i]);
			free(self->options[i]);
		}
		free(self->options);
	}
}

void global_menu_create(struct global_menu *self) {
	if (self != NULL) {
		self->firstMenuToShow = true;
		self->selectedOption = 0;
		self->firstMenu = malloc(sizeof(struct menu));
		self->mainMenu = NULL;
		create_first_menu(self->firstMenu);
	}
}

void global_menu_destroy(struct global_menu *self) {
	if (self != NULL) {
		menu_destroy(self->firstMenu);
		free(self->firstMenu);
		menu_destroy(self->mainMenu);
		free(self->mainMenu);
	}
}

bool menu_is_valid_option(struct menu *self, int option) {
	bool res = false;
	if (self != NULL) {
		res = option > 0 && option <= self->nbOptions;
	}
	return res;
}

int menu_show(struct menu *self) {
	int res = ERREUR_SAISIE_OPTION;
	if (self != NULL) {
		int choix = 0;
		size_t index;
		printf("\n");
		for (index = 0; index < self->nbOptions; index++) {
			printf("%d : %s\n", self->options[index]->codeCommand, self->options[index]->text);
		}
		scanf("%d", &choix);
		getchar();
		if (menu_is_valid_option(self, choix)) {
			res =  self->options[choix - 1]->result;
		}
	}
	return res;
}

void global_menu_activate_main_menu(struct global_menu *self) {
	if (self != NULL) {
		self->firstMenuToShow = false;
		self->mainMenu = malloc(sizeof(struct menu));
		create_main_menu(self->mainMenu);
		menu_destroy(self->firstMenu);
		free(self->firstMenu);
		self->firstMenu = NULL;
	}
}

void global_menu_show(struct global_menu *self) {
	if (self != NULL) {
		int choix = 0;
		if (self->firstMenuToShow) {
			choix = menu_show(self->firstMenu);
		}
		else {
			choix = menu_show(self->mainMenu);
		}
		self->selectedOption = choix;
	}
}
