#include <bits/stdc++.h>

/*
5 6
0 1 5
0 4 1
0 3 9
4 3 2
1 2 10
2 3 6
*/

using namespace std;
int n, m;

void dijkstra(list<pair<int,int>>*adj)
{
	bool visited[n];
	int distance[n];
	for(int i = 0; i < n; i++) distance[i] = INT_MAX, visited[i] = false;
	
	distance[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		if(visited[s]) continue;
		visited[s] = true;
		for(list<pair<int,int>>::iterator it = adj[s].begin(); it != adj[s].end(); it++)
		{
			int c = (*it).first;
			int t = (*it).second;
			if(distance[s]+t < distance[c])
			{
				distance[c] = distance[s]+t;
				q.push(c);
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		printf("cvor %d je udaljen od 0 za: %d\n", i, distance[i]);
	}
}

int main()
{
	
	scanf("%d%d", &n, &m);
	list<pair<int, int>> adj[n];
	
	for(int i = 0; i < m; i++)
	{
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		adj[x].push_back({y, t});
		adj[y].push_back({x, t});
	}
	dijkstra(adj);
}
