#pragma once
#include "Graphics.h"
class CCircle : public Graphics
{
public:
	CCircle();
	//��ȡԲ��
	CPoint GetCenter();
	//��ȡ�뾶
	int GetRadius();
	//���ð뾶
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
 