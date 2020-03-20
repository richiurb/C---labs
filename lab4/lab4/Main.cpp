#include <iostream>
#include "Segment.h"

using namespace std;

int main() {
	Segment a, b;
	b.initFromDialog();
	if (a == b) {
		cout << "YEES";
	}
	else {
		cout << "Fe";
	}
	return 0;
}
