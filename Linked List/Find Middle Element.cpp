/*
Efficiency : O(n/2)
Given a doubly linked list , traverse one end twice as fast as the other end.
By the time the fast-pointer reaches the end of the linked list, the
slow-pointer reaches the middle
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct linkedlist
{
	struct linkedlist *next;
	int data;
	struct linkedlist *prev;
}Node;

Node* head = NULL;
Node* tail = NULL;

Node* makeNode(int data)
{
	Node* temp = new Node();
	temp -> next = NULL;
	temp -> data = data;
	temp -> prev = NULL;
	return temp;
}
void insert(int data)
{
	Node* curr = head;
	Node* node = makeNode(data);

	if(head == NULL)
	{
		head = node;
		return;
	}

	while(curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = node;
	node->prev = curr;
	tail = curr->next;
}
int find_mid()
{
    Node* fast = head;
    Node* slow = tail;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->prev;
    }
    return slow->data;
}
int main()
{
	int n,data;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>data;
		insert(data);
	}

   cout<<find_mid()<<endl;
}
