/* Max Heap: In this type of heap, the value of parent node will always be
less than or equal to the value of child node across the tree and the node
with highest value will be the root node of the tree.
Complexity: O( log N )*/

#include <bits/stdc++.h>
using namespace std;

void max_heapify(int arr[],int node,int n)
{
	int left = node * 2;
	int right = node * 2 + 1;
	int _max = node;

	if(left <n && arr[left]>arr[node])
		_max = left;
	if(right < n && arr[right]>arr[node])
		_max = right;

	if(_max != node)
	{
		swap(arr[_max],arr[node]);
		max_heapify(arr,_max,n);
	}
}
void Heap_Util(int arr[],int n)
{
	for(int i=n/2;i>=0;i--)
	{
		max_heapify(arr,i,n);
	}
}

void display(int *arr, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
        cin>>arr[i];

	Heap_Util(arr,n);
	display(arr,n);

}


