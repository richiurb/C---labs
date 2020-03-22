#ifndef MENUSEGMENT_H
#define MENUSEGMENT_H

#include "Menu.h"
#include "Segment.h"
#include <vector>

class menu_segment : public menu {
private:
	std::vector<Segment> memory;
public:
	menu_segment();
	int menu_main();
	void new_segment();
	void segment_info();
	double sum_square();
	double sum_perimeter();
	CVector2D center_of_mass_of_system();
	unsigned int used_memory();
	void sort();
};
#endif  // !MENUSEGMENT_H
