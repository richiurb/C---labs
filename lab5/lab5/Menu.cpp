#include <iostream>
#include "Menu.h"

void menu::menu_intro() {
	std::cout << "������������ ������ �5 \"�������, ����������.\". ������� 21." << "\n";
	std::cout << "����� ������������� �������� � �������;" << "\n";
	std::cout << "������ �� N ��������� ���� T." << "\n";
}

int menu::menu_type() {
	std::cout << "���� �� ������ ������� ����� ������������� �������� � �������, �� ������� 1;" << "\n";
	std::cout << "����� ������� i-�� ������� �������, ������� 2;" << "\n";
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

menu::menu() {}

void menu::menu_main() {
	bool check_end = true;
	while (check_end) {
		menu_intro();
		check_end = false;
		int input_type = menu_type();
		
		if (input_type == 1) {
			std::cout << "������������ ������� � �������: " << memory.max_element() << "\n";
			check_end = true;
		}

		if (input_type == 2) {
			std::cout << "����� ������� i-�� ������� �������, ������� ����� i: ";
			int i;
			std::cin >> i;
			try {
				if ((i < 0) || (i >= memory.size())) {
					std::bad_alloc ex;
					throw ex;
				}
				std::cout << "\ni-�� ������� ������� �����: " << (int)memory[i];
				
			}
			catch (std::bad_alloc& exception) {
				std::cout << "You ran out of memory!" << '\n';
				break;
			}
			check_end = true;
		}


		menu_next();
		system("cls");
	}

	memory.~array();
}