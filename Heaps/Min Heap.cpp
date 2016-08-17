/* Min Heap: In this type of heap, the value of parent node will always be
lesser than or equal to the value of child node across the tree and the node
with highest value will be the root node of the tree.
Complexity: O( log N )*/

#include <bits/stdc++.h>
using namespace std;

void min_heapify(int *arr,int node,int n)
{
	int left = node*2;
	int right = node*2+1;
	int _min = node;

	if(left<=n && arr[left]<arr[node])
		_min = left;

	if(right<=n && arr[right]<arr[_min])
		_min = right;

	if(_min != node)
	{
		swap(arr[node],arr[_min]);
		min_heapify(arr,_min,n);
	}
}
void Heap_Util(int *arr, int n)
{
	for(int i=n/2;i>=1;i--)
	{
		min_heapify(arr,i,n);
	}
}

void display(int *arr, int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=1;i<=n;i++)
        cin>>arr[i];

	Heap_Util(arr,n);
	display(arr,n);

}
