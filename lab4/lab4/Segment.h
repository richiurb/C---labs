#ifndef SEGMENT_H
#define SEGMENT_H

#include "Base.h"

class Segment : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject {
private:
	CVector2D first;
	CVector2D second;
	double mas;
public:
	double perimeter();
	double square();
	double mass();
	CVector2D position();
	bool operator== (const IPhysObject&) const;
	bool operator< (const IPhysObject&) const;
	void draw();
	void initFromDialog();
	const char* classname();
	unsigned int size();
};

#endif SEGMENT_H

