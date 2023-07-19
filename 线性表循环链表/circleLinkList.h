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

	//���
	void pushBack(int value);	//β�����
	void pushFront(int value);	//ͷ�����
	void insertByIndex(int index, int value);	//ָ��λ��ǰ����Ԫ��

	//��ӡ����
	void printCircleLinkList();

	//��ѯ
	int getSize();	//����������
	int front();	//���ص�һ��Ԫ�ص�ֵ
	int back();		//�������һ��Ԫ�ص�ֵ
	int findByIndex(int index);	//����ָ��λ��Ԫ�ص�ֵ

	//ɾ��
	void popFront();	//ɾ����һ��Ԫ��
	void popBack();		//ɾ�����һ��Ԫ��

	//Լɪ������
	void yuesefu();
};