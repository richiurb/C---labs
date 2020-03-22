#include <iostream>
#include "Menu.h"

void menu::menu_intro() {
	std::cout << "Лабораторная работа №4 \"Виртуальные функции\". Вариант 21." << "\n";
	std::cout << "Отрезок;" << "\n";
	std::cout << "Шестиугольник." << "\n";
}

int menu::menu_type() {
	std::cout << "Если вы хотите выбрать отрезок, то нажмите 1;" << "\n";
	std::cout << "если вы хотите выбрать шестиугольник, то нажмите 2;" << "\n";
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
