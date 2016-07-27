/*
Given a sequence, find the length of the longest palindromic subsequence in it.
For example, if the given sequence is “BBABCBCAB”, then the output should be 7
as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB”
are also palindromic subsequences of the given sequence, but not the longest ones.
*/

#include <bits/stdc++.h>
using namespace std;

string str;

void solve(string str)
{
	int n = str.length();
	int dp[n][n];

	for(int i=0;i<n;i++)
		dp[i][i] = 1;    //subsequence of lenght 1 is 1

	for(int width=2;width<=n;width++) // substring of length 2 to n
	{
		for(int i=0;i<(n+1)-width;i++)
		{
			int j = i+(width-1);
			if(str[i] == str[j])
			{
				if(width == 2)
					dp[i][j] = 2;
				else
					dp[i][j] = 2 + dp[i+1][j-1];
			}
			else
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);

		}
	}

	int ans = dp[0][n-1];

	cout<<"The length of the maximum subsequence is : "<<ans<<endl;

	// finding the subsequence
	int i=0, j=n-1;
	int idx[n];  //bit map to indicate which chars are in the subsequence
	memset(idx,0,sizeof(idx));

	while(ans!=0)
	{
		if(i == j)
		{
			idx[i] = 1;
			ans--;
		}

		else if(dp[i][j] == dp[i+1][j] || dp[i][j] == dp[i][j-1])
		{
			if(dp[i][j] == dp[i+1][j])
                i++;

			else
				j-=1;
		}
		else
		{
			idx[i] = idx[j] = 1;
			i+=1;
			j-=1;
			ans-=2;
		}


	}
// printing the subsequence
    cout<<"The Subsequence is : \n";
	for(int i=0;i<n;i++)
	{
		if(idx[i])
			cout<<str[i]<<" ";
	}
}
int main()
{
	cin>>str;
	solve(str);
}
