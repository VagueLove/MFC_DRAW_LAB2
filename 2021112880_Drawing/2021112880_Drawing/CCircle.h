#pragma once
#include "Graphics.h"
class CCircle : public Graphics
{
public:
	CCircle();
	//获取圆心
	CPoint GetCenter();
	//获取半径
	int GetRadius();
	//设置半径
	void Set_Radius(int Radius);
	void Set_CenPoint(CPoint p);
	void Get_Radius(CPoint p);

	void Draw(CDC *pDC);
	int Selected(CPoint p);

private:
	CPoint m_CenPoint;
	int m_Radius;
	bool is_CenPoint;
}; 
 