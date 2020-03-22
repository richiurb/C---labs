#include <iostream>;
#include <cmath>;
#include <algorithm>
#include "MenuSegment.h"

// public
menu_segment::menu_segment() {}

int menu_segment::menu_main() {
	std::cout << "Выберите одно из возможных действий:\n";
	std::cout << "\"0\" - Добавить новый отрезок;\n";
	std::cout << "\"1\" - Вывод информации про отрезки;\n";
	std::cout << "\"2\" - Суммарная площадь;\n";
	std::cout << "\"3\" - Суммарный периметр;\n";
	std::cout << "\"4\" - Центр масс всей системы;\n";
	std::cout << "\"5\" - Использованная память;\n";
	std::cout << "\"6\" - Сортировка по массе;\n";
	std::cout << "\"7\" - Закончить программу:";

	int type;
	std::cin >> type;
	switch (type) {
	case 0:
		new_segment();
		break;
	case 1:
		segment_info();
		break;
	case 2:
		std::cout << sum_square();
		menu_next();
		break;
	case 3:
		std::cout << sum_perimeter();
		menu_next();
		break;
	case 4:
		CVector2D center_m = center_of_mass_of_system();
		std::cout << "Координата X: " << center_m.x << "; координата Y: " << center_m.y << "\n";
		menu_next();
		break;
	case 5:
		std::cout << used_memory();
		menu_next();
		break;
	case 6:
		sort();
		break;
	case 7:
		return 0;
	default:
		return 1;
	}
	return 1;
}

void menu_segment::new_segment() {
	Segment new_segment;
	new_segment.initFromDialog();
	memory.push_back(new_segment);
}

void menu_segment::segment_info() {
	if (memory.size() == 0) {
		std::cout << "no info:(";
	}
	else {
		int i = 0;
		for (Segment e : memory) {
			std::cout << "Ячейка " << i << ":\n";
			e.draw();
			i++;
		}
	}

	menu_next();
}

double menu_segment::sum_square() {
	return 0;
}

double menu_segment::sum_perimeter() {
	double ans = 0;
	for (Segment e : memory) {
		ans += e.perimeter();
	}
	return ans;
}

CVector2D menu_segment::center_of_mass_of_system() {
	double x_sum = 0;
	double y_sum = 0;
	double count = 0;

	for (Segment e : memory) {
		CVector2D this_e = e.position();
		double this_c = e.mass();
		x_sum += this_e.x * this_c;
		y_sum += this_e.y * this_c;
		count += this_c;
	}

	CVector2D ans;
	ans.x = x_sum / count;
	ans.y = y_sum / count;
	return ans;
}

unsigned int menu_segment::used_memory() {
	Segment s_null;
	return (s_null.size() * memory.size());
}

void menu_segment::sort() {
	std::sort(memory.begin(), memory.end(),
		[](const Segment& a, const Segment& b) {
			return a.mass() < b.mass();
		});
}
