#ifndef HEXAGON_H
#define HEXAGON_H

#include "Base.h"

class Hexagon : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject {
private:
	CVector2D A, B, C, D, E, F;
	double mas;
	double side(CVector2D, CVector2D);
	double square_triangle(double, double, double);
public:
	double perimeter();
	double square();
	double mass() const;
	CVector2D position();
	bool operator== (const IPhysObject&) const;
	bool operator< (const IPhysObject&) const;
	void draw();
	void initFromDialog();
	const char* classname();
	unsigned int size();
};

#endif HEXAGON_H
