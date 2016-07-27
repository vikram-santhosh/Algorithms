#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;

int n,*coin;

void solve(int sum)
{
	int dp[sum+1];
	int used[sum+1];

    for(int i=0;i<=sum;i++)
    {
        dp[i] = MAX;
        used[i] = -1;
    }

	dp[0] = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
		    if(j>=coin[i])
            {
                int temp = dp[j];
                dp[j] = min(dp[j],1+dp[j-coin[i]]);
                if(temp != dp[j])
                    used[j]=i;
            }
		}
	}

	cout<<"Minimum no. of Coins need : "<<dp[sum]<<endl;

	cout<<"Coins Used are : ";
	int i = sum;
	while(i!=0)
	{
		cout<<coin[used[i]]<<" ";
		i-=coin[used[i]];
	}

}
int main()
{
    int sum;
	cin>>n>>sum;
	coin = new int[n];

	for(int i=0;i<n;i++)
		cin>>coin[i];

    solve(sum);

}
