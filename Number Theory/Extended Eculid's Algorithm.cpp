/*Extended Euclid Algorithm: This is the extended form of Euclid’s Algorithm
explained above. GCD(A,B) has a special property that it can always be
represented in the form of an equation, i.e., Ax + By = GCD(A, B).

Time Complexity: The time complexity of Extended Euclid’s Algorithm is
O(log(max(A, B)))*/

#include <bits/stdc++.h>
using namespace std;

int gcd,x,y;

void extended_euclid(int a,int b)
{

	if(b==0) // base case
	{
		gcd = a;
		x = 1;
		y = 0;
	}
	else
	{
		extended_euclid(b,a%b);
		int tmp = x;
		x = y;
		y = tmp - (a/b) * y;
	}

}
int main()
{
	int a,b;
	cin>>a>>b;
	extended_euclid(a,b);
	cout<<" x : "<<x<<" y : "<<y<<endl;
}
