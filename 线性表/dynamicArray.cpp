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
	if (capacity == size)	//˵������������������Ҫ����
	{
		//��������һ��
		int* temp_data = new int[capacity * 2];
		
		//�Ѿ����ݿ������¿��ٵĿռ���
		for (int i = 0; i < size; i++)
		{
			temp_data[i] = data[i];
		}

		//�ͷž�����Ŀռ�
		delete[] data;

		data = temp_data;	//��Ա����dataʼ��ָ�����µ�����ռ�
		capacity *= 2;
	}

	data[size] = value;	//����Ԫ��
	size++;	//���������С
}

void DynamicArray::printArray()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

//����indexָ����λ��֮ǰ������
void DynamicArray::insertByIndex(int index, int value)
{
	if (index < 0 || index > size - 1)
	{
		return;
	}

	//��Ҫ���ݣ���������һ��
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

	cout << "����������ǣ�" << dynamic->getCapacity() << endl;
	cout << "����Ĵ�С�ǣ�" << dynamic->getSize() << endl;
	cout << "�����еĵ�����Ԫ�ص�ֵ�ǣ�" << dynamic->getValueByindex(2) << endl;
	cout << "�����еĵ�һ��Ԫ���ǣ�" << dynamic->front() << endl;
	cout << "�����е�����Ԫ���ǣ�" << dynamic->back() << endl;

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

	//ɾ������
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