#pragma once
class CLine
{
public:
	CLine();
	//�������
	void Set_start_point(CPoint p);
	//�����յ�
	void Set_end_point(CPoint p);
	//��ȡ���
	CPoint GetStart();
	//��ȡ�յ�
	CPoint GetEnd();

	int Selected(CPoint p);
private:
	//���
	CPoint Line_start_point;
	//�յ�
	CPoint Line_end_point;


public:
	//����ֱ��
	void Draw(CDC* pDC);
};

