#ifndef MENU_H
#define MENU_H

#include "Array.h"

class menu {
private:
	array<int> memory = 0;
	void menu_intro();
	void menu_next();
	int menu_type();
public:
	menu();
	void menu_main();
};
#endif // !MENU_H
