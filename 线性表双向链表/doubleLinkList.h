#pragma once

class DoubleLinkNode
{
public:
	int data;
	DoubleLinkNode* prev;
	DoubleLinkNode* next;
public:
	DoubleLinkNode();
	DoubleLinkNode(int value);
	~DoubleLinkNode();
};

class DoubleLinkList
{
private:
	DoubleLinkNode* head;
	int size;
public:
	DoubleLinkList();
	~DoubleLinkList();

	//插入
	void pushBack(int value);	//在链表最后插入
	void pushFront(int value);	//在链表最开始插入
	void insertByIndex(int index, int value);	//在指定位置插入

	//查找
	int getSize();	//获取链表长度
	int front();	//获取第一个元素的值
	int back();	//获取最后一个元素的值
	int findByIndex(int index);	//获取指定位置的元素的值

	//删除
	void popFront(); //删除链表中的第一个元素
	void popBack();	//删除链表中的最后一个元素
	//删除指定位置的元素

	//打印双向链表
	void printDoubleLinkList();
};