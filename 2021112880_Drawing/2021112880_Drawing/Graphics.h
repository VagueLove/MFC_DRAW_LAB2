#pragma once
class Graphics 
{
public:
	Graphics() = default;
	~Graphics() = default;
	//��ͼ����
	virtual void Draw(CDC* pDC) = 0;
	//�Ƿ�ѡ����
	virtual int Selected(CPoint p) = 0;
	//��亯��
	void Padding();
};
