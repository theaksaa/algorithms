#include <bits/stdc++.h>
using namespace std;

/*
5 6
0 1 5
0 4 1
0 3 9
4 3 2
1 2 10
2 3 6
*/

int dijkstra(int s, int e, vector<pair<int, int>> *adj, int n)
{
	int distance[n];
	bool visited[n];
	for(int i = 0; i < n; i++) distance[i] = INT_MAX, visited[i] = false;
	
	distance[s] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	
	while(!pq.empty())
	{
		int c = pq.top().second;
		pq.pop();
		
		if(visited[c]) continue;
		visited[c] = true;
		
		for(pair<int, int> k : adj[c])
			if(distance[c] + k.second < distance[k.first])
			{
				distance[k.first] = distance[c] + k.second;
				pq.push(make_pair(-distance[k.first], k.first));
			}
	}
	return distance[e];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> adj[n];
	
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
	
	int dist = dijkstra(4, 2, adj, n);
	printf("dist: %d\n", dist);
}
