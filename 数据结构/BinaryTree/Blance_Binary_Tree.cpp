#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
	int weight;
	int height;
	int blance_index;
	struct Node *left, *rigth;
}Node, *Tree;


void Insert(Tree root, int x) {
	if(root == NULL) {
		root = (Tree)malloc(sizeof(Node));
		root->weight = x;
		root->height = 1;
		root->blance_index = 0;
		root->left  = NULL;
		root->right = NULL;
		return;
	}
	if(root->weight >= x) {
		Insert(root->left, x);
		root->height = max(root->left  == NULL?0:root->left->height,
						   root->right == NULL?0:root->right->height) + 1;
		root->blance_index = root->left  == NULL?0:root->left->height - 
						     root->right == NULL?0:root->right->height;
	}
	else	return Insert(root->right, x);
}

int main() {

	return 0;
}