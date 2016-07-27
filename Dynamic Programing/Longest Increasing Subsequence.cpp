#include <bits/stdc++.h>
using namespace std;

int n,*arr,*dp;

int solve()
{
	int ans = 0;
	memset(dp,1,n);

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				dp[i] = max(dp[i],dp[j]+1);
				if(dp[i]>ans)
					ans = dp[i];
			}
		}
	}
	return ans;
}

int main()
{
	cin>>n;
	arr = new arr[n];
	dp = new dp[n];
	cout<<"Length of Longest Increasing Subsequence : "<<solve()<<endl;

}