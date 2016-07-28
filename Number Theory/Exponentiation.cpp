/*
Compute M^N in O(log N)
*/

#include <bits/stdc++.h>
using namespace std;

int exponentiate(int m,int n)
{
	int ans;
	if(n == 0)
		return 1;

	ans = exponentiate(m,n/2);

	if(n&1)
		return m*ans*ans;
	else
		return ans*ans;
}

int main()
{
	int m,n;
	cin>>m>>n;
	cout<<exponentiate(m,n);
}
