#include <bits/stdc++.h>
using namespace std;

/*
6 7
3 0
3 4
4 1
4 2
0 1
1 2
2 5
*/

void topological(int s, vector<int> *adj, bool *visited, vector<int> *result)
{
	if(visited[s]) return;
	visited[s] = true;
	for(int e : adj[s])
		topological(e, adj, visited, result);
	(*result).push_back(s);
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
	}
	
	vector<int> result;
	for(int i = 0; i < n; i++) topological(i, adj, visited, &result);
	reverse(result.begin(), result.end());
	for(int e : result)
		printf("%d ", e);
}
