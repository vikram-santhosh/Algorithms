/*
    Level Order Traversal of a Binary Tree.
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

void LevelOrder(node * root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* curr = q.front();
        q.pop();
        if(curr)
        {
            cout<<curr->data<<" ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
}

int main()
{
    node* root = NULL;

    root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->right = createNode(4);
    root->right->right = createNode(5);

    LevelOrder(root);
}