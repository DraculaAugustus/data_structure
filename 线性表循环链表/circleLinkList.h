#pragma once

class CircleLinkNode
{
public:
	int data;
	CircleLinkNode* next;

public:
	CircleLinkNode();
	CircleLinkNode(int value);
	~CircleLinkNode();
};

class CircleLinkList
{
private:
	CircleLinkNode* head;
	int size;

public:
	CircleLinkList();
	~CircleLinkList();

	//添加
	void pushBack(int value);	//尾部添加
	void pushFront(int value);	//头部添加
	void insertByIndex(int index, int value);	//指定位置前插入元素

	//打印链表
	void printCircleLinkList();

	//查询
	int getSize();	//返回链表长度
	int front();	//返回第一个元素的值
	int back();		//返回最后一个元素的值
	int findByIndex(int index);	//返回指定位置元素的值

	//删除
	void popFront();	//删除第一个元素
	void popBack();		//删除最后一个元素

	//约瑟夫环问题
	void yuesefu();
};