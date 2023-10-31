#pragma once
class Graphics 
{
public:
	Graphics() = default;
	~Graphics() = default;
	//绘图函数
	virtual void Draw(CDC* pDC) = 0;
	//是否选择函数
	virtual int Selected(CPoint p) = 0;
	//填充函数
	void Padding();
};
