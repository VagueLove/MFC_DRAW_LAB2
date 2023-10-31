#pragma once
#include "Graphics.h"
#define MAX_COUNT 100
class PolyLine : public Graphics
{
public:
	PolyLine();
	~PolyLine();
	//≈–∂œ «∑ÒÕÍ≥…
	bool over;
	bool firstset;
	void Get_point(CPoint p);
	void Set_point(CPoint p);
	void ReDraw(CDC* pDC);
	int Get_num();
	CPoint pointbox[MAX_COUNT] = { 0 };

	void Draw(CDC* pDC);
	int Selected(CPoint p);
private:
	CPoint now_point;
	CPoint next_point;
	int num;
};