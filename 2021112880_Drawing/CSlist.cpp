#include "pch.h"
#include "CSlist.h"

#include<iostream>
#include<stdlib.h>
using namespace std;

CSlist::CSlist()
{
	first = nullptr;
}

void CSlist::InputTail(Node* Pelem)
{
	if (Pelem == nullptr)  return;
	if (first == nullptr)
	{
		first = Pelem;
		return;
	}

	Node* temp = first;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = Pelem;
}


void CSlist::InputFront(struct Node* Pelem)
{
	if (Pelem == nullptr)  return;
	Pelem->next = first;
	first = Pelem;
}

int CSlist::Length()const
{
	if (first == nullptr)  
		return 0;

	struct Node* n = first;
	int length = 1;
	while (n->next)
	{
		++length;
		n = n->next;
	}
	return length;
}

bool CSlist::IsEmpty()const
{
	return first == nullptr ? true : false;
}

void CSlist::MakeEmpty()
{
	struct Node* d;
	while (first)
	{
		d = first;
		first = first->next;
		delete d;
	}
}

struct Node* CSlist::GetElement(int i)
{
	int j = 0;
	struct Node* L = first;
	if (i <= 0 || i > Length()) cout << "error" << endl;

	while (L)
	{
		++j;
		if (j == i)
		{
			return L;
		}
		else  L = L->next;
	}
}

void CSlist::Input_behind_pos(struct Node* Pelem, int pos)
{

	struct Node* d = GetElement(pos + 1);
	Pelem->next = d;//新节点的next指向原来的下一个节点
	struct Node* c = GetElement(pos);
	c->next = Pelem;//上一个节点的next指向新节点
}

void CSlist::Input_before_pos(struct Node* Pelem, int pos)
{

	struct Node* c = GetElement(pos - 1);
	c->next = Pelem;//上一个节点的next指向新节点
	struct Node* d = GetElement(pos);
	Pelem->next = d;//新节点的next指向原来的下一个节点
}

void CSlist::Delete(int pos)
{
	struct Node* a = GetElement(pos - 1);
	struct Node* b = GetElement(pos);
	struct Node* c = GetElement(pos + 1);
	a->next = c;
	delete b;
}
