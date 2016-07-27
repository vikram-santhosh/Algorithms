#include <bits/stdc++.h>
using namespace std;

// global section
struct Job
{
	int start;
	int finish;
	int wt;
};
int n;
vector<Job> job(n);

//code section
bool compare(struct Job j1, struct Job j2)
{
	return (j1.finish<j2.finish);
}

int solve()
{
	int dp[n];

	sort(job.begin(),job.end(),compare);

	for(int i=0;i<n;i++)
		dp[i] = job[i].wt;

	int ans = 0;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(job[j].finish <= job[i].start)
			{
                dp[i] = max(dp[i],job[i].wt+dp[j]);
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

	job.resize(n);
	for(int i=0;i<n;i++)
		cin>>job[i].start>>job[i].finish>>job[i].wt;

	cout<<solve()<<endl;
}
