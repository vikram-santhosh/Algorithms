/*Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’
under modulo ‘m’.

The modular multiplicative inverse is an integer ‘x’ such that.

 a x ≡ 1 (mod m)  The value of x should be in {0, 1, 2, … m-1}, i.e., in the
ring of integer modulo m.

The multiplicative inverse of “a modulo m” exists if and only if a and m are
relatively prime (i.e., if gcd(a, m) = 1).
*/


#include <bits/stdc++.h>
using namespace std;

int gcd,x,y;

void extended_euclid(int a,int b)
{
	if(b==0)
	{
		gcd = a;
		x = 1;
		y = 0;
	}
	else
	{
		extended_euclid(b,a%b);
		int temp = x;
		x = y;
		y = temp - (a/b) * y;
	}
}

void mul_inverse(int a, int b) // inverse of a in b
{
	extended_euclid(a,b);
	if(gcd != 1)
	{
		cout<<"Multiplicative Inverse does not exist\n";
		return;
	}
	else
	{
		x = ( x%b + b)% b;
		cout<<x<<endl;
	}
}

int main()
{
	int a,b;
	cin>>a>>b;
	mul_inverse(a,b);
}
