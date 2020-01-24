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

int *bfs(int s, vector<int> *adj, int n)
{
	int *distance = (int*) malloc(n * sizeof(int));
	bool visited[n];
	for(int i = 0; i < n; i++) distance[i] = INT_MAX, visited[i] = false;
	distance[s] = 0;

	queue<int> q;
	q.push(s);
	
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		
		if(visited[c]) continue;
		visited[c] = true;
		
		for(int e : adj[c])
			if(distance[c] + 1 < distance[e])
			{
				distance[e] = distance[c] + 1;
				q.push(e);
			}
	}
	return distance;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> adj[n];
	
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
	}
	
	int *distance = bfs(0, adj, n);
	
	for(int i = 0; i < n; i++)
		printf("%d -> %d = %d\n", 0, i, distance[i]);

}
