/* Implementacion de busqueda en profundidad */

#include <stdio.h>
#define MAX_V 20
#define MAX_DEGREE 5
#define MAX_QUEUE 30

struct graph {
    int nr_vertices;
    int nr_edges;
    int edges[MAX_V][MAX_DEGREE];
    int weights[MAX_V][MAX_DEGREE];
    int degree[MAX_V];
};

void graph_fill(struct graph *g) {
    int i;

    scanf("%d", &g->nr_vertices);
    scanf("%d", &g->nr_edges);
    for (i = 0; i < g->nr_vertices; ++i)
        g->degree[i] = 0;
    for (i = 0; i < g->nr_edges; ++i) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        g->edges[from][g->degree[from]] = to;
        g->edges[to  ][g->degree[to  ]] = from;
        g->weights[from][g->degree[from]] = weight;
        g->weights[to  ][g->degree[to  ]] = weight;
        ++g->degree[from];
        ++g->degree[to];
    }
}

/* como la funcion es recursiva, utilizaremos arreglos globales para
 * marcar los vertices, y una funcion para inicializar los arreglos */

int discovered[MAX_V];
int processed[MAX_V];

void graph_dfs_init(struct graph *g) {
    int i;
    for (i = 0; i < g->nr_vertices; ++i) {
        discovered[i] = 0;
        processed[i] = 0;
    }
}

void graph_dfs(struct graph *g, int current) {
    discovered[current] = 1;
    printf("Visitando vertice %d\n", current);

    int i;
    for (i = 0; i < g->degree[current]; ++i) {
        int neighbor = g->edges[current][i];
        if (!discovered[neighbor])
            graph_dfs(g, neighbor);
        else if (!processed[neighbor])
            /* si nos interesan solo los vertices,
             * esta parte no es necesaria */
            printf("Visitando arco %d -> %d\n", current, neighbor);
    }
    processed[current] = 1;
}


int main() {
    struct graph g;
    graph_fill(&g);

    graph_dfs_init(&g);
    graph_dfs(&g, 0);

    return 0;
}

