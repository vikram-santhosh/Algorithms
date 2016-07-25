/*
	Find the BFS of given graph
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj;
int n,m;  //nodes and edges
int s;
void bfs(int s)
{
	queue<int> q;
	int visited[n] = {0};
	q.push(s);
	cout<<s<<" ";
	visited[s] = 1;

	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++)
		{
			int u = adj[v][i];
			if(!visited[u])
			{
				visited[u] = 1;
				q.push(u);
				cout<<u<<" ";
			}
		}

	}
}
int main()
{
	cout<<"Enter number of nodes and edges"<<endl;
	cin>>n>>m;

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

	cout<<"BFS\n";
	bfs(s);

}
