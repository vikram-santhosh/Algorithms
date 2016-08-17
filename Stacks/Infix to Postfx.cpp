/*Infix to Postfix 
Infix expression: The expression of the form a op b. When
an operator is in-between every pair of operands. 
Postfix expression: The expression of the form a b op. When an operator is 
followed for every pair of operands. 

Why postfix representation of the expression? 
The compiler scans the expression either from left to right or from right to left. 
Consider the below expression: a op1 b op2 c op3 d If op1 = +, op2 = *, op3 = +
The compiler first scans the expression to evaluate the expression b * c, then again scan
the expression to add a to it. The result is then added to d after another
scan. The repeated scanning makes it very in-efficient. It is better to
convert the expression to postfix(or prefix) form before evaluation. 

The corresponding expression in postfix form is: abc*d++. The postfix expressions
can be evaluated easily using a stack. We will cover postfix expression
evaluation in a separate post. */


#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
	switch(ch)
	{
		case '+'	:
		case '-'	:	return 1;
		case '/'	:
		case '*'	: 	return 2;
		case '^'	:	return 3;
		default		: 	return -1; // when '(' is seen
	}
}
int main()
{
	string exp;
	cin>>exp;
	stack<char>op;
	vector<char>postfix;

	for(int i=0;i<exp.length();i++)
	{
		if(isalnum(exp[i]))
			postfix.push_back(exp[i]);
		else if(exp[i] == '(')
			op.push(exp[i]);

		else if (exp[i] == ')')
		{
			while(op.top() != '(')
			{
				postfix.push_back(op.top());
				op.pop();
			}
			op.pop(); // pop '('
		}
		else // input is an operator
		{
			while( !op.empty() && prec(op.top()) >= prec(exp[i]) )
			{
				postfix.push_back(op.top());
				op.pop();
			}
			op.push(exp[i]);
		}
	}

	while(!op.empty())
    {
        postfix.push_back(op.top());
        op.pop();
    }

    for(int i=0;i<postfix.size();i++)
        cout<<postfix[i];

}
