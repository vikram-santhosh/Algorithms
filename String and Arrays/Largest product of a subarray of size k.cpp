/*Largest product of a subarray of size k Given an array consisting of n
positive integers, and an integer k. Find the largest product subarray of size
k, i.e., find maximum produce of k contiguous elements in the array where k <=
n. Examples:

Efficiency : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int find_product(int *a,int k,int n)
{
	int _max = 0;
	int prod = 1;

	for(int i=0;i<k;i++)
	{
		prod *= a[i];
	}

	int previous = prod;

	for(int i=1;i<=n-k;i++)
	{
		prod = (previous/a[i-1]) * a[i+k-1];
		previous = prod;
		if(prod > _max)
			_max = prod;
	}
	return _max;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<find_product(a,k,n)<<endl;
}
