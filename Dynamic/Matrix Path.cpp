/*
Find the longest path in a matrix with given constraints
Given a n*n matrix where numbers all numbers are distinct
and are distributed from range 1 to n2, find the maximum
length path (starting from any cell) such that all cells
along the path are increasing order with a difference of 1

*/

#include <bits/stdc++.h>
#define n 3
using namespace std;

int solve(int i,int j,int mat[n][n],int dp[n][n])
{
	if(i<0 || j<0 || i>=n || j>=n)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	if(j<n-1 && (mat[i][j]+1 == mat[i][j+1]))
		return (dp[i][j] = 1 + solve(i,j+1,mat,dp));

	if(i<n-1 && (mat[i][j]+1 == mat[i+1][j]))
		return (dp[i][j] = 1 + solve(i+1,j,mat,dp));

	if(j>=0 && (mat[i][j]+1 == mat[i][j-1]))
		return (dp[i][j] = 1 + solve(i,j-1,mat,dp));

	if(i>=0 && (mat[i][j]+1 == mat[i-1][j]))
		return (dp[i][j] = 1 + solve(i-1,j,mat,dp));

	return (dp[i][j] = 1);

}
int main()
{
	int res = 1;
	int dp[n][n],mat[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j];

	memset(dp,-1,sizeof(dp));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[i][j] == -1)
				solve(i,j,mat,dp);
			res = max(res,dp[i][j]);
		}
	}
    cout<<"Longest Path : "<<res<<endl;
}
