#pragma once
struct Node
{
	int now_RGB = 0;//������ɫ
	void* data;
	int now_type;//�洢��״
	Node* next = nullptr;
};
class CSlist
{
public:
	CSlist();
	Node* head;
	//ͷ��
	void InputFront(Node* Pelem);
	//β��
	void InputTail(Node* Pelem);
	//��ȡ������
	int Length()const;
	//�ж������Ƿ�Ϊ��
	bool IsEmpty()const;
	//���������
	void MakeEmpty();
	//����i������ȡ��
	Node* GetElement(int i);
	//�ڵڼ�����ֵ֮������½ڵ�
	void Input_behind_pos(Node* Pelem, int pos);
	//�ڵڼ�����ֵ֮ǰ�����½ڵ�
	void Input_before_pos(Node* Pelem, int pos);

	void Delete(int pos);

};