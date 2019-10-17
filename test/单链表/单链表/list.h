#ifndef __LIST_H__
#define __LIST_H__
//#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node, *pList;

//��ʼ��
void InitList(pList plsit);

//ͷ��
void InsertHead(pList plist, int val);

//β��
void InsertTail(pList plist, int val);

//��ӡ
void Show(pList plist);

//����λ�ò���

//ɾ��

//����

//������k�����
Node *LastKNode(pList plist, int k);

//���õ����� ��ͷ���
Node *ReverseList(pList plist);

//���߱�����
Node *ReverseList2(pList plist);

//������м�λ��
Node *FindMidNode(pList plist);

// ������м�λ��2
Node *FindMidNode2(pList plist);


#endif //__LIST_H__
