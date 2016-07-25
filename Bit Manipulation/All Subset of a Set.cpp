/* A big advantage of bit manipulation is that it can help to iterate over all
the subsets of an N-element set. As we all know there are 2N possible subsets
of any given set with N elements. What if we represent each element in a
subset with a bit. A bit can be either 0 or 1, thus we can use this to denote
whether the corresponding element belongs to this given subset or not. So each
bit pattern will represent a subset. */

#include <bits/stdc++.h>
using namespace std;

void findSubsets(char arr[],int n)
{
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i & (1<<j))
				cout<<arr[j];
		}
		cout<<endl;
	}
}
int main()
{
	int n;
	char *arr;
	cin>>n;
    arr = new char[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];
	findSubsets(arr,n);
}
