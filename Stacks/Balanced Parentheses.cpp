/*

Given an expression string exp, write a program to examine whether the pairs
and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp. For example, the
program should print true for exp = “[()]{}{[()()]()}” and false for exp =
“[(])” 

*/

#include <bits/stdc++.h>
using namespace std;


bool isBalanced(string str)
{
	stack<char> st;
	for(int i=0;i<str.length();i++)
	{
		char ch = str[i];
		switch(ch)
		{
			case '('	:
			case '{'	:
			case '['	:	st.push(str[i]);
							break;
			case ')'	:	if(st.top() == '(')
								st.pop();
							else
								return false;
							break;

			case '}'	:	if(st.top() == '{')
								st.pop();
							else
								return false;
							break;

			case ']'	:	if(st.top() == '[')
								st.pop();
							else
								return false;
							break;
		}
		//cout<<st.top()<<endl;
	}

	if(st.empty())
		return true;
	else
		return false;
}
int main()
{
	string str;
	cin>>str;

	cout<<isBalanced(str)<<endl;
}
