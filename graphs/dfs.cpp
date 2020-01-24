#include <bits/stdc++.h>
using namespace std;
/*
8 9
0 1
0 5
1 5
1 2
1 3
2 3
2 5
4 5
6 7
*/

int dfs(int s, vector<int> *adj, bool *visited)
{
	if(visited[s]) return 0;
	visited[s] = true;
	
	for(int e : adj[s])
		dfs(e, adj, visited);
		
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
	
	int s = 0;
	for(int i = 0; i < n; i++)
		if(dfs(i, adj, visited)) s++;

	printf("%d\n", s);
}

