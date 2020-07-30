#include<bits/stdc++.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LinkList LinkList_HeadInsert(LinkList &L) {
	LNode *s;
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	while(~scanf("%d", &x)) {
		if(x == -1)	break;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		L->data++;
	}
	return L;
}

LinkList LinkList_TailInsert(LinkList &L) {
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *s, *r = L;
	while(~scanf("%d", &x)) {
		if(x == -1)	break;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		L->data++;
	}
	r->next = NULL;
	return L;
}

LNode *GetElem(LinkList L, int index) {
	int cnt = 1;
	if(index == 0)	return L;
	LNode *s = L->next;
	if(index < 0)	return NULL;
	while(s && cnt < index) {
		s = s->next;
		cnt++;
	}
	return s;
}

LNode *LocateElem(LinkList L, ElemType e, int &index) {
	index = 1;
	LNode *s = L->next;
	while(s && s->data != e) {
		s = s->next;
		index++;
	}
	return s;
}

bool ElemInsert(LinkList L, int index, ElemType e) {
	LNode *s, *p = GetElem(L, index-1);
	if(p == NULL)	return false;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	L->data++;
	return true;
}

bool ElemDelete(LinkList L, int index, ElemType &e) {
	LNode *s, *p = GetElem(L, index-1);
	if(p->next == NULL)	return false;
	s = p->next;
	e = s->data;
	p->next = s->next;
	free(s);
	L->data--;
	return true;
}

bool LNodeDelete(LinkList L, LNode *s) {
	if(s == NULL)	return false;
	if(s->next == NULL)	return true;
	LNode *p = s->next;
	s->data = p->data;
	s->next = p->next;
	free(p);
	L->data--;
	return true;
}

int ListLength(LinkList L) {
	return L->data;
}
void Print(LinkList L) {
	LNode *s = L;
	printf("Length: %d\n", s->data);
	while(s->next != NULL) {
		s = s->next;
		printf("{%d}\n", s->data);
	}
}

void Scan(ElemType &e) {
	scanf("%d", &e);
}
void Print(ElemType e) {
	printf("{%d}\n", e);
}
int main() {
	LinkList L;
	// LinkList_HeadInsert(L);
	LinkList_TailInsert(L);
	int id, index;
	ElemType e;
	bool flag;
	LNode *s;
	while(~scanf("%d", &id)) {
		if(id == -1)	break;
		switch(id) {
			case 1:
			scanf("%d", &index);
			s = GetElem(L, index);
			if(s == NULL) {
				printf("Failed!\n");
			} else {
				Print(s->data);
			}
			break;
			case 2:
			Scan(e);
			s = LocateElem(L, e, index);
			if(s == NULL) {
				printf("Failed!\n");
			} else {
				printf("Index: %d\n", index);
			}
			break;
			case 3:
			scanf("%d", &index);
			Scan(e);
			flag = ElemInsert(L, index, e);
			if(flag) {
				printf("Done\n");
			} else {
				printf("Failed\n");
			}
			break;
			case 4:
			scanf("%d", &index);
			flag = ElemDelete(L, index, e);
			if(flag) {
				printf("Deleted Element:\n");
				Print(e);
			} else {
				printf("Failed!\n");
			}
			break;
			case 5:
			Print(L);
			break;
			default:
			printf("1: GetElem\n"
				   "2: LocateElem\n"
				   "3: ElemInsert\n"
				   "4: ElemDelete\n"
				   "5: Print\n");
		}
	}
	return 0;
}