#pragma once

//��ʽ�洢�ڵ�
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

//����
class LinkArrayList
{
	LinkArrayNode* head;
	int size;
public:
	LinkArrayList();
	~LinkArrayList();

	//���
	void pushBack(int value);	//β�����Ԫ��
	void insertValueByIndex(int index, int value);	//ָ��λ��ǰ����Ԫ��

	//��ӡ����
	void printArrayList();


	int getSize();
};