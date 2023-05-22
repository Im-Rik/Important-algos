#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

// struct for the edges of the graph
struct Edge
{
    int u;
    int v;
    int w;
};

// Graph - it consists of edges
struct Graph
{
    int V;
    int E;
    struct Edge *edge;
};

void bellmanford(struct Graph *g, int source);
void display(int arr[], int size);

int main(void)
{
    // create graph
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->V = 5;
    g->E = 7;

    g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));

    g->edge[0].u = 0;
    g->edge[0].v = 1;
    g->edge[0].w = 6;

    g->edge[1].u = 0;
    g->edge[1].v = 2;
    g->edge[1].w = 5;

    g->edge[2].u = 2;
    g->edge[2].v = 1;
    g->edge[2].w = -2;

    g->edge[3].u = 1;
    g->edge[3].v = 3;
    g->edge[3].w = -1;

    g->edge[4].u = 2;
    g->edge[4].v = 3;
    g->edge[4].w = 4;

    g->edge[5].u = 3;
    g->edge[5].v = 4;
    g->edge[5].w = 3;

    g->edge[6].u = 2;
    g->edge[6].v = 4;
    g->edge[6].w = 3;

    bellmanford(g, 0);
    return 0;
}

void bellmanford(struct Graph *g, int source)
{
    int i, j, u, v, w;
    int tV = g->V;
    int tE = g->E;
    int d[tV];
    int p[tV];

    for (i = 0; i < tV; i++)
    {
        d[i] = INFINITY;
        p[i] = 0;
    }

    d[source] = 0;

    for (i = 0; i < tV - 1; i++)
    {
        for (j = 0; j < tE; j++)
        {
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;
            int tempdist = d[u] + w;
            if (d[u] != INFINITY && d[v] > tempdist)
            {
                d[v] = tempdist;
                p[v] = u;
            }
        }
    }
    printf("Distance array: ");
    display(d, tV);
    printf("Predecessor array: ");
    display(p, tV);
}

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}