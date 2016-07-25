/*
	Insertion at a given position
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct linklist
{
	int data;
	struct linklist* link;
}node;

void display(node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<endl;
		head = head->link;
	}
}

node* makeNode(int val)
{
	node* temp = (node*) malloc(sizeof(node));
	temp->data = val;
	temp->link = NULL;
	return temp;
}
node* insertAt(int pos,node* head,int val)
{
	int count = 0;
	node* temp = makeNode(val);
	node* i = head;
	while(count<pos)
	{
		i = i->link;
		count++;
	}

	node* j = i->link;
	i->link = temp;
	temp->link = j;
	return head;
}
node* insert(node* head,int data)
{
	node* temp = makeNode(data);
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
int main()
{
	int n,val;
	cin>>n;
	node* head;

	node* nextNode = head;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		node* temp = makeNode(val);
		if(nextNode == NULL)
			nextNode = temp;
		else
			nextNode->link = temp;
		nextNode = nextNode->link;
	}
    display(head);
	head = insertAt(3,head,10);
	head = insertAt(1,head,11);
	display(head);
}
