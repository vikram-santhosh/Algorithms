#include <bits/stdc++.h>
using namespace std;

int N,W;
int *val, *wt;

int knapsack()
{
	int k[N+1][W+1];
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0 || j==0)
				k[i][j] = 0;
			else
			{
				if(wt[i] > j)
					k[i][j] = k[i-1][j];
				else
					k[i][j] = max(k[i-1][j],val[i]+k[i-1][j-wt[i]]);
			}
		}
	}

	return k[N][W];
}
int main()
{
	cin>>N>>W;
	val = new int[N+1];
	wt = new int[N+1];

	for(int i=1;i<=N;i++)
		cin>>wt[i]>>val[i];
	cout<<knapsack()<<endl;
}
