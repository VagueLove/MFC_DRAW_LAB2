#pragma once
#include "Graphics.h"
class CLine :public Graphics
{
public:
	CLine();
	//设置起点
	void Set_start_point(CPoint p);
	//设置终点
	void Set_end_point(CPoint p);
	//获取起点
	CPoint GetStart();
	//获取终点
	CPoint GetEnd();
	//绘制直线
	void Draw(CDC* pDC);
	int Selected(CPoint p);
private:
	//起点
	CPoint Line_start_point;
	//终点
	CPoint Line_end_point;
};

