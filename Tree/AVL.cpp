#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode
{
	int key;
	struct TreeNode *left;
	struct TreeNode *right;
	int height;
}Node;

int height(Node *node)
{
	if(node == NULL)
		return 0;
	return node->height;
}

Node* createNode(int key)
{
	Node* node = NULL;
	node = new Node();

	node->left = NULL;
	node->right = NULL;
	node->key = key;
	node->height = 1;

	return node;
}

Node* rightRotate(Node* root)
{
	Node* newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	root->height = max(height(root->left),height(root->right)) + 1;
	newRoot->height = max(height(newRoot->left),height(newRoot->right)) + 1;

	return newNode;
}

Node* leftRotate(Node* root)
{
	Node* newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;

	root->height = max(height(root->left),height(root->right)) + 1;
	newRoot->height = max(height(newRoot->left),height(newRoot->right)) + 1;

	return newNode;
}

int getBalance(Node* node)
{
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

Node* inserr(Node* node, int key)
{
	if(node == NULL)
		return (createNode(key));
	if(key < node->key)
		node->left = insert(node->left,key);
	else
		node->right = insert(node->right,key);

	node->height = max(height(node->left),height(node->right))+1; 
	int balance = getBalance(node);

	//left left
	if(balance > 1 && key < node->left->key)
		return rightRotate(node);

	//right right
	if(balanc < -1 && key > node->right->key)
		return leftRotate(node);

	//left right
	if(balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		reutrn rightRotate(node);
	}

	//right left
	if(balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}
