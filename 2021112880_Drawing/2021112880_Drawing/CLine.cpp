#include "pch.h"
#include "CLine.h"

CLine::CLine()
{

}

void CLine::Set_start_point(CPoint p)
{
	Line_start_point = p;
}


void CLine::Set_end_point(CPoint p)
{
	Line_end_point = p;
}


void CLine::Draw(CDC* pDC)
{
	pDC->MoveTo(Line_start_point);
	pDC->LineTo(Line_end_point);
}

CPoint CLine::GetStart()
{
	return Line_start_point;
}
CPoint CLine::GetEnd()
{
	return Line_end_point;
}

int CLine::Selected(CPoint p)
{

	double a = Line_end_point.y - Line_start_point.y;
	double b = Line_start_point.x - Line_end_point.x;
	double c = Line_end_point.x * Line_start_point.y - Line_start_point.x * Line_end_point.y;

	// 使用点到直线距离公式计算距离
	int d = fabs((a * p.x + b * p.y + c) / sqrt(a * a + b * b));

	if (d < 5 && p.x >= min(Line_start_point.x, Line_end_point.x) && p.x <= max(Line_start_point.x, Line_end_point.x))
		return 1;
	else
		return 0;
}
