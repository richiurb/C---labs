#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class CComplex {
private:
	double real, im;
public:
	CComplex(double real = 0, double im = 0) {
		(*this).real = real;
		(*this).im = im;
	}

	double length() {
		return sqrt(real * real + im * im);
	}

	bool operator==(const CComplex& complex) {
		return (real == complex.real) && (im == complex.im);
	}

	bool operator!=(const CComplex& complex) {
		return !((*this) == complex);
	}

	bool operator>(CComplex& complex) {
		return (*this).length() > complex.length();
	}

	bool operator<(int length) {
		return (*this).length() < length;
	}

	bool operator<(CComplex& complex) {
		return (*this).length() < complex.length();
	}

	friend ostream& operator<< (ostream& out, const CComplex& point);
	friend istream& operator>> (istream& in, CComplex& complex);
};

ostream& operator<< (ostream& out, const CComplex& complex)
{
	out << complex.real << " + " << complex.im << "i";
	return out;
}

istream& operator>> (istream& in, CComplex& complex)
{
	in >> complex.real;
	in >> complex.im;
	return in;
}

template<class ForwardIterator, class UnaryPredicat>
bool none_of(ForwardIterator first, ForwardIterator last, UnaryPredicat predicat) {
	while (first != last) {
		if (predicat(*first)) {
			return false;
		}
		first++;
	}
	return true;
}

template<class ForwardIterator, class Comparator>
bool is_sorted(ForwardIterator first, ForwardIterator last, Comparator comp) {
	ForwardIterator prev = first;
	first++;
	while (first != last) {
		if (!comp(prev, first)) {
			return false;
		}
		prev++;
		first++;
	}
	return true;
}

template<class ForwardIterator, class Type>
ForwardIterator find_not(ForwardIterator first, ForwardIterator last, const Type& value) {
	while (first != last) {
		if (*first != value) {
			return first;
		}
		first++;
	}
	return last;
}

class LessThanSmth {
public:
	int _number;
	LessThanSmth(int number = 5) : _number(number){}

	int number() { 
		return _number; 
	}

	template<class ForwardIterator>
	bool operator()(ForwardIterator it1) {
		return it1 < number();
	}
};

class MoreThanNext {
public:
	template <class ForwardIterator>
	bool operator()(ForwardIterator it1, ForwardIterator it2) {
		return *it1 > *it2;
	}
};

void output_intro() {
	cout << "Лабораторная работа №6. Реализация обобщённых алгоритмов." << endl;
	cout << "Вариант 21. none_of; is_sorted; find_not." << endl;
}

int main() {
	setlocale(LC_CTYPE, "");
	output_intro();

	int n;
	cout << "Введите количество элементов для вектора типа int: ";
	cin >> n;
	vector<int> vector_int;
	for (int i = 0; i < n; ++i) {
		cout << "Введите элемент вектора: ";
		int e;
		cin >> e;
		vector_int.push_back(e);
	}

	cout << endl << "Результат none_of: " << none_of(vector_int.begin(), vector_int.end(), LessThanSmth());
	cout << endl << "Результат is_sorted: " << is_sorted(vector_int.begin(), vector_int.end(), MoreThanNext());
	cout << endl << "Результат find_not: " << *find_not(vector_int.begin(), vector_int.end(), 8);
	
	vector_int.~vector();

	cout << endl << "Введите количество элементов для вектора типа CComplex: ";
	cin >> n;
	vector<CComplex> vector_complex;
	for (int i = 0; i < n; ++i) {
		cout << "Введите элемент вектора (вещественную и мнимую часть через пробел): ";
		CComplex e;
		cin >> e;
		vector_complex.push_back(e);
	}

	cout << endl << "Результат none_of: " << none_of(vector_complex.begin(), vector_complex.end(), LessThanSmth());
	cout << endl << "Результат is_sorted: " << is_sorted(vector_complex.begin(), vector_complex.end(), MoreThanNext());
	cout << endl << "Результат find_not: " << *find_not(vector_complex.begin(), vector_complex.end(), 8);

	vector_complex.~vector();

	return 0;
}