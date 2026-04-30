#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // initialize graph
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;

    // input edges
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // remove for directed graph
    }

    int source;
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    // initialize
    for(int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra
    for(int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX, u = -1;

        // find min distance node
        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] && !visited[v] &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print result
    for(int i = 0; i < n; i++)
    {
        if(dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}