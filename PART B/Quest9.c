#include <stdio.h>

#define N 5
#define INF 9999

void dij (int graph[N][N], int source){
    int visited[N] = {0};
    int dist[N];
    int i , count , u , v , min;


    for(i = 0 ;  i< N; i++){
        dist[i] = INF;
    }
    dist[source] = 0 ;

    for(count = 0 ; count < N - 1 ; count ++){
        min= INF;
        u = -1;

        for (i = 0 ; i < N ; i ++){
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }
        if(u==-1){
            break;
        }
        visited[u] = 1;

        for(v = 0 ; v < N ; v++){
            if(!visited[v] && graph[u][v] != INF &&
            dist[v] > dist[u]+graph[u][v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("\nShorted paths from node %c\n",'A'+source);
    for(i=0 ; i < N ; i++){
        if(dist[i]!=INF){
            printf("%c -----> %c = %d\n",'A'+source ,'A' + i , dist[i]);
        }else{
            printf("%c ------> %c = NOT REACHABLE\n",'A'+source,'A' + i);
        }
    }
}

int main() {
    int graph[N][N] = {
        {0,   2,   INF, 1,   INF},  // A
        {2,   0,   3,   2,   INF},  // B
        {INF, 3,   0,   4,   5},    // C
        {1,   2,   4,   0,   3},    // D
        {INF, INF, 5,   3,   0}     // E
    };
    int source;
    printf("Enter source node (0=A, 1=B, 2=C, 3=D, 4=E): ");
    scanf("%d", &source);
    dij(graph, source);
    return 0;
}