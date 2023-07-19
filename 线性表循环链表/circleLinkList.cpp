#include <iostream>
#include "circleLinkList.h"
#include <vld.h>

using namespace std;

CircleLinkNode::CircleLinkNode()
{
	data = 0;
	next = nullptr;
}

CircleLinkNode::CircleLinkNode(int value)
{
	data = value;
	next = nullptr;
}

CircleLinkNode::~CircleLinkNode()
{
	next = nullptr;
}

CircleLinkList::CircleLinkList()
{
	head = new CircleLinkNode;
	head->next = head;
	size = 0;
}

CircleLinkList::~CircleLinkList()
{
	CircleLinkNode* curr = head->next;
	CircleLinkNode* temp;
	while (curr != head)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	delete head;
	size = 0;
}

void CircleLinkList::pushBack(int value)
{
	//新建节点
	CircleLinkNode* newNode = new CircleLinkNode(value);
	//找到链表中最后一个节点
	CircleLinkNode* curr = head;
	while (curr->next != head)
	{
		curr = curr->next;
	}
	
	curr->next = newNode;
	newNode->next = head;

	size++;
}

void CircleLinkList::pushFront(int value)
{
	//新建节点
	CircleLinkNode* newNode = new CircleLinkNode;

	newNode->next = head->next;
	head->next = newNode;

	size++;
}

void CircleLinkList::insertByIndex(int index, int value)
{
	if (index < 0 || index >= size)
	{
		return;
	}

	//新建节点
	CircleLinkNode* newNode = new CircleLinkNode(value);

	//找到插入位置
	CircleLinkNode* curr = head;
	for (int i = 0; i < index; i++)
	{
		curr = curr->next;
	}

	newNode->next = curr->next;
	curr->next = newNode;

}

void CircleLinkList::printCircleLinkList()
{
	CircleLinkNode* curr = head;
	while (curr->next != head)
	{
		curr = curr->next;
		cout << curr->data << " ";
	}
	cout << endl;
}

int CircleLinkList::getSize()
{
	return size;
}

int CircleLinkList::front()
{
	if (size > 0)
	{
		return head->next->data;
	}
	return NULL;
}

int CircleLinkList::back()
{
	if (size > 0)
	{
		CircleLinkNode* curr = head;
		while (curr->next != head)
		{
			curr = curr->next;
		}
		return curr->data;
	}

	return NULL;
}

int CircleLinkList::findByIndex(int index)
{
	if (index < 0 || index >= size)
	{
		return NULL;
	}

	CircleLinkNode* curr = head;
	for (int i = 0; i <= index; i++)
	{
		curr = curr->next;
	}

	return curr->data;
}

void CircleLinkList::popFront()
{
	if (head->next == head)
	{
		return;
	}

	//CircleLinkNode* curr = head->next;
	//CircleLinkNode* temp;
	//head->next = curr->next;
	//temp = curr;
	//delete temp;
	CircleLinkNode* temp = head->next;
	head->next = temp->next;
	delete temp;

	size--;
}

void CircleLinkList::popBack()
{
	if (head->next == head)
	{
		return;
	}

	//找到最后一个节点和它的前一个节点
	CircleLinkNode* curr = head;
	CircleLinkNode* prev = nullptr;
	while (curr->next != head)
	{
		prev = curr;
		curr = curr->next;
	}
	
	delete curr;
	prev->next = head;

	size--;
}

void CircleLinkList::yuesefu()
{
	CircleLinkNode* curr = head;
	CircleLinkNode* prev = nullptr;

	while (size > 0)
	{
		for (int i = 1; i <= 3; i++)
		{
			prev = curr;
			curr = curr->next;
			if (curr == head)	//越过头节点
			{
				curr = head->next;
			}
		}
		prev->next = curr->next;
		cout << curr->data << "出列" << endl;
		delete curr;

		curr = prev;
		size--;
	}

}

void test_circlelinklist()
{
	CircleLinkList* cl = new CircleLinkList;
	for (int i = 0; i < 7; i++)
	{
		cl->pushBack(i + 10);
	}
	cl->printCircleLinkList();

	cl->insertByIndex(3, 33);
	cl->printCircleLinkList();

	cout << "链表的长度是：" << cl->getSize() << endl;
	cout << "链表中第一个元素的值：" << cl->front() << endl;
	cout << "链表中最后一个元素的值：" << cl->back() << endl;
	cout << "链表中第三个元素的值：" << cl->findByIndex(2) << endl;

	cl->popBack();
	cl->printCircleLinkList();

	cl->popFront();
	cl->printCircleLinkList();

	delete cl;
}


void test_yusefu()
{
	CircleLinkList* clist = new CircleLinkList;
	for (int i = 0; i < 8; i++)
	{
		clist->pushBack(i + 1);
	}
	clist->printCircleLinkList();
	clist->yuesefu();

	//delete clist;
}

int main()
{
	//test_circlelinklist();
	test_yusefu();

	return 0;
}