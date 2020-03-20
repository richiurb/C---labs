#include "Segment.h"
#include <cmath>
#include<iostream>

double Segment::perimeter() {
	return abs(sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)));
}

double Segment::square() {
	return 0;
}

double Segment::mass() {
	return (*this).mas;
}

CVector2D Segment::position() {
	CVector2D ans;
	ans.x = (first.x + second.x) / 2;
	ans.y = (first.y + second.y) / 2;
	return ans;
}

bool Segment::operator==(const IPhysObject& ob) const {
	//return (*this).mas == ;
}

bool Segment::operator<(const IPhysObject& ob) const {
	//return (*this).mas < mass();
}

void Segment::draw() {
	std::cout << "���������� ������ ����� �� X: " << (*this).first.x << "; �� Y: " << (*this).first.y << "\n";
	std::cout << "���������� ������ ����� �� X: " << (*this).second.x << "; �� Y: " << (*this).second.y << "\n";
	std::cout << "�������� ������� (��� �����): " << (*this).perimeter() << "\n";
	std::cout << "������� ������� (what?): " << (*this).square() << "\n";
	std::cout << "����� �������: " << (*this).mass() << "\n";
	std::cout << "����� ���� �� �" << (*this).position().x << "; �� Y: " << (*this).position().y << "\n";
}

void Segment::initFromDialog() {
	std::cout << "������� ���������� � ������ ����� �������: ";
	std::cin >> first.x;
	std::cout << "/n������� ���������� Y ������ ����� �������: ";
	std::cin >> first.y;
	std::cout << "/n������� ���������� � ������ ����� �������: ";
	std::cin >> second.x;
	std::cout << "/n������� ���������� Y ������ ����� �������: ";
	std::cin >> second.y;
	std::cout << "/n������� ����� �������: ";
	std::cin >> mas;
}

const char* Segment::classname() {
	return "Segment";
}

unsigned int Segment::size() {
	return sizeof(double) * 5;
}
