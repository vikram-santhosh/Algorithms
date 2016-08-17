/*
Find 7/8 of a number without using multiplication or division operator
*/
#include <bits/stdc++.h>
using namespace std;

int multiply_by_7(int n)
{
	int ans = n<<3;
	ans -= n;
	return ans;
}

int divide_by_8(int n)
{
	int ans = n>>3;
	return ans;
}
int main()
{
	int n;
	cin>>n;

	int x = multiply_by_7(n);
	int y = divide_by_8(x);

	cout<<y<<endl;
}
