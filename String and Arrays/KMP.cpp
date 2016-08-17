#include <bits/stdc++.h>
using namespace std;

int* findLPS(string pattern)
{
	int j = 0;
	int i = 1;
	int n = pattern.length();
	int lps[n] = {0}; // longest prefix suffix array
	while(i<n)
	{
		if(pattern[j] == pattern[i])
		{
			lps[i] = j+1;
			j++;
			i++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}

bool KMP(int* lps,string text,string pattern)
{
	int i = 0;
	int j = 0;
	int n = text.length();
	int m = pattern.length();

	while(i<n && j<m)
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
		if(j==m)
			return true;
	}
	return false;
}
int main()
{
	string text,pattern;
	cin>>text>>pattern;

	int *lps = findLPS(pattern);

	cout<<KMP(lps,text,pattern);
}
