/*Find the Missing Number You are given a list of n-1 integers and these
integers are in the range of 1 to n. There are no duplicates in list. One of
the integers is missing in the list. Write an efficient code to find the
missing integer.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
	int x = 1,y = 1;
	cin>>n;
	int a[n];
	for(int i=1;i<n;i++)  //inputing n-1 elements
		cin>>a[i];

	for(int i=1;i<n;i++)
		x ^= a[i];

	for(int i=1;i<=n;i++)
		y ^= i;

	int ans = x^y;

	cout<<ans<<endl;
}
