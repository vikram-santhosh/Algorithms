/*
MergeSort is a Divide and Conquer algorithm.
It divides input array in two halves, calls
itself for the two halves and then merges the
two sorted halves. The merg() function is used
for merging two halves. The merge(arr, l, m, r) is
key process that assumes that arr[l..m] and arr[m+1..r]
are sorted and merges the two sorted sub-arrays into one.
*/

#include <bits/stdc++.h>
using namespace std;

int *arr;
int n;

void merge_array(int low,int mid,int high)
{
	int n = mid-low+1;
	int m = high-mid;

	int x[n], y[m];

	for(int i=0;i<n;i++)
		x[i] = arr[low+i];

	for(int j=0;j<m;j++)
		y[j] = arr[(mid+1)+j];

	int i = 0, j=0, k = low;

	while(i<n && j<m)
	{
		if(x[i]<=y[j])
		{
			arr[k] = x[i];
			i++;
		}
		else
		{
			arr[k] = y[j];
			j++;
		}
		k++;
	}

	while(i<n)
	{
		arr[k] = x[i];
		i++;
		k++;
	}

	while(j<m)
	{
		arr[k] = y[j];
		j++;
		k++;
	}

}
void display()
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
    cout<<endl;
}
void merge_sort(int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge_array(low,mid,high);
	}
}

int main()
{
	cin>>n;
	arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	merge_sort(0,n-1);
	display();
}
