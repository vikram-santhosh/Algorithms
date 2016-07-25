/*
Given a rod of length n inches and an array of prices that 
contains prices of all pieces of size smaller than n. Determine 
the maximum value obtainable by cutting up the rod and selling 
he pieces. For example, if length of the rod is 8 and the values
of different pieces are given as following, then the maximum 
obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

*/

#include <bits/stdc++.h>
using namespace std;

int total,n;
int *val , *len;

void solve()
{
	int dp[n+1][total+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=total;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else
			{
				if(j >= len[i])
					dp[i][j] = max(dp[i-1][j], (val[i] + dp[i][j-len[i]]));
				else
					dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout<<dp[n][total]<<endl;
}

int main()
{
	cin>>n>>total;
	len = new int[n+1];
	val = new int[n+1];

	for(int i=1;i<=n;i++)
		cin>>len[i]>>val[i];

    solve();
}
