#include <iostream>
#include "MenuSegment.h"
#include "MenuHexagon.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "");
	menu program_menu;

	program_menu.menu_intro();

	int input_type;
	input_type = program_menu.menu_type();
	system("cls");
	int check_end = -1;

	if (input_type == 1) {
		menu_segment p_menu;
		while (check_end != 0) {
			p_menu.menu_intro();
			check_end = p_menu.menu_main();
			system("cls");
		}
	}

	if (input_type == 2) {
		menu_hexagon s_menu;
		while (check_end != 0) {
			s_menu.menu_intro();
			check_end = s_menu.menu_main();
			system("cls");
		}
	}
}
