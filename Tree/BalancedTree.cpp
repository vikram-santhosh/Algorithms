/*
	Check if a Binary Tree is Balaced. A tree is said to be balanced if the max difference 
	in height between two leaf nodes is 1.
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
	temp->data = data;
	temp->right = NULL;
	return temp;
}

int isBalanced(node* root)
{
	if(root == NULL)
		return 0;
	int left_ht = isBalanced(root->left);
	if(left_ht == -1)
		return -1;
	int right_ht = isBalanced(root->right);
	if(right_ht == -1)
		return -1;

	int diff = abs(left_ht-right_ht);
	if(diff>1)
		return -1;
	else
		return 1+max(left_ht,right_ht);
}

int main()
{
	node* root = NULL;

	root = createNode(1);
	root->left = createNode(2);
	root->left->left = createNode(3);
	root->right = createNode(4);
    root->right->right = createNode(5);

	int res = isBalanced(root);
	if(res<0)
		cout<<"Not Balanced"<<endl;
	else
		cout<<"Balanced"<<endl;

}
