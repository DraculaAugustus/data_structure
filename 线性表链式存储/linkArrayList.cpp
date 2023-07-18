#include <iostream>
#include "linkArrayList.h"

using namespace std;

LinkArrayNode::LinkArrayNode()
{
	data = NULL;
	next = nullptr;
}

LinkArrayNode::LinkArrayNode(int value)
{
	data = value;
	next = nullptr;
}

LinkArrayNode::~LinkArrayNode()
{
	next = nullptr;
	data = NULL;
}

LinkArrayList::LinkArrayList()
{
	head = new LinkArrayNode();
	size = 0;
}

LinkArrayList::~LinkArrayList()
{
	LinkArrayNode* curr = head;
	LinkArrayNode* temp;
	while (curr != nullptr)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}

	size = 0;
}

void LinkArrayList::pushBack(int value)
{
	//�����½ڵ�
	LinkArrayNode* newNode = new LinkArrayNode(value);

	//��ָ��ָ�����һ���ڵ�
	LinkArrayNode* temp = head;

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	temp->next = newNode;

	size++;
}

void LinkArrayList::insertValueByIndex(int index, int value)
{
	//�ڵ��Ŵ�0��ʼ�����ڵ�Ϊ size-1
	if (index < 0 || index >= size)
	{
		return;
	}

	//�����½ڵ�
	LinkArrayNode* newNode = new LinkArrayNode(value);

	//�ƶ�ָ�뵽indexָ���Ľڵ��ǰһ���ڵ�
	LinkArrayNode* curr = head;;

	for (int i = 0; i < index; i++)
	{
		curr = curr->next;
	}
	//���ҵ���λ�ò����½ڵ�
	newNode->next = curr->next;
	curr->next = newNode;

	size++;
}

void::LinkArrayList::printArrayList()
{
	LinkArrayNode* curr = head;

	while (curr->next != nullptr)
	{
		curr = curr->next;
		cout << curr->data << " ";
	}
	cout << endl;
}

int LinkArrayList::getSize()
{
	return size;
}

int LinkArrayList::findByindex(int index)
{
	if (index < 0 || index >= size)
	{
		return NULL;
	}

	LinkArrayNode* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	
	return temp->next->data;
}

int LinkArrayList::findIndexByValue(int value)
{
	int index = -1;	//���û���ҵ�Ԫ�أ��򷵻�-1

	
	LinkArrayNode* temp = head->next;
	while (temp != nullptr)
	{
		index++;
		if (temp->data == value)
		{
			return index;
		}
		temp = temp->next;
	}
	return -1;
}

int LinkArrayList::front()
{
	if (head->next != nullptr)
	{
		return head->next->data;
	}
	return NULL;
}

int LinkArrayList::back()
{
	if (head->next == nullptr)
	{
		return NULL;
	}
	LinkArrayNode* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	return temp->data;
}

void LinkArrayList::popBack()
{
	if (head->next == nullptr)
	{
		return;
	}

	LinkArrayNode* curr = head;
	LinkArrayNode* prev = nullptr;

	while (curr->next != nullptr)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = nullptr;
	delete curr;

	size--;
}

void LinkArrayList::delByIndex(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}

	LinkArrayNode* curr = head;
	for (int i = 0; i < index; i++)
	{
		curr = curr->next;
	}

	LinkArrayNode* temp = curr->next;
	curr->next = curr->next->next;

	delete temp;
	size--;
}


void test_linklist()
{
	LinkArrayList* list = new LinkArrayList();

	for (int i = 0; i < 7; i++)
	{
		list->pushBack(77 + i);
	}
	list->printArrayList();

	list->insertValueByIndex(2, 88);
	list->printArrayList();

	cout << "����ĳ����ǣ�" << list->getSize() << endl;
	cout << "�����еĵ�����Ԫ���ǣ�" << list->findByindex(7) << endl;
	cout << "������Ԫ��88�������ǣ�" << list->findIndexByValue(88) << endl;
	cout << "�����еĵ�һ��Ԫ���ǣ�" << list->front() << endl;
	cout << "�����е����һ��Ԫ���ǣ�" << list->back() << endl;

	list->popBack();
	list->printArrayList();

	list->delByIndex(3);
	list->printArrayList();

	delete list;
}

int findMax(LinkArrayList* lst)
{
	int max = lst->front();
	for (int i = 0; i < lst->getSize(); i++)
	{
		if (max < lst->findByindex(i))
		{
			max = lst->findByindex(i);
		}
	}
	return max;
}

void testFunc()
{
	LinkArrayList* lst = new LinkArrayList;
	
	for (int i = 0; i < 10; i++)
	{
		lst->pushBack(rand() % 101);
	}
	lst->printArrayList();

	int max = findMax(lst);
	cout << "���������ֵΪ��" << max << endl;

	int index = lst->findIndexByValue(max);
	lst->delByIndex(index);
	lst->printArrayList();

}

int main()
{
	srand((unsigned)time(NULL));

	//test_linklist();
	testFunc();

	return 0;
}