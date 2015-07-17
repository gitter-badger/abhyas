#include <stdio.h>
#include "graph.h"

void initialize_graph(graph* g, bool directed)
{
    int i;      /* counter */

    g->num_vertices = 0;
    g->num_edges = 0;
    g->directed = directed;

    for (i = 1; i <= MAX_VERTICES; ++i) g->degree[i] = 0;
    for (i = 1; i <= MAX_VERTICES; ++i) g->edges[i] = NULL;
}

void read_graph(graph* g, bool directed)
{
    int i;              /* counter */
    int nedges;         /* number of edges */
    int vertex_id;      /* id of the vertex */
    int neighbor_id;    /* id of the neighbor */

    initialize_graph(g, directed);

    scanf("Enter <#vertices> <#edges>: %d %d", &(g->num_vertices), &nedges);

    for (i = 1; i <= nedges; ++i) 
    {
        scanf("Enter <Vertex Id> <Neighbor Id>: ", &vertex_id, &neighbor_id);
        insert_edge(g, vertex_id, neighbor_id, directed);
    }
}

void insert_edge(graph* g, int vertex_id, int neighbor_id, bool directed)
{
    graph_node* p;                  /* Temporary pointer */

    p = malloc(sizeof(graph_node))  /* allocate storage */

    p->weight = NULL;
    p->neighbor = neighbor_id;
    p->next = g->edges[vertex_id];          /* insert at the head of the list */  

    g->edges[vertex_id] = p;
    g->degree[vertex_id] ++;

    /* Note the use of recursion to add neighbors in an 
       undirected graph. TRUE ensures that recursion ends. */
    if (directed == FALSE)
        insert_edge(g, neighbor_id, vertex_id, TRUE);
    else
        g->num_edges ++;
}

void print_graph(graph* g)
{
    int i;              /* counter */
    graph_node* p;      /* temporary pointer */

    for (i = 1; i <= g->num_vertices; ++i)
    {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL) 
        {
            printf(" %d", p->neighbor);
            p = p->next;
        }
        printf("\n");
    }
}

