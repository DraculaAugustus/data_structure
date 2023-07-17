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

void LinkArrayList::insertValueByIndex(int index, int value)
{
	LinkArrayNode* newNode = new LinkArrayNode(value);

	LinkArrayNode* temp = head;;

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = temp->next;

}

void test_linkArrayList()
{
	LinkArrayList* lst = new LinkArrayList();

	for (int i = 0; i < 10; i++)
	{
		lst->pushBack(rand() % 101);
	}
	lst->printArrayList();
	cout << "元素个数为：" << lst->getSize() << endl;

	//lst->insertValueByIndex(5, 23);
	//lst->printArrayList();

	delete lst;
}

int main()
{
	srand((unsigned)time(NULL));

	test_linkArrayList();

	return 0;
}