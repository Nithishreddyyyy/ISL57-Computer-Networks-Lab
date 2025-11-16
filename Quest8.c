#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

typedef struct {
	int u;
	int v;
	int wt;
} Edge;

int bellmanFord(int V, Edge edges[], int E, int src, int dist[]) {
	for (int i = 0; i < V; i++) dist[i] = INF;
	dist[src] = 0;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			int u = edges[j].u;
			int v = edges[j].v;
			int wt = edges[j].wt;
			if (dist[u] != INF && dist[u] + wt < dist[v]) {
				if (i == V - 1) {
					// negative cycle detected
					return -1;
				}
				dist[v] = dist[u] + wt;
			}
		}
	}
	return 0;
}

int main(void) {
	int V = 5;
	Edge edges[] = {
		{1, 3, 2},
		{4, 3, -1},
		{2, 4, 1},
		{1, 2, 1},
		{0, 1, 5}
	};
	int E = sizeof(edges) / sizeof(edges[0]);
	int src = 0;
	int dist[5];

	if (bellmanFord(V, edges, E, src, dist) == -1) {
		printf("-1\n");
	} else {
		for (int i = 0; i < V; i++) {
			if (i) printf(" ");
			printf("%d", dist[i]);
		}
		printf("\n");
	}
	return 0;
}