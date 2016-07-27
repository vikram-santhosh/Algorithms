/*
Prims's algorithm is an algorithm for finding the
Minimum Spanning Tree
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj;
vector<int> dist;
vector<int> visited;
vector<int> start;
int n,s;

void CreateADJ()
{
    int temp;
	adj.resize(n);
	for(int i=0;i<n;i++)
	{
		//adj[i].resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>temp;	 // 0 indicates that an edge is absent
			adj[i].push_back(temp);
		}
	}
}
int nextNode()
{
	int minVal = INT_MAX ;
	int minNode = -1;
	for(int i=0;i<n;i++)
	{
		if(dist[i]<minVal && !visited[i] )
		{
			minVal = dist[i];
			minNode = i;
		}
	}
	return minNode;
}

void prisms()
{
	dist[s] = 0;
	for(int i=0;i<n;i++)
	{
		int u = nextNode();
		visited[u] = 1;

		for(int v=0;v<n;v++)
		{
			if(adj[u][v] && !visited[v] && adj[u][v] < dist[v])
			{
				dist[v] = adj[u][v];
				start[v] = u;
			}
		}
	}
}

void display()
{
    cout<<"Start\t-\tEnd\tWeight\n\n";
    for(int i=1;i<n;i++)
    {
        cout<<start[i]<<"\t-\t"<<i<<"\t"<<dist[i]<<endl;
    }

}

int main()
{
	cin>>n>>s;
	dist.resize(n);
	visited.resize(n);
	start.resize(n);

	for(int i=0;i<n;i++)
	{
		dist[i] = INT_MAX;
		visited[i] = 0;
		start[i] = 0;
	}

	CreateADJ();
	prisms();
	display();
}
