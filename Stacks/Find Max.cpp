/*Design a Data Structure SpecialStack that supports all the stack operations
like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
which should return minimum element from the SpecialStack. All these
operations of SpecialStack must be O(1). To implement SpecialStack, you should
only use standard Stack data structure and no other data structure like
arrays, list, .. etc.

Solution: Use two stacks: one to store actual stack elements and other as an
auxiliary stack to store minimum values. The idea is to do push() and pop()
operations in such a way that the top of auxiliary stack is always the
minimum. Let us see how push() and pop() operations work.

Enter 1 to insert , 2 to pop, 3 to check if empty and 4 to return max
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> primary;
	stack<int> auxiliary;

	int n; //number of operations
	int ch,num;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>ch;
		if(ch == 1)
		{
			cin>>num;
			if(primary.empty())
            {
                primary.push(num);
                auxiliary.push(num);
            }
            else
            {
                if(num >= primary.top() )
                    auxiliary.push(num);
                else if(num < primary.top())
                    auxiliary.push(primary.top());
                primary.push(num);
            }
		}
		else if(ch == 2)
		{
			primary.pop();
			auxiliary.pop();
		}
		else if(ch == 3)
		{
			cout<<!primary.empty()<<endl;
		}
		else if(ch == 4)
		{
			cout<<auxiliary.top()<<endl;
		}
	}
}
