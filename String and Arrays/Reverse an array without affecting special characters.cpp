/*Reverse an array without affecting special characters Given a string, that
contains special character together with alphabets (‘a’ to ‘z’ and ‘A’ to
‘Z’), reverse the string in a way that special characters are not affected.

Examples:

Input:   str = "a,b$c" Output:
str = "c,b$a"
Note that $ and , are not moved anywhere.   Only subsequence "abc" is reversed
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	stack<char> st;

	cin>>str;

	for(int i=0;i<str.length();i++)
	{
		if(isalpha(str[i]))
			st.push(str[i]);
	}

	for(int i=0;i<str.length();i++)
	{
		if(isalnum(str[i]))
		{
			cout<<st.top();
			if(!st.empty())
                st.pop();
		}
		else
			cout<<str[i];
	}
}
