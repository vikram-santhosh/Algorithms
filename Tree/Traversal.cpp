/*
	Inorder, Preorder and Postorder traversal of a Binary Tree
*/
#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
	struct treeNode* left;
	int data;
	struct treeNode* right;
};
typedef struct treeNode node;

node* createNode(int data)
{
	node* temp = (node*) malloc (sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	return temp;
}

void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(node* root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int main()
{
	int ch;
	node* root = NULL;

	root = createNode(1);
	root->left = createNode(2);
	root->left->left = createNode(3);
	root->right = createNode(4);
	root->right->right = createNode(5);

	cin>>ch;
	switch(ch)
	{
		case 1: inorder(root);
				break;
		case 2:	postorder(root);
				break;
		case 3: postorder(root);
				break;
	}
}
