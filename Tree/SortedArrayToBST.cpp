#include <bits/stdc++.h>
using namespace std;

typedef struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
} node;
int n,*arr;

node* makeNode(int data)
{
    node* temp = (node*) malloc (sizeof(node));
    temp->left = NULL;
    temp->data = data;
    temp->right = NULL;
    return temp;
}
node* CreateBST(node* root,int low,int high)
{
	if(low<=high)
	{
		int mid = (low+high)/2;
		root = makeNode(arr[mid]);
		root->data = arr[mid];
		root->left = CreateBST(root->left,low,mid-1);
		root->right = CreateBST(root->right,mid+1,high);
	}
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
	cin>>n;
	arr = new int[n];
	node* root = NULL;
	for(int i=0;i<n;i++) // enter a sorted list
		cin>>arr[i];

	root = CreateBST(root,0,n-1);
	inorder(root);
}
