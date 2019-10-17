#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"

void InitList(pList plsit)
{
	assert(plsit != NULL);
	plsit->data = -1;
	plsit->next = NULL;
}

//得到一个节点
Node *GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

//头插   plist:  头结点的地址
void InsertHead(pList plist, int val)//55
{
	Node *pGet = GetNode(val);
	assert(plist != NULL);
	pGet->next = plist->next;
	plist->next = pGet;
}

//尾插法
void InsertTail(pList plist, int val){
	Node *pGet = GetNode(val);
	Node *p = plist;
	assert(p != NULL);
	while (p->next != NULL){
		p = p->next;
	}
	p->next = pGet;
}

//打印
void Show(pList plist)
{
	Node *p = plist->next;
	while (p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//倒数第K个结点
Node *LastKNode(pList plist, int k)
{
	if (k < 0)
	{
		return NULL;
	}
	Node *p = plist;
	Node *q = plist;

	//1、让一个指针p先走K-1步
	while (k - 1){
		//if (p->next != NULL){
		//	p = p->next;
		//	k--;
		//}
		//else return;
		p = p->next;
		k--;
		if (p->next == NULL) return;
	}
	//两个指针pq同时走
	while (p->next != NULL){
		p = p->next;
		q = q->next;
	}
	//Show(q);
	return q;
}

//逆置单链表 带头结点 头插法
Node *ReverseList(pList plist){
	//Node *p = plist->next;
	//Node *q = plist->next;
	//while (p->next != NULL){
	//	p = p->next;
	//	q = q->next;
	//	q->next=q->next->next;
	//	p->next->next = p;
	//	plist->next = p->next;
	//}
	//return plist;
	Node *p = plist->next;  //p pCur  q pCurN
	Node *q = NULL;
	plist->next = NULL;
	while (p != NULL){
		q = p->next;
		p->next = plist->next;
		plist->next = p;
		p = q;
	}
	return plist;
}

//边走边逆置 error
Node *ReverseList2(pList plist){
	Node *rever_head = NULL;
	Node *prev = NULL;
	Node *pCur = plist->next;
	Node *pCurN = NULL;
	while (pCur != NULL){
		pCurN = pCur->next;
		if (pCurN == NULL){
			rever_head = pCur;
		}
		pCur->next = prev->next;
		prev = prev->next;
		pCur = pCurN;
	}
	/*return rever_head*/;
}

// 链表的中间位置
Node *FindMidNode(pList plist){
	Node *pFast = plist->next;
	Node *pSlow = plist->next;

	while (pFast != NULL&&pFast->next != NULL)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

// 链表的中间位置2
Node *FindMidNode2(pList plist){
	Node *pFast = plist->next; //带头结点
	Node *pSlow = plist->next;

	while (pFast->next != NULL)
	{
		if (pFast->next->next != NULL)
			pFast = pFast->next->next;
		else pFast = pFast->next;

		pSlow = pSlow->next;
	}
	return pSlow;
}
