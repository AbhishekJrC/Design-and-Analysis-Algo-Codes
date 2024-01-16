#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int parent[MAX_VERTICES];
int visited[MAX_VERTICES];
void initialize(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }
}
void readGraph(FILE *file, int vertices) {
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
}
int getMinDistanceVertex(int vertices) {
    int minDistance = INT_MAX;
    int minVertex = -1;
for (int v = 1; v <= vertices; v++) {
        if (!visited[v] && distance[v] < minDistance) {
            minDistance = distance[v];
            minVertex = v;
        }
}
return minVertex;
}
void dijkstra(int vertices, int source) {
    initialize(vertices);
distance[source] = 0;
for (int i = 1; i <= vertices - 1; i++) {
        int currentVertex = getMinDistanceVertex(vertices);
        visited[currentVertex] = 1;
for (int v = 1; v <= vertices; v++) {
            if (!visited[v] && graph[currentVertex][v] && distance[currentVertex] != INT_MAX &&
                distance[currentVertex] + graph[currentVertex][v] < distance[v]) {
                distance[v] = distance[currentVertex] + graph[currentVertex][v];
                parent[v] = currentVertex;
            }
        }
    }
}
void printPath(int source, int destination) {
    if (destination == source) {
        printf("%d", source);
        return;
}
printPath(source, parent[destination]);
    printf("->%d", destination);
}
int main() {
    int vertices, source;
FILE *file;
file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
fscanf(file, "%d", &vertices);
printf("Enter the Source Vertex: ");
    scanf("%d", &source);
dijkstra(vertices, source);
printf("\nSource Destination Cost Path\n");
    for (int i = 1; i <= vertices; i++) {
        printf("%d\t%d\t%d\t", source, i, distance[i]);
        if (i != source) {
            printPath(source, i);
        } else {
            printf("-");
        }
        printf("\n");
}
fclose(file);
return 0;
}