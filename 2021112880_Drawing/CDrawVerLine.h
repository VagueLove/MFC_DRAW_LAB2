#pragma once
#include"CLine.h"
#include"CSlist.h"
class CDrawVerLine
{
public:
	CDrawVerLine();
	void GetVerFoot();
	void GetPoint(CPoint p);
	void GetLine(CLine* l);
	void Draw(CDC* pDC, CSlist &list);
	void calculate_foot(double x1, double y1, double x2, double y2, double x3, double y3, double& foot_x, double& foot_y);
	double vector_length(double x, double y);
	void vector_difference(double x1, double y1, double x2, double y2, double& diff_x, double& diff_y);
	double dot_product(double x1, double y1, double x2, double y2);
	bool pointset;
	bool lineset;
private:
	CPoint point;
	CPoint foot;
	CLine* line;
};