#pragma once

class DoubleLinkNode
{
public:
	int data;
	DoubleLinkNode* prev;
	DoubleLinkNode* next;
public:
	DoubleLinkNode();
	DoubleLinkNode(int value);
	~DoubleLinkNode();
};

class DoubleLinkList
{
private:
	DoubleLinkNode* head;
	int size;
public:
	DoubleLinkList();
	~DoubleLinkList();

	//����
	void pushBack(int value);	//������������
	void pushFront(int value);	//�������ʼ����
	void insertByIndex(int index, int value);	//��ָ��λ�ò���

	//����
	int getSize();	//��ȡ������
	int front();	//��ȡ��һ��Ԫ�ص�ֵ
	int back();	//��ȡ���һ��Ԫ�ص�ֵ
	int findByIndex(int index);	//��ȡָ��λ�õ�Ԫ�ص�ֵ

	//ɾ��
	void popFront(); //ɾ�������еĵ�һ��Ԫ��
	void popBack();	//ɾ�������е����һ��Ԫ��
	//ɾ��ָ��λ�õ�Ԫ��

	//��ӡ˫������
	void printDoubleLinkList();
};