/*
Worst Case: O(n*n) --> Parition choosen is always the largest or smallest element
Best Case : O(n log n)
Auxiliary Space: O(1)
Quicksort is a comparison sort, meaning that it can sort items of any type for which a
"less-than" relation (formally, a total order) is defined. In efficient implementations
it is not a stable sort, meaning that the relative order of equal sort items is not
preserved. Quicksort can operate in-place on an array, requiring small additional
amounts of memory to perform the sorting.
*/


#include <bits/stdc++.h>
using namespace std;

int *arr;
int n;

int find_partition(int low,int high)
{
	int idx = low-1;
	int pivot = arr[high];

	for(int i=low;i<high;i++)
	{
		if(arr[i]<=pivot)
		{
			idx++;
			swap(arr[idx],arr[i]);
		}
	}
	idx++;
	swap(arr[idx],arr[high]);
	return idx;
}

void quick_sort(int low,int high)
{
	if(low<high)
	{
		int _partition = find_partition(low,high);
		quick_sort(low,_partition-1);
		quick_sort(_partition+1,high);
	}
}
void display()
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main()
{
	cin>>n;
	arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	quick_sort(0,n-1);
	display();
}
