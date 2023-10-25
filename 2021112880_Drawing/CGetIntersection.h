#pragma once
#include"CCircle.h"
#include"CLine.h"
#include"CSlist.h"
class CGetIntersection
{
public:
	CGetIntersection();
	void Set_data1(int d);
	void Set_data2(int d);
	void Circle_Circle(CCircle* c1,CCircle* c2);
	void Line_Line(CLine* L1,CLine* L2);
	void Circle_Line(CCircle* c,CLine* L);
	void CalCC(CSlist list);
	void CalCL(CSlist list);
	void CalLC(CSlist list);
	void CalLL(CSlist list);
	bool dt1set;
	bool dt2set;
	int Obj1;
	int Obj2;
	CPoint is1;
	CPoint is2;
private:
	int data1;
	int data2;
};