#include <iostream>
#include "Menu.h"

void menu::menu_intro() {
	std::cout << "Лабораторная работа №5 \"Шаблоны, исключения.\". Вариант 21." << "\n";
	std::cout << "Поиск максимального элемента в массиве;" << "\n";
	std::cout << "Массив из N элементов типа T." << "\n";
}

int menu::menu_type() {
	std::cout << "Если вы хотите выбрать поиск максимального элемента в массиве, то нажмите 1;" << "\n";
	std::cout << "Чтобы вывести i-ый элемент массива, нажмите 2;" << "\n";
	std::cout << "если вы введете другое число/цифру, то программа закончит свою работу:";

	int type;
	std::cin >> type;
	std::cout << "\n";
	return type;
}

void menu::menu_next() {
	std::cout << "\n" << "Введите 1, чтобы продолжить.";
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
			std::cout << "Максимальный элемент в массиве: " << memory.max_element() << "\n";
			check_end = true;
		}

		if (input_type == 2) {
			std::cout << "Чтобы вывести i-ый элемент массива, введите число i: ";
			int i;
			std::cin >> i;
			try {
				if ((i < 0) || (i >= memory.size())) {
					std::bad_alloc ex;
					throw ex;
				}
				std::cout << "\ni-ый элемент массива равен: " << (int)memory[i];
				
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