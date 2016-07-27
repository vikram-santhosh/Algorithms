/*
Kruskal's algorithm is a greedy algorithm in graph theory that finds a minimum
spanning tree for a connected weighted graph.  It finds a subset of the edges
that forms a tree that includes every vertex, where the total weight of all
the edges in the tree is minimized. This algorithm is directly based on the
MST( minimum spanning tree) property.
Time Complexity: O(ElogE) or O(ElogV).
Sorting of edges takes O(ELogE) time. After sorting, we iterate through all
edges and apply find-union algorithm. The find and union operations can take
atmost O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value
of E can be atmost V^2, so O(LogV) are O(LogE) same. Therefore, overall time
complexity is O(ElogE) or O(ElogV)
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int u;
	int v;
	int cost;
};

int n,m;
vector<node> edge;
vector<int> subset;

void getEdges()
{
	edge.resize(n);
	subset.resize(n);

	int u,v,cost;

	for(int i=0;i<n;i++)
	{
		cin>>u>>v>>cost;
		edge[i].u = u;
		edge[i].v = v;
		edge[i].cost = cost;
	}
}

bool cmp(node a, node b)
{
	return (a.cost < b.cost);
}

void makeSet()
{
	for(int i=0;i<m;i++)
		subset[i] = i;
}

void kruskal()
{
	vector<node> res;

	for(int i=0;i<n;i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;

		if(subset[u] != subset[v])
		{
			subset[u] = subset[v] = max(subset[u],subset[v]);
			res.push_back(edge[i]);
		}
	}

	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].u<<" - "<<res[i].v<<" = "<<res[i].cost<<endl;
	}
}

int main()
{
	cin>>m>>n; // number of nodes and edges
	edge.resize(n);
	subset.resize(m);

	getEdges();
	makeSet();
	sort(edge.begin(),edge.end(),cmp);  //sort edges in non descending order


	kruskal();
}
