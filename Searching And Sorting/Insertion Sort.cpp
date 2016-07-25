/*
Time Complexity: O(n*n)
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if
elements are sorted in reverse order. And it takes minimum time (Order of n)
when elements are already sorted.
Algorithmic Paradigm: Incremental Approach
Sorting In Place: Yes
Stable: Yes
Online: Yes
Uses: Insertion sort is uses when number of elements is small.
It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
*/

#include <bits/stdc++.h>
using namespace std;

int *arr;
int n;

insertion_sort();
{
	for(int i=1;i<n;i++)
	{
		int key = a[i];
		j = i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void display()
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
	cin>>n;
	arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	insertion_sort();
}
