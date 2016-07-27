/* Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering
of vertices such that for every directed edge uv, vertex u comes before v in
the ordering. Topological Sorting for a graph is not possible if the graph is
not a DAG.

Time Complexity: The above algorithm is simply DFS with an extra
stack. So time complexity is same as DFS which is O(V+E).

Applications: Topological Sorting is mainly used for scheduling jobs from the
given dependencies among jobs. */


#include <bits/stdc++.h>
using namespace std;

vector<vector<int> >adj;
stack<int> s;
bool *visited;
int n;

void createGraph()
{
	int a,b;
	adj.resize(n);

    for(int j=0;j<n;j++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
}

void topoSortUtil(int i)
{
	visited[i] = true;
	for(int j=0;j<adj[i].size();j++)
	{
		int node = adj[i][j];
		if(!visited[node])
            topoSortUtil(node);
	}
	s.push(i);
}

void topoSort()
{
	memset(visited,false,sizeof(visited));

	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			topoSortUtil(i);
	}
}
void display()
{
	for(int i=0;i<n;i++)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main()
{
	cin>>n;
	visited = new bool[n];
	createGraph();
	topoSort();
	display();
}
