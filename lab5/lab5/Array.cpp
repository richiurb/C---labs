#include <iostream>
#include "Array.h"
#define max(a, b) {a > b ? a : b}

template<class T>
array<T>::array() { 
}

template<class T>
array<T>::array(bool flag) {
	std::cout << "¬ведите, пожалуйста, число N: ";
	std::cin >> N;
	std::cout << "\n¬ведите N элементов в массив:\n";
	memory = new T(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> memory[i];
	}
}

template<class T>
T& array<T>::max_element() {
	T& ans = memory[0];
	for (int i = 1; i < N; ++i) {
		ans = max(memory[i], ans);
	}
	return ans;
}

template<class T>
T& array<T>::operator[](int i) {
	return memory[i];
}

template<class T>
array<T> array<T>::operator=(array<T> a) {
	return a;
}

template<class T>
array<T>::~array() {
	array();
}

template<class T>
int array<T>::size() {
	return N;
}