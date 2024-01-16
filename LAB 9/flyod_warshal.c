#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int next[MAX_VERTICES][MAX_VERTICES];
void initialize(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            next[i][j] = j;
        }
    }
}
void readGraph(FILE *file, int vertices) {
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            fscanf(file, "%d", &graph[i][j]);
            if (i == j) {
                next[i][j] = 0;
            }
        }
    }
}
void floydWarshall(int vertices) {
    for (int k = 1; k <= vertices; k++) {
        for (int i = 1; i <= vertices; i++) {
            for (int j = 1; j <= vertices; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}
void printShortestPath(int source, int destination) {
    printf("Shortest Path from vertex %d to vertex %d: %d", source, destination, source);
int current = source;
    while (current != destination) {
        current = next[current][destination];
        printf("-->%d", current);
    }
printf("\nPath weight: %d\n", graph[source][destination]);
}
int main() {
    int vertices, source, destination;
FILE *file;
file = fopen("inDiAdjMat2.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
fscanf(file, "%d", &vertices);
initialize(vertices);
    readGraph(file, vertices);
    floydWarshall(vertices);
printf("Shortest Path Weight Matrix:\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
}
printf("Enter the source and destination vertex: ");
scanf("%d %d", &source, &destination);
printShortestPath(source, destination);
fclose(file);
return 0;
}