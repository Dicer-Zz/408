#include<bits/stdc++.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LinkList LinkList_HeadInsert(LinkList &L) {
	ElemType e;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *s;
	while(~scanf("%d", &e)) {
		if( e == -1)	break;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L->next;
		L->next = s;
		L->data++;
	}
	return L;
}

LinkList LinkList_TailInsert(LinkList &L) {
	ElemType e;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *s, *r = L;
	while(~scanf("%d", &e)) {
		if(e == -1)	break;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		r->next = s;
		r = s;
		L->data++;
	}
	r->next = NULL;
	return L;
}
bool Print(LinkList L) {
	LNode s = *L;
	printf("Length: %d\n", s.data);
	while(s.next != NULL) {
		s = *s.next;
		printf("{%d}\n", s.data);
	}
	return true;
}
int main() {
	LinkList L;
	LinkList_HeadInsert(L);
	// LinkList_TailInsert(L);
	Print(L);
	return 0;
}