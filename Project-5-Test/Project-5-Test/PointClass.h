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
	PointC(const PointC &p);
	~PointC() {};
	PointC &operator=(const PointC &p);
	void Draw(Graphics^ g);
	void Move(int dx, int dy);
	void SetNewPlace(int x, int y);
	void AddRef();
	void DelRef();
	int Distance(int x, int y);
	int GetX() const {return xCoord;};
	int GetY() const {return yCoord;};
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

PointC::PointC(const PointC &p)
{
	type = TPoint;
	name = p.name;
	xCoord = p.xCoord;
	yCoord = p.yCoord;
	color = p.color;
	visible = 1;
	SetSize(p.size);
	refCount = 1;
}

PointC &PointC::operator=(const PointC &p)
{
	type = TPoint;
	name = p.name;
	xCoord = p.xCoord;
	yCoord = p.yCoord;
	color = p.color;
	visible = 1;
	SetSize(p.size);
	refCount = 1;
	return *this;
}

void PointC::Draw(Graphics^ g)
{
	g->FillEllipse(Brushes::Black, xCoord, yCoord, 2 * size, 2 * size);
	g->DrawString(Convert::ToString(name.c_str()), gcnew System::Drawing::Font("Arial", 11), System::Drawing::Brushes::Blue, Point(xCoord, yCoord));
}

void PointC::Move(int dx, int dy)
{
	xCoord += dx;
	yCoord += dy;
}

void PointC::SetNewPlace(int x, int y)
{
	xCoord = x;
	yCoord = y;
}

void PointC::AddRef()
{
	refCount++;
}

void PointC::DelRef()
{
	refCount--;
}

int PointC::Distance(int x, int y)
{
	int distance = (x - xCoord) * (x - xCoord) + (y - yCoord) * (y - yCoord);
	if (distance < epsilon * epsilon)
		return 1;
	else
		return 0;
}

#endif