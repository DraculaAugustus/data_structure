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
	//生成新节点
	LinkArrayNode* newNode = new LinkArrayNode(value);

	//让指针指向最后一个节点
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
	//节点编号从0开始，最大节点为 size-1
	if (index < 0 || index >= size)
	{
		return;
	}

	//生成新节点
	LinkArrayNode* newNode = new LinkArrayNode(value);

	//移动指针到index指定的节点的前一个节点
	LinkArrayNode* curr = head;;

	for (int i = 0; i < index; i++)
	{
		curr = curr->next;
	}
	//在找到的位置插入新节点
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
	int index = -1;	//如果没有找到元素，则返回-1

	
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

	cout << "链表的长度是：" << list->getSize() << endl;
	cout << "链表中的第三个元素是：" << list->findByindex(7) << endl;
	cout << "链表中元素88的索引是：" << list->findIndexByValue(88) << endl;
	cout << "链表中的第一个元素是：" << list->front() << endl;
	cout << "链表中的最后一个元素是：" << list->back() << endl;

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
	cout << "链表中最大值为：" << max << endl;

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