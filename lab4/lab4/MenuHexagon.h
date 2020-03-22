#ifndef MENUHEXAGON_H
#define MENUHEXAGON_H

#include "Menu.h"
#include "Hexagon.h"
#include <vector>

class menu_hexagon : public menu {
private:
	std::vector<Hexagon> memory;
public:
	menu_hexagon();
	int menu_main();
	void new_hexagon();
	void hexagon_info();
	double sum_square();
	double sum_perimeter();
	CVector2D center_of_mass_of_system();
	unsigned int used_memory();
	void sort();
};
#endif  // !MENUSEGMENT_H
