#pragma once
#include"CLine.h"
#include"CSlist.h"
class CDrawVerLine
{
public:
	CDrawVerLine();
	//��ȡ����
	void SetVerFoot();
	//���ù����ߵ�һ��
	void SetPoint(CPoint p);
	//����Ҫ�����ߵ�ֱ��
	void SetLine(CLine* line);
	//������
	void Draw(CDC* pDC, CSlist &list);
	//���㴹��
	void Calc_HangingFeet(double x1, double y1, double x2, double y2, double x3, double y3, double& foot_x, double& foot_y);
	//������������
	double Calc_VectorLength(double x, double y);
	//������������ֵ
	void Calc_VectorDifference(double x1, double y1, double x2, double y2, double& diff_x, double& diff_y);
	//�������
	double PointMultiply(double x1, double y1, double x2, double y2);

	bool IsPointSet;//�ж��Ƿ������ù����ߵ�һ��
	bool IsLineSet;//�ж��Ƿ���ѡ��Ҫ�����ߵ���
private:
	CPoint point;
	CPoint HangingFeet;
	CLine* line;
};