#include <iostream>;
#include <cmath>;
#include <algorithm>
#include "MenuSegment.h"

// public
menu_segment::menu_segment() {}

int menu_segment::menu_main() {
	std::cout << "�������� ���� �� ��������� ��������:\n";
	std::cout << "\"0\" - �������� ����� �������;\n";
	std::cout << "\"1\" - ����� ���������� ��� �������;\n";
	std::cout << "\"2\" - ��������� �������;\n";
	std::cout << "\"3\" - ��������� ��������;\n";
	std::cout << "\"4\" - ����� ���� ���� �������;\n";
	std::cout << "\"5\" - �������������� ������;\n";
	std::cout << "\"6\" - ���������� �� �����;\n";
	std::cout << "\"7\" - ��������� ���������:";

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
		std::cout << "���������� X: " << center_m.x << "; ���������� Y: " << center_m.y << "\n";
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
			std::cout << "������ " << i << ":\n";
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
