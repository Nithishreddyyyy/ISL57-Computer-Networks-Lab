#include <stdio.h>
#define INF 999
#define N 5

void dijkstra(int graph[N][N], int n, int src) {
    int dist[N], visited[N] = {0};
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min)
                min = dist[j], u = j;
        if (u == -1) break;

        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nShortest paths from %c:\n", 'A' + src);
    for (int i = 0; i < n; i++)
        printf("%c ---> %c = %d\n", 'A' + src, 'A' + i, dist[i]);
}

int main() {
    int graph[N][N] = {
        {0, 2, INF, 1, INF},
        {2, 0, 3, 2, INF},
        {INF, 3, 0, INF, 1},
        {1, 2, INF, 0, 3},
        {INF, INF, 1, 3, 0}
    };
    int src;
    printf("Enter source node (0-4): ");
    scanf("%d", &src);
    dijkstra(graph, N, src);
    return 0;
}
