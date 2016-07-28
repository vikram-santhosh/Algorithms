/*Given three numbers x, y and p, compute (x^y) % p
(a mod p) (b mod p) ≡  (ab) mod p
or equivalently ( (a mod p) (b mod p) ) mod p  =  (ab) mod p
Time Complextity : O(log n)
*/

#include <bits/stdc++.h>
using namespace std;


int modular_exp(int x,int y,int p)
{
	y = y % p;
	int ans = 1;
	while(y!=0)
	{
		if(y&1)
		{
			ans = (ans*x)%p;
		}
		x = (x*x)%p;
		y/=2 ;
	}
	return ans;
}
int main()
{
	int x,y,p; // (x^y)mod p
	cin>>x>>y>>p;

	cout<<modular_exp(x,y,p)<<endl;
}
