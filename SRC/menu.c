#include <stdio.h>
#include <stdbool.h>
#include "menu.h"

#define COMMAND_QUIT_FIRST_MENU 3
#define COMMAND_QUIT_MAIN_MENU 9

int add_line_menu(int index, char *s) {
	printf("%d : %s\n", index, s);
}

int show_first_menu() {
	int choix;
	add_line_menu(COMMAND_CREATE, "create graph");
	add_line_menu(COMMAND_LOAD, "load graph");
	add_line_menu(COMMAND_QUIT_FIRST_MENU, "quit");
	scanf("%d",&choix);
	if (choix == COMMAND_QUIT_FIRST_MENU) {
		choix = -1;
	}
	return choix;
}

int show_main_menu() {
	int choix;
	add_line_menu(COMMAND_CREATE, "create graph");
	add_line_menu(COMMAND_LOAD, "load graph");
	add_line_menu(COMMAND_ADD_NODE, "add node");
	add_line_menu(COMMAND_ADD_EDGE, "add edge");
	add_line_menu(COMMAND_REMOVE_NODE, "remove node");
	add_line_menu(COMMAND_REMOVE_EDGE, "remove edge");
	add_line_menu(COMMAND_VIEW_GRAPH, "view graph");
	add_line_menu(COMMAND_SAVE_GRAPH, "save graph");
	add_line_menu(COMMAND_QUIT_MAIN_MENU, "quit");
	scanf("%d", &choix);
	if (choix == COMMAND_QUIT_MAIN_MENU) {
		choix = -1;
	}
	return choix;
}

int main(int argc, char ** argv) {
	bool firstMenuToShow = true;
	while (true) {
		int choix = 0;
		if (firstMenuToShow) {
			choix = show_first_menu();
			firstMenuToShow = false;
		}
		else {
			choix = show_main_menu();
		}
		if (choix == -1) {
			break;
		}
	}
	return 0;
}
