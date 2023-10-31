#pragma once
#include "CLine.h"
#include "CQuare.h"
#include "CCircle.h"
#include "Curve.h"
#include "CSlist.h"
#include "PolyLine.h"
class DataDraw
{
public:
	DataDraw() = default;
	~DataDraw() = default;
	static DataDraw* Get_Draw(int type);
	virtual void Draw(Node*, CDC*) = 0;
	static DataDraw* Get_Data();
};

class LineDraw : public DataDraw
{
public:
	LineDraw() = default;
	~LineDraw() = default;
	void Draw(Node*, CDC*);
};

class CquareDraw : public DataDraw
{
public:
	CquareDraw() = default;
	~CquareDraw() = default;
	void Draw(Node*, CDC*);
};

class CircleDraw : public DataDraw
{
public:
	CircleDraw() = default;
	~CircleDraw() = default;
	void Draw(Node*, CDC*);
};

class CurveDraw :public DataDraw
{
public:
	CurveDraw() = default;
	~CurveDraw() = default;
	void Draw(Node*, CDC*);
};
class PolyLineDraw :public DataDraw
{
public:
	PolyLineDraw() = default;
	~PolyLineDraw() = default;
	void Draw(Node*, CDC*);
};


