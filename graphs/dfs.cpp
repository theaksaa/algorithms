#include <stdio.h>
#include <list>

using namespace std;

/*
5 6
0 1
0 3
3 4
1 4
2 4
1 2
5 4
0 2
2 3
0 3
1 4
*/

int dfs(int s, list<int>*adj, bool *visited)
{
    if(visited[s]) return 0;
    visited[s] = true;
    for(list<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++)
        dfs(*it, adj, visited);
    return 1;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    bool visited[n] = { false };
    list<int> adj[n];

    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s += dfs(i, adj, visited);
    }

    printf("sum of isolated graphs: %d\n", s);

    for(int i = 0; i < n; i++)
    {
        printf("\nvertex %d is conntected with: ", i);
        for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
            printf("%d ", *it);
    }
}
