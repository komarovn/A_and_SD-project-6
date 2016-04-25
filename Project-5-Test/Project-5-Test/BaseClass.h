#ifndef _BASECLASS_H_
#define _BASECLASS_H_

#include "iostream"
#include "stringconvert.h"
#include <vcclr.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Base
{
public:
	enum FigureType {TPoint, TLine, TRectangle, TArc};
protected:
	FigureType type;
	string name;
	gcroot <Color> color;
	int size;
	bool visible;
	int epsilon;
	int refCount;
public:
	virtual void Draw(Graphics^ g) = 0;
	virtual void Fill(Graphics^ g) = 0;
	virtual void Move(int dx, int dy) = 0;
	virtual void SetNewPlace(int x, int y) = 0;
	virtual void AddRef() = 0;
	virtual void DelRef() = 0;
	virtual int Distance(int x, int y) = 0;
	FigureType GetType() const {return type;};
	string GetName() const {return name;};
	Color GetColor() const {return color;};
	void SetColor(Color c) {color = c;};
	int GetSize() const {return size;};
	void SetSize(int s) {size = s; epsilon = 3 * s;};
	bool GetVisible() const {return visible;};
	void Show() {visible = true;};
	void Hide() {visible = false;};
	int GetRefCount() const {return refCount;};
};

#endif