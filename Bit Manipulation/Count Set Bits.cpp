/*
x & (x-1) flips the right most  set bit . Count the number of flips need to make the number  
Brian Kernighan’s Algorithm 
*/

#include <bits/stdc++.h>
using namespace std;

int countSet(int x)
{
	int c = 0;
	while(x)
	{
		x = x & (x-1);
		c++;
	}
	return c;
}

int countCleared(int x)
{
	int c = 0;
	x = ~x;
	while(x)
	{
		x = x & (x-1);
		c++;
	}
	return c;
}
int main()
{
	int n;
	cin>>n;
	cout<<"Number of bits set in 32 bit range : "<<countSet(n)<<endl;
	cout<<"Number of cleared set 32 bit range : "<<countCleared(n)<<endl;
}
