#include "pch.h"
#include "CCircle.h"
CCircle::CCircle()
{
	is_CenPoint = false;
}
void CCircle::Set_CenPoint(CPoint p)
{
	is_CenPoint = true;
	m_CenPoint = p;
}

void CCircle::Set_Radius(int Radius)
{
	this->m_Radius = Radius;
}
void CCircle::Get_Radius(CPoint p)
{
	if (is_CenPoint)
	{
		double x = (p.x - m_CenPoint.x) * (p.x - m_CenPoint.x);
		double y = (p.y - m_CenPoint.y) * (p.y - m_CenPoint.y);
		m_Radius = (int)sqrt(x + y);
	}
}
void CCircle::Draw(CDC* pDC)
{
	pDC->Ellipse(m_CenPoint.x - m_Radius, m_CenPoint.y - m_Radius, m_CenPoint.x + m_Radius, m_CenPoint.y + m_Radius);
}

CPoint CCircle::GetCenter()
{
	return m_CenPoint;
}
int CCircle::GetRadius()
{
	return m_Radius;
}

int CCircle::Selected(CPoint p)
{
	double x = (p.x - m_CenPoint.x) * (p.x - m_CenPoint.x);
	double y = (p.y - m_CenPoint.y) * (p.y - m_CenPoint.y);
	double l = sqrt(x + y);
	if (fabs(l - m_Radius) < 5)
	{
		return 1;
	}
	else
		return 0;
}
