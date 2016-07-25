/*
	Create a Binary Search Tree.
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

node* createNode(int value)
{
	node* temp = (node*) malloc (sizeof(node));
	temp->left = NULL;
	temp->data = value;
	temp->right = NULL;
	return temp;
}
node* insert(node* root,int value)
{
	if(root == NULL)
		return (root = createNode(value));
	if(value > root->data)
		root->right = insert(root->right,value);
	else
		root->left = insert(root->left,value);
	return root;
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
	node* root = NULL;
	int n,value;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>value;
		root = insert(root,value);
	}

	inorder(root);
}
