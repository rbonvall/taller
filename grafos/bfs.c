/* Implementacion de busqueda en amplitud */

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


void graph_bfs(struct graph *g, int start) {
    int discovered[MAX_V];
    int processed[MAX_V];

    int i;
    for (i = 0; i < g->nr_vertices; ++i) {
        discovered[i] = 0;
        processed[i] = 0;
    }

    struct queue q;
    queue_init(&q);
    queue_push(&q, start);

    discovered[start] = 1;

    while (!queue_empty(&q)) {
        int current = queue_pop(&q);

        printf("Visitando vertice %d\n", current);

        for (i = 0; i < g->degree[current]; ++i) {
            int neighbor = g->edges[current][i];
            if (!discovered[neighbor]) {
                queue_push(&q, neighbor);
                discovered[neighbor] = 1;
            }
            if (!processed[neighbor])
                /* si nos interesan solo los vertices,
                 * esta parte no es necesaria */
                printf("Visitando arco %d -> %d\n", current, neighbor);
        }
        processed[current] = 1;
    }
}


int main() {
    struct graph g;
    graph_fill(&g);

    graph_bfs(&g, 0);
    return 0;
}

