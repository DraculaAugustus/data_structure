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

	//查询
	int getSize();	//获取链表的长度
	int findByindex(int index);	//返回指定位置的元素
	int findIndexByValue(int value);	//返回指定元素的索引
	int front();	//返回第一个元素
	int back();	//返回最后一个元素

	//删除
	void popBack();	//删除最后一个元素
	void delByIndex(int index);	//删除指定位置的元素


};