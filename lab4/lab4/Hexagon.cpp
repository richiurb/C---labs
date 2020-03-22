#include "Hexagon.h"
#include <cmath>
#include <iostream>

//private
double Hexagon::side(CVector2D first, CVector2D second) {
	double length_x = second.x - first.x;
	double length_y = second.y - first.y;
	return sqrt(length_x * length_x + length_y * length_y);
}

double Hexagon::square_triangle(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

//public
double Hexagon::perimeter() {
	return side(A, B) + side(B, C) + side(C, D) + side(D, E) + side(E, F) + side (F, A);
}

double Hexagon::square() {
	CVector2D O = position();
	double first_s = square_triangle(side(A, B), side(A, O), side(B, O));
	double second_s = square_triangle(side(B, C), side(B, O), side(C, O));
	double third_s = square_triangle(side(C, D), side(C, O), side(D, O));
	double fourth_s = square_triangle(side(D, E), side(D, O), side(E, O));
	double fifth_s = square_triangle(side(E, F), side(E, O), side(F, O));
	double sixth_s = square_triangle(side(F, A), side(F, O), side(A, O));
	return first_s + second_s + third_s + fourth_s + fifth_s + sixth_s;
}

double Hexagon::mass() const {
	return mas;
}

CVector2D Hexagon::position() {
	CVector2D ans;
	ans.x = (A.x + B.x + C.x + D.x + E.x + F.x) / 6;
	ans.y = (A.y + B.y + C.y + D.y + E.y + F.y) / 6;
	return ans;
}

bool Hexagon::operator==(const IPhysObject& ob) const {
	return mass() == ob.mass();
}

bool Hexagon::operator<(const IPhysObject& ob) const {
	return mass() < ob.mass();
}

void Hexagon::draw() {
	std::cout << "Координаты точки A по X: " << (*this).A.x << "; по Y: " << (*this).A.y << "\n";
	std::cout << "Координаты точки B по X: " << (*this).B.x << "; по Y: " << (*this).B.y << "\n";
	std::cout << "Координаты точки C по X: " << (*this).C.x << "; по Y: " << (*this).C.y << "\n";
	std::cout << "Координаты точки D по X: " << (*this).D.x << "; по Y: " << (*this).D.y << "\n";
	std::cout << "Координаты точки E по X: " << (*this).E.x << "; по Y: " << (*this).E.y << "\n";
	std::cout << "Координаты точки F по X: " << (*this).F.x << "; по Y: " << (*this).F.y << "\n";
	std::cout << "Периметр шестиугольника: " << (*this).perimeter() << "\n";
	std::cout << "Площадь шестиугольника: " << (*this).square() << "\n";
	std::cout << "Масса шестиугольника: " << (*this).mass() << "\n";
	std::cout << "Центр масс по Х: " << (*this).position().x << "; по Y: " << (*this).position().y << "\n";
}

void Hexagon::initFromDialog() {
	std::cout << "\nВведите координату Х точки А шестиугольника: ";
	std::cin >> A.x;
	std::cout << "\nВведите координату Y точки А шестиугольника: ";
	std::cin >> A.y;
	std::cout << "\nВведите координату Х точки B шестиугольника: ";
	std::cin >> B.x;
	std::cout << "\nВведите координату Y точки B шестиугольника: ";
	std::cin >> B.y;
	std::cout << "\nВведите координату Х точки C шестиугольника: ";
	std::cin >> C.x;
	std::cout << "\nВведите координату Y точки C шестиугольника: ";
	std::cin >> C.y;
	std::cout << "\nВведите координату Х точки D шестиугольника: ";
	std::cin >> D.x;
	std::cout << "\nВведите координату Y точки D шестиугольника: ";
	std::cin >> D.y;
	std::cout << "\nВведите координату Х точки E шестиугольника: ";
	std::cin >> E.x;
	std::cout << "\nВведите координату Y точки E шестиугольника: ";
	std::cin >> E.y;
	std::cout << "\nВведите координату Х точки F шестиугольника: ";
	std::cin >> F.x;
	std::cout << "\nВведите координату Y точки F шестиугольника: ";
	std::cin >> F.y;
	std::cout << "\nВведите массу отрезка: ";
	std::cin >> mas;
}

const char* Hexagon::classname() {
	return "Hexagon";
}

unsigned int Hexagon::size() {
	return sizeof(double) * 13;
}
