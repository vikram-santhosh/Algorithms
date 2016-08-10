/*: Write an efficient program for printing k largest elements in an array.
: Elements in array can be in any order.

For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for
the largest 3 elements i.e., k = 3 then your program should print 50, 30 and
23.
*/

#include <bits/stdc++.h>
using namespace std;

void heapify(int a[],int node,int k)
{
	int left = 2*node;
	int right = 2*node+1;
	int _min = node;

	if(right < k && a[right]<a[node])
		_min = right;

    if(left < k && a[left]<a[node])
		_min = left;

	if(node != _min)
    {
        swap(a[node],a[_min]);
        heapify(a,_min,k);
    }
}
int* heap_util(int *a,int k)
{
	for(int i=k/2;i>=0;i--)
	{
		heapify(a,i,k);
	}
	return a;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int *b = heap_util(a,k);

	for(int i=k;i<n;i++)
    {
        {
            swap(b[0],a[i]);
            heapify(b,0,k);
        }
    }

    for(int i=0;i<k;i++)
    {
        cout<<b[i]<<" ";
    }
}
