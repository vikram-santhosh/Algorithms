/*
	Find the DFS of given graph
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj;
int *visited;
int n,m;  //nodes and edges
int s;

void dfs(int u)
{
	visited[u] = 1;
	cout<<u<<" ";
	for(int i=0;i<adj[u].size();i++)
	{
		int v = adj[u][i];
		if(!visited[v])
		{
			dfs(v);
		}
	}

}
int main()
{
	cout<<"Enter number of nodes and edges"<<endl;
	cin>>n>>m;
	visited = new int[n];
	memset(visited,0,n);

	int v1,v2;
	adj.resize(n);
	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	cout<<"Source\n";
	cin>>s;

	cout<<"DFS\n";
	dfs(s);

}
