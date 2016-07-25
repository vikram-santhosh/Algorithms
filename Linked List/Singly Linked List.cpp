#include <bits/stdc++.h>
using namespace std;

typedef struct linklist
{
	int data;
	struct linklist* link;
}node;

node* insert(node* head,int data)
{
	node* temp = (node*) malloc (sizeof(node));
	temp->data = data;
	temp->link = NULL;

	if(head == NULL)
	{
		head = temp;
		return head;
	}
	node* nextNode = head;
	while(nextNode->link != NULL)
	{
		nextNode = nextNode->link;
	}
	nextNode->link = temp;
	return head;
}

void display(node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<endl;
		head = head->link;
	}
}
int main()
{
	int n,val;
	cin>>n;
	node *head = NULL;

	for(int i=0;i<n;i++)
	{
		cin>>val;
		head = insert(head,val);
	}
	display(head);
}
