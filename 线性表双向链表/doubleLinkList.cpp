#include <iostream>
#include "doubleLinkList.h"
#include <vld.h>

using namespace std;

DoubleLinkNode::DoubleLinkNode()
{
	data = NULL;
	prev = nullptr;
	next = nullptr;
}

DoubleLinkNode::DoubleLinkNode(int value)
{
	data = value;
	prev = next = nullptr;
}

DoubleLinkNode::~DoubleLinkNode()
{
	prev = next = nullptr;
	data = NULL;
}

DoubleLinkList::DoubleLinkList()
{
	head = new DoubleLinkNode;
	size = 0;
}

DoubleLinkList::~DoubleLinkList()
{
	DoubleLinkNode* curr = head;
	DoubleLinkNode* temp;

	while (curr != nullptr)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}

	size = 0;
}

void DoubleLinkList::pushBack(int value)
{
	//�½��ڵ�
	DoubleLinkNode* newNode = new DoubleLinkNode(value);

	//�ҵ����һ���ڵ�
	DoubleLinkNode* curr = head;

	while (curr->next != nullptr)
	{
		curr = curr->next;
	}
	curr->next = newNode;
	newNode->prev = curr;

	size++;
}

void DoubleLinkList::printDoubleLinkList()
{
	DoubleLinkNode* curr = head;

	while (curr->next != nullptr)
	{
		curr = curr->next;
		cout << curr->data << " ";
	}
	cout << endl;
}

void DoubleLinkList::pushFront(int value)
{
	//�½��ڵ�
	DoubleLinkNode* newNode = new DoubleLinkNode(value);

	if (head->next != nullptr)
	{
		head->next->prev = newNode;
		newNode->prev = head;
		newNode->next = head->next;
		head->next = newNode;
	}
	else
	{
		head->next = newNode;
		newNode->prev = head;
	}

	size++;
}

void DoubleLinkList::insertByIndex(int index, int value)
{
	if (index < 0 || index >= size)
	{
		return;
	}

	//�½��ڵ�
	DoubleLinkNode* newNode = new DoubleLinkNode(value);
	//�ҵ������λ��
	DoubleLinkNode* curr = head;
	for (int i = 0; i < index; i++)
	{
		curr = curr->next;
	}

	curr->next->prev = newNode;
	newNode->next = curr->next;
	newNode->prev = curr;
	curr->next = newNode;

	size++;
}

int DoubleLinkList::getSize()
{
	return size;
}

int DoubleLinkList::front()
{
	if (head->next != nullptr)
	{
		return head->next->data;
	}
	return NULL;
}
int DoubleLinkList::back()
{
	DoubleLinkNode* curr = head;
	while (curr->next != nullptr)
	{
		curr = curr->next;
	}
	return curr->data;
}

int DoubleLinkList::findByIndex(int index)
{
	if (index < 0 || index >= size)
	{
		return NULL;
	}

	DoubleLinkNode* curr = head;
	//�ҵ�index�ڵ�
	for (int i = 0; i <= index; i++)
	{
		curr = curr->next;
	}
	return curr->data;
}

void DoubleLinkList::popFront()
{
	if (head->next == nullptr)
	{
		return;
	}

	DoubleLinkNode* temp = head->next;
	if (temp->next != nullptr)
	{
		temp->next->prev = head;
	}
	head->next = temp->next;

	delete temp;

	size--;
}

void DoubleLinkList::popBack()
{
	if (head->next ==  nullptr)
	{
		return;
	}

	//�ҵ����һ��Ԫ��
	DoubleLinkNode* curr = head;
	while (curr->next != nullptr)
	{
		curr = curr->next;
	}

	curr->prev->next = nullptr;
	delete curr;

	size--;
}

void test_doublelink()
{
	DoubleLinkList* doublelink = new DoubleLinkList;

	for (int i = 0; i < 9; i++)
	{
		doublelink->pushBack(i + 30);
	}

	doublelink->printDoubleLinkList();

	doublelink->pushFront(29);
	doublelink->printDoubleLinkList();

	doublelink->insertByIndex(4, 88);
	doublelink->printDoubleLinkList();

	cout << "˫������Ĵ�СΪ��" << doublelink->getSize() << endl;
	cout << "˫������ĵ�һ���ڵ�Ϊ��" << doublelink->front() << endl;
	cout << "˫����������һ���ڵ�Ϊ��" << doublelink->back() << endl;
	cout << "˫������ĵ�8�ڵ�Ϊ��" << doublelink->findByIndex(7) << endl;

	doublelink->popFront();
	doublelink->printDoubleLinkList();

	doublelink->popBack();
	doublelink->printDoubleLinkList();

	delete doublelink;
}

DoubleLinkList* reverseDoubleList(DoubleLinkList* list)
{
	DoubleLinkList* newList = new DoubleLinkList;
	while (list->getSize() > 0)
	{
		//newList->pushBack(list->back());
		//list->popBack();

		newList->pushFront(list->front());
		list->popFront();
	}
	delete list;
	return newList;
}

void mytest()
{
	srand((unsigned)time(NULL));
	DoubleLinkList* doublelist = new DoubleLinkList;

	for (int i = 0; i < 10; i++)
	{
		doublelist->pushBack(rand() % 101);
	}
	doublelist->printDoubleLinkList();

	doublelist = reverseDoubleList(doublelist);
	doublelist->printDoubleLinkList();

	delete doublelist;
}

int main()
{
	//test_doublelink();
	mytest();

	return 0;
}