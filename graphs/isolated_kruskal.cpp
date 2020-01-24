#include <bits/stdc++.h>
using namespace std;

/*
11 12
0 1 10
0 5 20
1 5 3
1 2 5
1 3 2
2 3 5
2 5 10
4 5 20
6 7 3
6 8 5
7 8 1
9 10 2
*/

typedef struct edge
{
	int u, v, w;
	
	bool operator<(const struct edge &tmp)
	{
		return w < tmp.w;
	}
} Edge;

Edge make_edge(int u, int v, int w)
{
	Edge e;
	e.u = u;
	e.v = v;
	e.w = w;
	return e;
}

int isolated(int s, vector<pair<int, int>> *adj, vector<Edge> *isolated_edges, bool *visited, int k)
{
	if(visited[s]) return 0;
	visited[s] = true;
	
	for(pair<int, int> p : adj[s])
	{
		isolated_edges[k].push_back(make_edge(s, p.first, p.second));
		isolated(p.first, adj, isolated_edges, visited, k);
	}
	
	return 1;
}

int find(int v, int *parent)
{
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v], parent);
}

void dsu(int u, int v, int *parent, int *erank)
{
	if(erank[u] < erank[v]) swap(u, v);
	if(erank[u] == erank[v]) erank[u]++;
	parent[v] = u;
}

int kruskal(vector<Edge> edges, int n)
{
	sort(edges.begin(), edges.end());
	
	/*for(Edge e : edges)
		printf("  > %d - %d = %d\n", e.u, e.v, e.w);*/
	
	int cost = 0, k = 0;
	int parent[n], erank[n] = { 0 };
	//for(int i = 0; i < n; i++) parent[i] = i;
	
	for(Edge e : edges) parent[e.u] = e.u, parent[e.v] = e.v;
	
	vector<Edge> result;
	for(Edge e : edges)
	{
		if(find(e.u, parent) != find(e.v, parent))
		{
			cost += e.w;
			k++;
			result.push_back(e);
			dsu(e.u, e.v, parent, erank);
		}
	}
	/*for(Edge e : result)
		printf("  > %d - %d = %d\n", e.u, e.v, e.w);*/
	if(k == n - 1) return cost;
	return -1;
}

int get_vertexes(vector<Edge> edges, int n)
{
	int k = 0;
	bool v[n] = { false };
	for(Edge e : edges)
	{
		if(!v[e.u]) v[e.u] = true, k++;
		if(!v[e.v]) v[e.v] = true, k++;
	}
	return k;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> adj[n];
	
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	
	int k = 0;
	bool *visited = (bool*) calloc(n, sizeof(bool));
 	vector<Edge> isolated_edges[n];
	for(int i = 0; i < n; i++)
		if(isolated(i, adj, isolated_edges, visited, k)) k++;
	
	for(int i = 0; i < k; i++)
	{
		printf("\nisolated %d (cost: %d):\n", i, kruskal(isolated_edges[i], get_vertexes(isolated_edges[i], n)));
		for(Edge e : isolated_edges[i])
			printf("%d - %d = %d\n", e.u, e.v, e.w);
	}
}
