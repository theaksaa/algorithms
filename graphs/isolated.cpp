#include <bits/stdc++.h>
using namespace std;

/*
8 8
3 0
3 4
4 1
4 2
0 1
1 2
2 5
6 7
*/

int isolated(int s, vector<int> *adj, bool *visited, vector<vector<int>> *isolated_graphs, int k)
{
	if(visited[s]) return 0;
	visited[s] = true;
	
	for(int e : adj[s])
	{
		isolated(e, adj, visited, isolated_graphs, k);
		isolated_graphs[k][s].push_back(e);
	}
	return 1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> adj[n];
	bool *visited = (bool*) calloc(n, sizeof(bool));
	
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	int k = 0;
	vector<vector<int>> isolated_graphs[n];
	for(int i = 0; i < n; i++) isolated_graphs[i].resize(n);
	
	for(int i = 0; i < n; i++)
		if(isolated(i, adj, visited, isolated_graphs, k)) k++;
		
	for(int i = 0; i < k; i++)
	{
		printf("\nISOLATED %d:", i);
		for(int j = 0; j < n; j++)
		{
			printf("\n   %d:\n      ", j);
			for(int e : isolated_graphs[i][j])
				printf("%d ", e);
		}
	}
}
