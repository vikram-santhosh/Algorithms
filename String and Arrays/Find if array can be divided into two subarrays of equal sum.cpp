/*Find if array can be divided into two subarrays of equal sum Given an array of
integers, find if it’s possible to remove exactly one integer from the array
that divides the array into two subarrays with the same sum.

Efficient Solution : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int *a,int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
		sum += a[i];

	int curr = 0;
	for(int i=1;i<n;i++)
	{
		curr += a[i-1];

		if(curr == (sum-curr-a[i]))
			return a[i];
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<solve(a,n)<<endl;
}
