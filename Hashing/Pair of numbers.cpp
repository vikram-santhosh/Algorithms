/*
Find all pairs of numbers in a given array which add up to a given sum
Complexity : O(n)
*/

#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;

int _hash[MAX] = {0};

void find_paris(int a[],int n)
{
	int sum;
	cin>>sum;

	for(int i=0;i<n;i++)
	{
		if(a[i]<=sum)
		{
			int rem = sum - a[i];
			if(_hash[rem])
				cout<<"("<<a[i]<<","<<rem<<") , ";
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int *a = new int[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		_hash[a[i]] = 1;
	}
	find_paris(a,n);
}
