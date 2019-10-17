#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

int main(){
	//pList L; //这么写为什么是错的
	//InitList(L);
	//InsertHead(L,4);
	//InsertHead(L, 5);
	//InsertHead(L, 7);
	//Show(L);

	Node head;
	InitList(&head);
	InsertHead(&head, 4);
	InsertHead(&head, 5);
	InsertHead(&head, 6);
	Show(&head);

	Node tail;
	InitList(&tail);
	InsertTail(&tail, 4);
	InsertTail(&tail, 5);
	InsertTail(&tail, 6);
	InsertTail(&tail, 7);
	InsertTail(&tail, 8);
	InsertTail(&tail, 9);
	InsertTail(&tail, 10);
	Show(&tail);

	/*Show(LastKNode(&tail, 3));*/

	printf("%d\n", LastKNode(&tail, 5)->data);

	Node *p = NULL;
	p = ReverseList(&tail);
	printf("转置1：");
	Show(p);

	//Node *q = NULL;
	//q = ReverseList2(&tail);
	//printf("转置2：");
	//Show(q);

	/*Node *mid = NULL;
	Node *mid2 = NULL;
	mid = FindMidNode(&tail);
	mid2 = FindMidNode2(&tail);*/
	printf("找中间1：%d\n", FindMidNode(&tail)->data);
	printf("找中间2：%d\n", FindMidNode2(&tail)->data);

	system("pause");
	return 0;
}
