#include <bits/stdc++.h>
using namespace std;

typedef struct TREE
{
	struct TREE *left;
	int data;
	struct TREE *right;
}Node;

Node* insert(int data)
{
    Node* node = new Node();
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}
int find_size(Node* root)
{
	if(root == NULL)
		return 0;
	else
	{
		return (find_size(root->left) + find_size(root->right) + 1);
	}
}
int main()
{
	Node* root = NULL;

    root = insert(1);
    root->left = insert(2);
    root->left->left = insert(3);
    root->right = insert(4);
    root->right->right = insert(5);

	cout<<find_size(root)<<endl;
}
