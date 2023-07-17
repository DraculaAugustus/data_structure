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

	//β������Ԫ��
	void pushBack(int value);

	//������������Ԫ��
	void insertByIndex(int index, int value);
	
	//��ӡ����
	void printArray();

	//����
	int getCapacity();	//�������������

	int getSize();	//��������Ĵ�С

	int getValueByindex(int index);	//����ָ��Ԫ�ص�ֵ

	int front();	//��������ĵ�һ��Ԫ��

	int back();	//������������һ��Ԫ��

	//ɾ��Ԫ��
	void popBack();	//ɾ�����һ��Ԫ��

	void delByIndex(int index);	//ɾ��ָ��λ�õ�Ԫ��

};