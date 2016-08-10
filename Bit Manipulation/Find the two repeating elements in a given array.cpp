/*You are given an array of n+2 elements. All elements of the array are in range
1 to n. And all elements occur once except two numbers which occur twice. Find
the two repeating numbers.

For example, array = {4, 2, 4, 5, 2, 3, 1} and n = 5

The above array has n + 2 = 7 elements with all elements occurring once except
2 and 4 which occur twice. So the output should be 4 2.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
	int x = 1,y = 1;
	cin>>n;
	int a[n+2];
	for(int i=1;i<n;i++)  //inputing n-1 elements
		cin>>a[i];

	for(int i=1;i<n;i++)
		x ^= a[i];

	for(int i=1;i<=n;i++)
		y ^= i;

	int ans = x^y;

	cout<<ans<<endl;
}
