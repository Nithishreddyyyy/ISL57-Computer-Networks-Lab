#include <stdio.h>

#define N 5
#define INF 9999

struct Node {
    int dist[N];
    int via[N];
};

int main() {
    int cost[N][N] = {
        {0,   2,   INF, 1,   INF},  // A
        {2,   0,   3,   2,   INF},  // B
        {INF, 3,   0,   4,   5},    // C
        {1,   2,   4,   0,   3},    // D
        {INF, INF, 5,   3,   0}     // E
    };

    struct Node node[N];
    int i, j, k, updated;

    // Initialize routing tables
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            node[i].dist[j] = cost[i][j];
            node[i].via[j] = j;
        }

    // Distance Vector Algorithm
    do {
        updated = 0;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                for (k = 0; k < N; k++)
                    if (node[i].dist[j] > cost[i][k] + node[k].dist[j]) {
                        node[i].dist[j] = cost[i][k] + node[k].dist[j];
                        node[i].via[j] = k;
                        updated = 1;
                    }
    } while (updated);

    // Display Final Distance Tables
    for (i = 0; i < N; i++) {
        printf("\nRouting Table for Router %c:\n", 'A' + i);
        printf("Dest\tNextHop\tDist\n");
        for (j = 0; j < N; j++)
            printf("  %c\t   %c\t   %d\n", 'A' + j, 'A' + node[i].via[j], node[i].dist[j]);
    }

    return 0;
}
