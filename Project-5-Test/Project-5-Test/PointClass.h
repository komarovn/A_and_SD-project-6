#ifndef _POINTCLASS_H_
#define _POINTCLASS_H_

#include "BaseClass.h"

class PointC: public Base
{
private: 
	int xCoord;
	int yCoord;
public:
	PointC(string Name = "", int X = 0, int Y = 0, Color c = Color::Black, int Size = 3);
	
};

PointC::PointC(string Name, int X, int Y, Color c, int Size)
{
	type = TPoint;
	name = Name;
	xCoord = X;
	yCoord = Y;
	color = c;
	visible - true;
	SetSize(Size);
	refCount = 1;
}

#endif