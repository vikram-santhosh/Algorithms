/*Maximum Sum Increasing Subsequence
Given an array of n positive integers. Write a program to find the sum of maximum sum
subsequence of the given array such that the intgers in the subsequence are
sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4,
5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4,
5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is
{10, 5, 4, 3}, then output should be 10
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int *a;

int solve()
{
	int dp[n];
	int sum[n];
	int max_sum = 0;
	for(int i=0;i<n;i++)
	{
		dp[i] = 1;
		sum[i] = a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				dp[i] = max(dp[j]+1,dp[i]);
				sum[i] = max(sum[j]+a[i],sum[i]);
				max_sum = max(sum[i],max_sum);
			}
		}
	}

	return max_sum;
}
int main()
{
	cin>>n;

    a = new int[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<solve()<<endl;
}
