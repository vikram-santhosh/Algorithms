/*
Heap sort is an in-place algorithm.
Its typical implementation is not stable, but can be made stable (See this)
Time Complexity: Time complexity of heapify is O(Logn). 
Time complexity of createAndBuildHeap() is O(n) and overall time complexity of Heap Sort is O(nLogn).
*/
#include <bits/stdc++.h>
using namespace std;

int *arr;
int n;

void display()
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
    cout<<endl;
}

void heapify(int n,int node)
{
	int _max = node;
	int left = 2*_max + 1;
	int right = 2*_max + 2;

	if(left<n && arr[left]>arr[_max])
		_max = left;

	if(right<n && arr[right]>arr[_max])
		_max = right;

	if(_max != node)
	{
		swap(arr[node],arr[_max]);
		heapify(n,_max);
	}
}

void heap_sort()
{
	for(int i=n/2-1;i>=0;i--)
		heapify(n,i);

	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(i,0);
	}
}
int main()
{
	cin>>n;
	arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	heap_sort();
	display();
}
