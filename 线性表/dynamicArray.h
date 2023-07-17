#pragma once

class DynamicArray
{
private:
	int* data;
	int size;
	int capacity;
	
public:
	DynamicArray();
	DynamicArray(int capacity);
	~DynamicArray();

	//尾部插入元素
	void pushBack(int value);

	//根据索引插入元素
	void insertByIndex(int index, int value);
	
	//打印数组
	void printArray();

	//查找
	int getCapacity();	//返回数组的容量

	int getSize();	//返回数组的大小

	int getValueByindex(int index);	//返回指定元素的值

	int front();	//返回数组的第一个元素

	int back();	//返回数组的最后一个元素

	//删除元素
	void popBack();	//删除最后一个元素

	void delByIndex(int index);	//删除指定位置的元素

};