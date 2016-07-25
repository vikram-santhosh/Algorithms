/*
	Find the Height of Binary Tree
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	struct node* left;
	int data;
	struct node* right;
};

int height(struct node* root)
{
	if(root == NULL)
		return 0;
	int left = height(root->left);
	int right = height(root->right);
	if(left>right)
		return left+1;
	else
		return right+1;
}
struct node* createNode(int data)
{
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	temp->left = NULL;
	temp->data = data;
	temp->right = NULL;
	return temp;
}
int main()
{
	struct node* root = NULL;
	root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->right->right = createNode(5);

	cout<<height(root)<<endl;
}
