/*
LCS Problem Statement: Given two sequences, find the length
of longest subsequence present in both of them. A subsequence
 is a sequence that appears in the same relative order, but
 not necessarily contiguous. For example, “abc”, “abg”, “bdf”,
 “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a
 string of length n has 2^n different possible subsequences.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

*/

#include <bits/stdc++.h>
using namespace std;

string str1,str2;

void findLCS()
{
	int n1 = str1.length();
	int n2 = str2.length();
	int ans = 0;
    int dp[n1+1][n2+1];

	for(int i=0;i<=n1;i++)
        for(int j=0;j<=n2;j++)
            dp[i][j]=0;

	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(str1[i] == str2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(dp[i][j] > ans)
				ans = dp[i][j];
		}
	}
	cout<<"Length of LCS : "<<ans<<endl;

}
int main()
{
	cin>>str1>>str2;
	findLCS();
}
