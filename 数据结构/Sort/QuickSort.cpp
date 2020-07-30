#include<bits/stdc++.h>
using namespace std;

int a[] = {3, 5, 9, 0, 7, -2, 4, 2, 10, 8};

int Partition(int l, int r) {
	int pivot = a[l];
	int i = l, j = r;
	while(i<j) {
		while(i<j && a[j]>=pivot)	j--;
		a[i] = a[j];
		while(i<j && a[i]<=pivot)	i++;
		a[j] = a[i];
	}
	a[i] = pivot;
	return i;
}
void Qsort(int l, int r) {
	if(l >= r)	return;
	int mid = Partition(l, r);
	// for(int i = 0; i < 10; i++)	printf("%d%c", a[i], (i!=9)?' ':'\n');
	Qsort(l, mid-1);
	Qsort(mid+1, r);
}
int main() {
	Qsort(0, 9);
	for(int i = 0; i < 10; i++)	printf("%d%c", a[i], (i!=9)?' ':'\n');
	return 0;
}