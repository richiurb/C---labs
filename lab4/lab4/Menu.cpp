#include <iostream>
#include "Menu.h"

void menu::menu_intro() {
	std::cout << "������������ ������ �4 \"����������� �������\". ������� 21." << "\n";
	std::cout << "�������;" << "\n";
	std::cout << "�������������." << "\n";
}

int menu::menu_type() {
	std::cout << "���� �� ������ ������� �������, �� ������� 1;" << "\n";
	std::cout << "���� �� ������ ������� �������������, �� ������� 2;" << "\n";
	std::cout << "���� �� ������� ������ �����/�����, �� ��������� �������� ���� ������:";

	int type;
	std::cin >> type;
	std::cout << "\n";
	return type;
}

void menu::menu_next() {
	std::cout << "\n" << "������� 1, ����� ����������.";
	int next = 0;
	while (next != 1) {
		std::cin >> next;
	}
	system("cls");
}
