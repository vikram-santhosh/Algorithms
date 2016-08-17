/*Idea behind Euclid’s Algorithm is GCD(A, B) = GCD(B, A % B). The algorithm
will recurse until A % B = 0.

Time Complexity: The time complexity of Euclid’s Algorithm
is O(log(max(A,B))) */

#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b)
{
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<"GCD of A and B is : "<<GCD(a,b)<<endl;
}
