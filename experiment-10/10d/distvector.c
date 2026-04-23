#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j, k;
    int cost[MAX][MAX], dist[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    /* Initialize distance vector from node 0 */
    for (i = 0; i < n; i++)
        dist[i] = cost[0][i];

    /* Bellman-Ford relaxation */
    for (k = 0; k < n - 1; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i] > dist[j] + cost[j][i]) {
                    dist[i] = dist[j] + cost[j][i];
                }
            }
        }
    }

    printf("Shortest distances from node 0:\n");
    for (i = 0; i < n; i++)
        printf("To node %d = %d\n", i, dist[i]);

    return 0;
}