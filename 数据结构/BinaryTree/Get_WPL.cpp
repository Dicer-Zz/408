#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
	unsigned weight;
	struct Node *left, *right;
}Node, *Tree;

unsigned ans = 0u;
unsigned cur = 0u;

unsigned Get_WPL(Tree root) {
	if(root == NULL)	return 0u;
	cur += root->weight;
	Get_WPL(root->left);
	Get_WPL(root->right);
	if(root->left == NULL && root->right == NULL)
		ans += cur;
	cur -= root->weight;
}

bool Init_Tree(Tree root) {
	unsigned x;
	queue<Tree> q;
	root = (Tree)malloc(sizeof(Node));
	q.push(root);
	while(~scanf("%u", &x)) {
		if(x == 0)	break;
		root->weight = x;
		root->left  = (Tree)malloc(sizeof(Node));
		root->right = (Tree)malloc(sizeof(Node));
		q.push(root->left);
		q.push(root->right);
	}	
}
int main() {

	return 0;
}