/*Evaluation of Postfix Expression

The Postfix notation is used to represent algebraic expressions. The
expressions written in postfix form are evaluated faster compared to infix
notation as parenthesis are not required in postfix. We have discussed infix
to postfix conversion.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string postfix;
	stack<int> eval;

	cin>>postfix;

	for(int i=0;i<postfix.length();i++)
	{
		char ch = postfix[i];
		if(isdigit(postfix[i]))
			eval.push(ch - '0');
		else
		{
			int b = eval.top() ;
			eval.pop();
			int a = eval.top();
			eval.pop();
			switch(ch)
			{
				case '+'	:	eval.push(a+b);
								break;
				case '-'	:	eval.push(a-b);
								break;
				case '*'	:	eval.push(a*b);
								break;
				case '/'	:	eval.push(a/b);
								break;
			}
		}
	}
	cout<<eval.top()<<endl;
}
