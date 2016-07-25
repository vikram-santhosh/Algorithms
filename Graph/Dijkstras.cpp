/*
Dijkstra's algorithm is an algorithm for finding the shortest paths
from source to all vertices .
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj;
vector<int> dist;
vector<int> visited;
int n,source;

void CreateADJ()
{
	adj.resize(n);
	for(int i=0;i<n;i++)
	{
		adj[i].resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>adj[i][j];		 // 0 indicates that an edge is absent
		}
	}
}

int nextNode()
{
	int minVal = INT_MAX , minNode = -1;
	for(int i=0;i<n;i++)
	{
		if(dist[i]<minVal && !visited[i])
		{
			minVal = dist[i];
			minNode = i;
		}
	}
	return minNode;
}
void dijkstra()
{
	cin>>source;
	dist[source] = 0;

	for(int i=0;i<n-1;i++)
	{
		int u = nextNode();
		visited[u] = 1;
		for(int v=0;v<n;v++)
		{
			if(adj[u][v] && !visited[v])
				if(dist[u]+adj[u][v] < dist[v])
					dist[v] = dist[u] + adj[u][v];
		}
	}
}
void display()
{
	for(int i=1;i<n;i++)
	{
		cout<<"Minimum Distance from Source to Node "<<i<<" : " <<dist[i]<<endl;
	}
}
int main()
{
	cin>>n;
	visited.resize(n);
	dist.resize(n);

	fill(visited.begin(),visited.end(),0);
	fill(dist.begin(),dist.end(),INT_MAX);

	CreateADJ();
	dijkstra();
	display();
}
