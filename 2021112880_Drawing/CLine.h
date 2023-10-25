#pragma once
class CLine
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

	int Selected(CPoint p);
private:
	//起点
	CPoint Line_start_point;
	//终点
	CPoint Line_end_point;


public:
	//绘制直线
	void Draw(CDC* pDC);
};

