#include<iostream>
#include "dynamicArray.h"

using namespace std;

DynamicArray::DynamicArray()
{
	capacity = 5;
	data = new int[capacity];
	size = NULL;
}

DynamicArray::DynamicArray(int capacity)
{
	this->capacity = capacity;
	data = new int[capacity];
	size = 0;
}

DynamicArray::~DynamicArray()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	size = 0;
	capacity = 0;
}

void DynamicArray::pushBack(int value)
{
	if (capacity == size)	//说明数组容量已满，需要扩容
	{
		//容量增加一倍
		int* temp_data = new int[capacity * 2];
		
		//把旧数据拷贝到新开辟的空间中
		for (int i = 0; i < size; i++)
		{
			temp_data[i] = data[i];
		}

		//释放旧数组的空间
		delete[] data;

		data = temp_data;	//成员变量data始终指向最新的数组空间
		capacity *= 2;
	}

	data[size] = value;	//插入元素
	size++;	//更新数组大小
}

void DynamicArray::printArray()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

//插入index指定的位置之前！！！
void DynamicArray::insertByIndex(int index, int value)
{
	if (index < 0 || index > size - 1)
	{
		return;
	}

	//需要扩容，容量增加一倍
	if (capacity == size)
	{
		int* temp_data = new int[capacity * 2];
		for (int i = 0; i < size; i++)
		{
			temp_data[i] = data[i];
		}
		delete[] data;

		data = temp_data;

		capacity *= 2;
	}
	
	for (int i = size - 1; i >= index; i--)
	{
		data[i + 1] = data[i];
	}

	data[index] = value;

	size++;
}

int DynamicArray::getCapacity()
{
	return capacity;
}

int DynamicArray::getSize()
{
	return size;
}

int DynamicArray::getValueByindex(int index)
{
	if (index < 0 || index >= size)
	{
		return NULL;
	}
	return data[index];
}

int DynamicArray::front()
{
	if (size > 0)
	{
		return data[0];
	}
	return NULL;
}

int DynamicArray::back()
{
	if (size > 0)
	{
		return data[size - 1];
	}
	return NULL;
}

void DynamicArray::popBack()
{
	if (size > 0)
	{
		size = size - 1;
	}
}

void DynamicArray::delByIndex(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}

	for (int i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	size--;
}

void test_dynamicArray()
{
	DynamicArray* dynamic = new DynamicArray(9);

	for (int i = 0; i < 5; i++)
	{
		dynamic->pushBack(i + 60);
	}

	dynamic->pushBack(88);

	dynamic->printArray();

	dynamic->insertByIndex(5, 99);

	dynamic->printArray();

	cout << "数组的容量是：" << dynamic->getCapacity() << endl;
	cout << "数组的大小是：" << dynamic->getSize() << endl;
	cout << "数组中的第三个元素的值是：" << dynamic->getValueByindex(2) << endl;
	cout << "数组中的第一个元素是：" << dynamic->front() << endl;
	cout << "数组中的最后个元素是：" << dynamic->back() << endl;

	dynamic->popBack();
	dynamic->printArray();

	dynamic->delByIndex(5);
	dynamic->printArray();

	delete dynamic;
}

void test2()
{
	DynamicArray* dynamic = new DynamicArray(10);

	for (int i = 0; i < 8; i++)
	{
		dynamic->pushBack(rand() % 101);
	}
	dynamic->printArray();

	dynamic->insertByIndex(5, 23);
	dynamic->printArray();

	//删除奇数
	for (int i = 0; i < dynamic->getSize();)
	{
		if (dynamic->getValueByindex(i) % 2 != 0)
		{
			dynamic->delByIndex(i);
		}
		else
		{
			i++;
		}
	}
	dynamic->printArray();

	delete dynamic;
}

int main()
{
	srand((unsigned)time(NULL));
	//test_dynamicArray();
	test2();
}