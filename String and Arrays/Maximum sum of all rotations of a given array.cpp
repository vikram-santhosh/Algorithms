/*Given an array arr[] of n integers, find the maximum that maximizes sum of
value of i*arr[i] where i varies from 0 to n-1.
The idea is to compute value of a rotation using value of previous rotation.
When we rotate an array by one, following changes happen in sum of i*arr[i].
1) Multiplier of arr[i-1] changes from 0 to n-1, i.e., arr[i-1] * (n-1) is
added to current value. 2) Multipliers of other terms is decremented by 1.
i.e., (cum_sum – arr[i-1]) is subtracted from current value where cum_sum is
sum of all numbers.
Efficient Solution : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

int solve(int a[],int n)
{
	int _max,prev;
	int sum = 0;
	int total = 0;
	for(int i=0;i<n;i++)
		total += a[i];

	for(int i=0;i<n;i++)
	{
		sum += i*a[i];
	}

	_max = sum;
	prev = sum;

	for(int i=1;i<n;i++)
	{
		sum = prev + a[i-1]*(n) - total;
		if(sum > _max)
			_max = sum;
		prev = sum;
	}

	return _max;
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
