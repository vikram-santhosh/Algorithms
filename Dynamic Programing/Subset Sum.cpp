#include <bits/stdc++.h>
using namespace std;

int sum,n;
int *val;
int solve()
{
	int dp[n+1][sum+1];
	bool soln = false;
	memset(dp,0,sizeof(dp));

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(j==0)
				dp[i][j] = 1;

            else if(i==0 && sum>0)
                dp[i][j] = 0;

			else if(j >= val[i])
				dp[i][j] = dp[i-1][j-val[i]];

			else
				dp[i][j] = dp[i-1][j];

            if(j == sum && dp[i][j])
                soln = true;
		}
	}

	return soln;
}

int main()
{
	cin>>n>>sum;
	val = new int[n+1];

	for(int i=1;i<=n;i++)
		cin>>val[i];

	cout<<solve()<<endl;
}
