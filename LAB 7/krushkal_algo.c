#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int vertices, edges;
    struct Edge edge[MAX_EDGES];
};
int parent[MAX_VERTICES];
void initialize(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        parent[i] = i;
    }
}
int find(int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find(parent[vertex]);
    }
    return parent[vertex];
}
void unionSets(int root1, int root2) {
    parent[root1] = root2;
}
int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
void kruskal(struct Graph *graph) {
initialize(graph->vertices);
qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);
int selectedEdges = 0;
int totalWeight = 0;
printf("Edge Cost\n");
for (int i = 0; i < graph->edges; i++) {
        int root1 = find(graph->edge[i].src);
        int root2 = find(graph->edge[i].dest);
if (root1 != root2) {
            printf("%d--%d %d\n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
            totalWeight += graph->edge[i].weight;
            unionSets(root1, root2);
            selectedEdges++;
if (selectedEdges == graph->vertices - 1) {
                break;
            }
        }
}
printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}
int main() {
struct Graph graph;
 printf("Enter the number of nodes and edges: ");
scanf("%d %d", &graph.vertices, &graph.edges);
printf("Enter the edges (u v w):\n");
    for (int i = 0; i < graph.edges; i++) {
        scanf("%d %d %d", &graph.edge[i].src, &graph.edge[i].dest, &graph.edge[i].weight);
}
kruskal(&graph);
return 0;
}