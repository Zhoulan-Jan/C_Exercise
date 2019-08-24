#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"

void InitList(pList plsit)
{
	assert(plsit != NULL);
	plsit->data = -1;
	plsit->next = NULL;
}

//�õ�һ���ڵ�
Node *GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

//ͷ��   plist:  ͷ���ĵ�ַ
void InsertHead(pList plist, int val)//55
{
	Node *pGet = GetNode(val);
	assert(plist != NULL);
	pGet->next = plist->next;
	plist->next = pGet;
}

//β�巨
void InsertTail(pList plist, int val){
	Node *pGet = GetNode(val);
	Node *p = plist;
	assert(p != NULL);
	while (p->next != NULL){
		p = p->next;
	}
	p->next = pGet;
}

//��ӡ
void Show(pList plist)
{
	Node *p = plist->next;
	while (p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//������K�����
Node *LastKNode(pList plist, int k)
{
	if (k < 0)
	{
		return NULL;
	}
	Node *p = plist;
	Node *q = plist;

	//1����һ��ָ��p����K-1��
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
	//����ָ��pqͬʱ��
	while (p->next != NULL){
		p = p->next;
		q = q->next;
	}
	//Show(q);
	return q;
}

//���õ����� ��ͷ��� ͷ�巨
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

//���߱����� error
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

// ������м�λ��
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

// ������м�λ��2
Node *FindMidNode2(pList plist){
	Node *pFast = plist->next; //��ͷ���
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
