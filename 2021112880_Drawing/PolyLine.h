#pragma once
#define MAX_COUNT 100
class PolyLine
{
public:
	PolyLine();
	~PolyLine();
	//≈–∂œ «∑ÒÕÍ≥…
	bool over;
	bool firstset;
	void Get_point(CPoint p);
	void Set_point(CPoint p);
	void Draw(CDC* pDC);
	void ReDraw(CDC* pDC);
	int Selected(CPoint p);
	int Get_num();
	CPoint pointbox[MAX_COUNT] = { 0 };
private:
	CPoint now_point;
	CPoint next_point;
	int num;
};