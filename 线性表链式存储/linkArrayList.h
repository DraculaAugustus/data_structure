#pragma once

//链式存储节点
class LinkArrayNode
{
public:
	int data;
	LinkArrayNode* next;

public:
	LinkArrayNode();
	LinkArrayNode(int value);
	~LinkArrayNode();
};

//链表
class LinkArrayList
{
	LinkArrayNode* head;
	int size;
public:
	LinkArrayList();
	~LinkArrayList();

	//添加
	void pushBack(int value);	//尾部添加元素
	void insertValueByIndex(int index, int value);	//指定位置前插入元素

	//打印链表
	void printArrayList();


	int getSize();
};