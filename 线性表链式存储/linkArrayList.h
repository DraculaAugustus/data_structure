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

	//��ѯ
	int getSize();	//��ȡ����ĳ���
	int findByindex(int index);	//����ָ��λ�õ�Ԫ��
	int findIndexByValue(int value);	//����ָ��Ԫ�ص�����
	int front();	//���ص�һ��Ԫ��
	int back();	//�������һ��Ԫ��

	//ɾ��
	void popBack();	//ɾ�����һ��Ԫ��
	void delByIndex(int index);	//ɾ��ָ��λ�õ�Ԫ��


};