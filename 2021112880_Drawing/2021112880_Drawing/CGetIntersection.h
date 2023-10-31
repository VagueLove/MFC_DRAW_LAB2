#pragma once
#include"CCircle.h"
#include"CLine.h"
#include"CSlist.h"
class CGetIntersection
{
public:
	CGetIntersection();
	void Set_GraphicsPos_List_1(int d);
	void Set_GraphicsPos_List_2(int d);
	//������Բ�Ľ���
	void Circle_Circle(CCircle* c1,CCircle* c2);
	//������ֱ�߽���
	void Line_Line(CLine* L1,CLine* L2);
	//����ֱ����Բ�Ľ���
	void Circle_Line(CCircle* c,CLine* L);

	void CalcCC(CSlist& list);
	void CalcCL(CSlist& list);
	void CalcLC(CSlist& list);
	void CalcLL(CSlist& list);

	bool IsSet_Node_Pos_1;
	bool IsSet_Node_Pos_2;
	int type_1;
	int type_2;
	//����
	CPoint Intersection_1;
	CPoint Intersection_2;
private:
	int GraphicsPos_List_1;
	int GraphicsPos_List_2;
};