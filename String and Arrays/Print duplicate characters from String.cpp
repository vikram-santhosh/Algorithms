#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<char,int> m;
	string str;
	cin>>str;

	for(int i=0;i<str.length();i++)
	{
		char ch = str[i];
		if(m.find(ch) != m.end())
			m[ch] ++;
		else
			m[ch] = 1;
	}

	map<char,int>::iterator it;

	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second > 1)
			cout<<it->first<<endl;
	}
}

