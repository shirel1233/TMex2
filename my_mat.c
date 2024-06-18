#include <stdio.h>
#include "my_mat.h"

#define INF 99999

void initializeGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }
}

void floydWarshall(int graph[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]
                && graph[k][j] != INF && graph[i][k] != INF)
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF || graph[i][j] == 0) {
                graph[i][j] = -1;
            }
        }
    }
}

int doesPathExist(int graph[V][V], int i, int j) {
    return (graph[i][j] != -1);
}

int shortestPathLength(int graph[V][V], int i, int j) {
    return graph[i][j];
}
