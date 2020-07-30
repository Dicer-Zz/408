#include <bits/stdc++.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

bool InitList(SqList &L) {
	L.length = 0;
	return true;
}

int Length(SqList L) {
	return L.length;
}

int LocateElem(SqList L, ElemType e){
	int index = 0;
	for(int i = 0; i < L.length; i++) {
		if(L.data[i] == e) {
			index = i + 1;
			break;	
		}
	}
	return index;
}

ElemType GetElem(SqList L, int index) {
	return L.data[index];
}

bool ListInsert(SqList &L, int index, ElemType e) {
	if(index < 1 || index > L.length + 1)
		return 0;
	if(L.length >= MaxSize)
		return 0;
	for(int i = L.length-1; i >= index - 1; i--) {
		L.data[i+1] = L.data[i];
	}
	L.data[index-1] = e;
	L.length++;
	return true;
}

bool ListDelete(SqList &L, int index, ElemType &e) {
	if(index < 1 || index > L.length)
		return 0;
	e = L.data[index-1];
	for(int i = index - 1; i < L.length - 1; i++) {
		L.data[i] = L.data[i+1];
	}
	L.length--;
	return true;
}

void PrintElem(ElemType e) {
	printf("{%d}\n", e);
}
bool PrintList(SqList L) {
	printf("L.length: %d\n", L.length);
	for(int i = 0; i < L.length; i++) {
		PrintElem(L.data[i]);
	}
	return true;
}

bool Empty(SqList L) {
	return L.length == 0;
}

bool DestroyList(SqList &L) {
	L.length = 0;
	return true;
}
int main() {
	SqList L;
	int index;
	ElemType e;
	int id;
	while(~scanf("%d", &id)) {
		switch(id) {
		case 0:
			InitList(L);
			printf("Done!\n");
			break;
		case 1:
			printf("Length: %d\n", Length(L));
			break;
		case 2:
			scanf("%d", &e);
			printf("Index: %d\n", LocateElem(L, e));
			break;
		case 3:
			scanf("%d", &index);
			printf("L.data[%d]: %d\n", index, GetElem(L, index));
			break;
		case 4:
			scanf("%d %d", &index, &e);
			if(ListInsert(L, index, e)) {
				printf("Done!\n");
			} else {
				printf("Failed!\n");
			}
			break;
		case 5:
			scanf("%d", &index);
			if(ListDelete(L, index, e)) {
				printf("Deleted Element: %d\n", e);
			} else {
				printf("Failed!\n");
			}
			break;
		case 6:
			PrintList(L);
			printf("Done!\n");
			break;
		case 7:
			if(Empty(L)) {
				printf("List is empty!\n");
			} else {
				printf("List is not empty!\n");
			}
			break;
		case 8:
			DestroyList(L);
			printf("Done!\n");
			default:
			printf("0: InitList\n"
				    "1: Length\n"
				    "2: LocateElem\n"
				    "3: GetElem\n"
				    "4: ListInsert\n"
				    "5: ListDelete\n"
				    "6: PrintList\n"
				    "7: Empty\n"
				    "8: DestroyList\n");
		}

	}
	return 0;
}