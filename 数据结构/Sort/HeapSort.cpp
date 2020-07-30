#include<bits/stdc++.h>
using namespace std;

int heap[] = {0, 3, 5, 9, 0, 7, -2, 4, 2, 10, 8};
int size = 10;

void HeapAdjust(int x) {
	heap[0] = heap[x];
	for(int i = x*2; i <= size; i *= 2) {
		if(i < size && heap[i] < heap[i+1])
			i++;
		if(heap[0] > heap[i])	break;
		else {
			heap[x] = heap[i];
			x = i;
		}
	}
	heap[x] = heap[0];
}

void Build() {
	// printf("%d\n", size);
	for(int i = size/2; i > 0; i--) HeapAdjust(i);
	printf("Done!\n");
}

bool DeleteTop(int &e) {
	if(size == 0)	return false;
	e = heap[1];
	heap[1] = heap[size];
	size--;
	HeapAdjust(1);
	return true;
}

void InsertAdjust(int x) {
	while(x != 0) {
		printf("%d\n", x);
		if(heap[x/2] < heap[x]) {
			swap(heap[x/2], heap[x]);
			x /= 2;
		} else	break;
	}
}

void Insert(int e) {
	size++;
	heap[size] = e;
	InsertAdjust(size);
}

int main() {
	Build();
	int id = 0, e;
	while(~scanf("%d", &id)) {
		switch(id) {
			case 1:
			scanf("%d", &e);
			Insert(e);
			printf("Done!\n");
			break;
			case 2:
			if(DeleteTop(e)) {
				printf("%d has been deleted!\n", e);
			} else {
				printf("Failed, Heap is Empty!\n");
			}
			break;
			case 3:
			printf("%d is the max number!\n", heap[1]);
			break;
			default:
			break;
		}
	}
	return 0;
}