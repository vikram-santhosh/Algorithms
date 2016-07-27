/*Counting sort is a sorting technique based on keys between a specific range.
It works by counting the number of objects having distinct key values (kind of
hashing). Then doing some arithmetic to calculate the position of each object
in the output sequence.
Time Complexity: O(n+k) where n is the number of
elements in input array and k is the range of input.
Auxiliary Space: O(n+k)*/

#include <bits/stdc++.h>
#define RANGE 1024
using namespace std;

void count_sort(int arr[],int n)
{
	int hash[RANGE+1];
	memset(hash,0,sizeof(hash));

	for(int i=0;i<n;i++)
		hash[arr[i]]++;

	int i=0;
	while(i<=RANGE)
	{
		if(hash[i])
		{
			hash[i]--;
			cout<<i<<" ";
			continue;
		}
		i++;
	}
}
int main()
{
	int n,*arr;
	cin>>n;
	arr = new int[n];

	for(int i=0;i<n;i++)
        cin>>arr[i];

	count_sort(arr,n);
}
