#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct option {
	int codeCommand;
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

void menu_set_option(struct menu *self, struct option *option, size_t index);

void global_menu_create(struct global_menu *self);

void global_menu_destroy(struct global_menu *self);

int menu_show(struct menu *menu);

void global_menu_show(struct global_menu *menu);

#endif // MENU_H
