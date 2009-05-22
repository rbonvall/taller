#include <stdio.h>
#define MAX_V 20
#define MAX_DEGREE 5
#define MAX_QUEUE 30

struct graph {
    int nr_vertices;
    int nr_edges;
    int edges[MAX_V][MAX_DEGREE];
    int degree[MAX_V];
};

void graph_fill(struct graph *g) {
    int i;

    scanf("%d", &g->nr_vertices);
    scanf("%d", &g->nr_edges);
    for (i = 0; i < g->nr_vertices; ++i)
        g->degree[i] = 0;
    for (i = 0; i < g->nr_edges; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        g->edges[from][g->degree[from]] = to;
        ++g->degree[from];
    }
}

struct queue {
    int start, end;
    int values[MAX_QUEUE];
};

void queue_init(struct queue *q) {
    q->start = 0;
    q->end = 0;
}

int queue_empty(struct queue *q) {
    return q->start == q->end;
}

void queue_push(struct queue *q, int val) {
    q->values[q->end] = val;
    q->end = (q->end + 1) % MAX_QUEUE;
}

int queue_pop(struct queue *q) {
    int val = q->values[q->start];
    q->start = (q->start + 1) % MAX_QUEUE;
    return val;
}

void compute_in_degrees(struct graph *g, int in_degree[]) {
    int i, j;
    for (i = 0; i < g->nr_vertices; ++i)
        in_degree[i] = 0;
    for (i = 0; i < g->nr_vertices; ++i)
        for (j = 0; j < g->degree[i]; ++j)
            ++in_degree[g->edges[i][j]];
}


void topo(struct graph *g, int sorted[]) {
    int in_degree[MAX_V];
    compute_in_degrees(g, in_degree);

    int vertex;
    struct queue q; /* zero-in-degree-vertices */
    queue_init(&q);
    for (vertex = 0; vertex < g->nr_vertices; ++vertex)
        if (in_degree[vertex] == 0)
            queue_push(&q, vertex);

    int pos = 0;
    while (!queue_empty(&q)) {
        int current = queue_pop(&q);
        sorted[pos] = current;
        ++pos;

        int i;
        for (i = 0; i < g->degree[current]; ++i) {
            int neighbor = g->edges[current][i];
            --in_degree[neighbor];
            if (in_degree[neighbor] == 0)
                queue_push(&q, neighbor);
        }
    }

    if (pos != g->nr_vertices)
        fprintf(stderr, "No era DAG, solo encontramos %d vertices\n", pos);
}





int main() {
    struct graph g;
    graph_fill(&g);

    int sorted[MAX_V];
    topo(&g, sorted);

    int i;
    printf("Orden topologico: ");
    for (i = 0; i < g.nr_vertices; ++i)
        printf("%d ", sorted[i]); 
    printf("\n");

    return 0;
}

