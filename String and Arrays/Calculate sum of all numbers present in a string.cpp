/*Calculate sum of all numbers present in a string
Given a string containing alphanumeric characters, calculate sum of all numbers present in the string.

Examples:

Input:  1abc23
Output: 24*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;

	int sum = 0;

	for(int i=0;i<str.length();i++)
	{
		if(isdigit(str[i]))
		{
			sum += (int) (str[i] - '0');
		}
	}
	cout<<sum;
}
