/*Given a set of strings, find the longest common prefix

Input  : {"apple", "ape", "april"}
Output : "ap"*/

#include <bits/stdc++.h>
using namespace std;

string common_prefix;

string find_prefix(string s1,string s2)
{
	string ans;
	for(int i=0,j=0;i<s1.length(),j<s2.length();i++,j++)
	{
		if(s1[i] == s2[j])
		{
			ans.push_back(s1[i]);
		}
		else
			return ans;
	}
}
string prefixUtil(string str[],int n)
{
	common_prefix = str[0];

	for(int i=1;i<n;i++)
	{
		common_prefix = find_prefix(common_prefix,str[i]);
	}
	return common_prefix;
}
int main()
{
	int n;
	cin>>n;
	string str[n];

	for(int i=0;i<n;i++)
		cin>>str[i];

	cout<<prefixUtil(str,n)<<endl;
}
