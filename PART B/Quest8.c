#include <stdio.h>

#define N 5
#define INF 99999

typedef struct {
    int dist[N];
    int via[N];
} Node;

int main() {
    int cost[N][N] = {
        {0,   2,   INF, 1,   INF},
        {2,   0,   3,   2,   INF},
        {INF, 3,   0,   4,   5},
        {1,   2,   4,   0,   3},
        {INF, INF, 5,   3,   0}
    };
    Node node[N];
    int i, j, k, updated;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            node[i].dist[j] = cost[i][j];
            if (cost[i][j] != INF && i != j)
                node[i].via[j] = j;
            else
                node[i].via[j] = -1;
        }
    }
    do {
        updated = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                for (k = 0; k < N; k++) {
                    if (node[i].dist[k] != INF &&
                        node[k].dist[j] != INF &&
                        node[i].dist[j] > node[i].dist[k] + node[k].dist[j]) {

                        node[i].dist[j] = node[i].dist[k] + node[k].dist[j];
                        node[i].via[j] = node[i].via[k];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    for (i = 0; i < N; i++) {
        printf("\nRouting Table for Router %c:\n", 'A' + i);
        printf("Dest\tNextHop\tDist\n");
        for (j = 0; j < N; j++) {
            if (node[i].via[j] != -1)
                printf("%c\t%c\t%d\n", 'A'+j, 'A'+node[i].via[j], node[i].dist[j]);
            else
                printf("%c\t-\t%d\n", 'A'+j, node[i].dist[j]);
        }
    }
    return 0;
}