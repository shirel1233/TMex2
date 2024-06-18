#include <stdio.h>
#include "my_mat.h"

int main() {
    int graph[V][V];
    char a;
    int i = 0, j = 0;

    while (1) {
        scanf(" %c", &a);
        if (a == 'D' || a == EOF) {
            break;
        } else if (a == 'A') {
            initializeGraph(graph);
            floydWarshall(graph);
        } else if (a == 'B') {
            scanf("%d %d", &i, &j);
            if (doesPathExist(graph, i, j)) {
                printf("True\n");
            } else {
                printf("False\n");
            }
        } else if (a == 'C') {
            scanf("%d %d", &i, &j);
            printf("%d\n", shortestPathLength(graph, i, j));
        }
    }

    return 0;
}
