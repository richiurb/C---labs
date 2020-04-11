#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class T>
class array {
private:
	int N;
	T *memory;
public:
	array();
	array(bool);
	~array();
	T& max_element();
	T& operator[](int);
	array<T> operator=(array<T>);
	int size();
};

#include "Array.cpp"

#endif // !ARRAY_H
