#include "Segment.h"
#include <cmath>
#include<iostream>

double Segment::perimeter() {
	return abs(sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)));
}

double Segment::square() {
	return 0;
}

double Segment::mass() const {
	return mas;
}

CVector2D Segment::position() {
	CVector2D ans;
	ans.x = (first.x + second.x) / 2;
	ans.y = (first.y + second.y) / 2;
	return ans;
}

bool Segment::operator==(const IPhysObject& ob) const {
	return mass() == ob.mass();
}

bool Segment::operator<(const IPhysObject& ob) const {
	return mass() < ob.mass();
}

void Segment::draw() {
	std::cout << "Координаты первой точки по X: " << (*this).first.x << "; по Y: " << (*this).first.y << "\n";
	std::cout << "Координаты второй точки по X: " << (*this).second.x << "; по Y: " << (*this).second.y << "\n";
	std::cout << "Периметр отрезка (его длина): " << (*this).perimeter() << "\n";
	std::cout << "Площадь отрезка (what?): " << (*this).square() << "\n";
	std::cout << "Масса отрезка: " << (*this).mass() << "\n";
	std::cout << "Центр масс по Х: " << (*this).position().x << "; по Y: " << (*this).position().y << "\n";
	std::cout << "Память, занимаемая отрезком: " << (*this).size() << "\n";
}

void Segment::initFromDialog() {
	std::cout << "\nВведите координату Х первой точки отрезка: ";
	std::cin >> first.x;
	std::cout << "\nВведите координату Y первой точки отрезка: ";
	std::cin >> first.y;
	std::cout << "\nВведите координату Х второй точки отрезка: ";
	std::cin >> second.x;
	std::cout << "\nВведите координату Y второй точки отрезка: ";
	std::cin >> second.y;
	std::cout << "\nВведите массу отрезка: ";
	std::cin >> mas;
}

const char* Segment::classname() {
	return "Segment";
}

unsigned int Segment::size() {
	return sizeof(double) * 5;
}
