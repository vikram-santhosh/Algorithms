/*
Bubble Sort is the simplest sorting algorithm
that works by repeatedly swapping the adjacent elements if they are in wrong order.

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes
Stable: Yes
*/

#include <bits/stdc++.h>
using namespace std;

int *arr;
int n;
void bubble_sort()
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<(n-i-1);j++)
			if(arr[j]>arr[j+1])
				swap(arr[j+1],arr[j]);
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

	bubble_sort();
	display();
}
