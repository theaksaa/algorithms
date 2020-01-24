#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int u, v, w;
	bool operator<(const struct edge &tmp)
	{
		return w < tmp.w;
	}
};

struct edge make_edge(int u, int v, int w)
{
	struct edge e;
	e.u = u;
	e.v = v;
	e.w = w;
	return e;
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

int kruskal(vector<struct edge> adj, int n)
{
	sort(adj.begin(), adj.end());
	
	int cost = 0, k = 0;
	int parent[n], erank[n] = { 0 };
	for(int i = 0; i < n; i++) parent[i] = i;
	
	for(struct edge e : adj)
		if(find(e.u, parent) != find(e.v, parent))
		{
			cost += e.w;
			k++;
			dsu(e.u, e.v, parent, erank);
		}
		
	if(k == n - 1) return cost;
	return -1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<struct edge> adj;
	
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj.push_back(make_edge(u, v, w));
	}
	
	printf("cost: %d\n", kruskal(adj, n));
}
