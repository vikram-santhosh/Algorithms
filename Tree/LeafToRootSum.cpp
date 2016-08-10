#include <bits/stdc++.h>
using namespace std;

typedef struct TREE
{
	struct TREE *left;
	int data;
	struct TREE *right;
}Node;

vector<int> path;

Node* insert(int data)
{
    Node* node = new Node();
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}

bool find_path(Node* node, int sum)
{
    if(node!=NULL)
    {
        if(find_path(node->left,sum-(node->data)) || find_path(node->right,sum-(node->data)))
        {
            path.push_back(node->data);
            return true;
        }
        else
            return false;
    }
    if(node == NULL)
    {
        return (sum==0);
    }

}
int main()
{
	Node* root = NULL;

    root = insert(5);
    root->left = insert(6);
    root->right = insert(7);
    root->right->left = insert(1);
    root->right->right = insert(2);


    if(find_path(root,13))
    {
        cout<<"Path Exists"<<endl;
        for(int i=0;i<path.size();i++)
            cout<<path[i]<<endl;
    }
    else
        cout<<"No Path"<<endl;
}
