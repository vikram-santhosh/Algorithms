#include <bits/stdc++.h>
using namespace std;


int find_parent(int x)
{
	if(parent[x] == x)
		return x;
	else
		return (parent[x] = find_parent(parent[x]));
}
void union(int u,int v)
{
	par_u = find_parent(u);
	par_v = find_parent(v);

	if(par_u == par_v)
		return;
	else
		parent[par_u] = par_v;
}
int main()
{
	int n,q;
	int u,v;
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>a[i];

	for(int i=0;i<q;i++)
	{
		cin>>u>>v;
		union(u,v);
	}

}