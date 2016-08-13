/*Write a function to reverse a linked list
Given pointer to the head node of a linked list, the task is to reverse the linked list.

Examples:

Input : Head of following linked list
       1->2->3->4->NULL
Output : Linked list should be changed to,
       4->3->2->1->NULL

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

typedef struct linklist
{
	int data;
	struct linklist *link;
} Node;

Node* head = NULL;

void reverseList(Node* curr)
{
	if(curr->link == NULL)
	{
		head = curr ;
		return;
	}
	reverseList(curr->link);

	//foldback after recursion

	Node* prev = curr->link;
	curr->link = NULL;
	prev->link = curr;
}

Node* makeNode(int data)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->link = NULL;
	return node;
}
Node* insert(Node* head, int data)
{
	Node* curr = head;
	Node* node = makeNode(data);

	if(head == NULL)
	{
		head = node;
		return head;
	}
	while(curr->link != NULL)
	{
		curr = curr->link;
	}
	curr->link = node;
    return head;
}

int main()
{
	int n,data;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>data;
		head = insert(head,data);
	}

	reverseList(head);

	Node *curr = head;
	while(curr != NULL)
	{
		cout<<curr->data<<" ";
		curr = curr->link;
	}
}
