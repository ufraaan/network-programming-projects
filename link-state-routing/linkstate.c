#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], dist[MAX], visited[MAX];
    int i, j, u, min;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    /* Initialize distances from node 0 */
    for (i = 0; i < n; i++) {
        dist[i] = cost[0][i];
        visited[i] = 0;
    }
    dist[0] = 0;
    visited[0] = 1;

    /* Dijkstra's algorithm */
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("Shortest distances from node 0:\n");
    for (i = 0; i < n; i++)
        printf("To node %d = %d\n", i, dist[i]);

    return 0;
}