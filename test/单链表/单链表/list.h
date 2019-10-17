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

//初始化
void InitList(pList plsit);

//头插
void InsertHead(pList plist, int val);

//尾插
void InsertTail(pList plist, int val);

//打印
void Show(pList plist);

//任意位置插入

//删除

//查找

//倒数第k个结点
Node *LastKNode(pList plist, int k);

//逆置单链表 带头结点
Node *ReverseList(pList plist);

//边走边逆置
Node *ReverseList2(pList plist);

//链表的中间位置
Node *FindMidNode(pList plist);

// 链表的中间位置2
Node *FindMidNode2(pList plist);


#endif //__LIST_H__
