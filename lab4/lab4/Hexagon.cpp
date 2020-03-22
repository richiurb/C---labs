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
	std::cout << "���������� ����� A �� X: " << (*this).A.x << "; �� Y: " << (*this).A.y << "\n";
	std::cout << "���������� ����� B �� X: " << (*this).B.x << "; �� Y: " << (*this).B.y << "\n";
	std::cout << "���������� ����� C �� X: " << (*this).C.x << "; �� Y: " << (*this).C.y << "\n";
	std::cout << "���������� ����� D �� X: " << (*this).D.x << "; �� Y: " << (*this).D.y << "\n";
	std::cout << "���������� ����� E �� X: " << (*this).E.x << "; �� Y: " << (*this).E.y << "\n";
	std::cout << "���������� ����� F �� X: " << (*this).F.x << "; �� Y: " << (*this).F.y << "\n";
	std::cout << "�������� ��������������: " << (*this).perimeter() << "\n";
	std::cout << "������� ��������������: " << (*this).square() << "\n";
	std::cout << "����� ��������������: " << (*this).mass() << "\n";
	std::cout << "����� ���� �� �: " << (*this).position().x << "; �� Y: " << (*this).position().y << "\n";
}

void Hexagon::initFromDialog() {
	std::cout << "\n������� ���������� � ����� � ��������������: ";
	std::cin >> A.x;
	std::cout << "\n������� ���������� Y ����� � ��������������: ";
	std::cin >> A.y;
	std::cout << "\n������� ���������� � ����� B ��������������: ";
	std::cin >> B.x;
	std::cout << "\n������� ���������� Y ����� B ��������������: ";
	std::cin >> B.y;
	std::cout << "\n������� ���������� � ����� C ��������������: ";
	std::cin >> C.x;
	std::cout << "\n������� ���������� Y ����� C ��������������: ";
	std::cin >> C.y;
	std::cout << "\n������� ���������� � ����� D ��������������: ";
	std::cin >> D.x;
	std::cout << "\n������� ���������� Y ����� D ��������������: ";
	std::cin >> D.y;
	std::cout << "\n������� ���������� � ����� E ��������������: ";
	std::cin >> E.x;
	std::cout << "\n������� ���������� Y ����� E ��������������: ";
	std::cin >> E.y;
	std::cout << "\n������� ���������� � ����� F ��������������: ";
	std::cin >> F.x;
	std::cout << "\n������� ���������� Y ����� F ��������������: ";
	std::cin >> F.y;
	std::cout << "\n������� ����� �������: ";
	std::cin >> mas;
}

const char* Hexagon::classname() {
	return "Hexagon";
}

unsigned int Hexagon::size() {
	return sizeof(double) * 13;
}
