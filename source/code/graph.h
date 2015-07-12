#ifndef __ABHYASI_GRAPH_H
#define __ABHYASI_GRAPH_H

#define MAX_VERTICES 100       /* Maximum vertices of vertices */

typedef struct
{
    int neighbor;               /* id of the next connected vertex */
    int weight;                 /* edge weight, if any */
    struct graph_node* next;    /* next edge in the list */
} graph_node;

typedef struct
{
    graph_node* edges[MAX_VERTICES + 1];    /* list of connected vertices */
    int degree [MAX_VERTICES + 1];          /* list with out-degree of each vertex */
    int num_vertices;                       /* number of vertices in graph */
    int num_edges;                          /* number of edges in the graph */
    bool directed;                          /* is the graph directed? */
} graph;

void initialize_graph(graph* g, bool directed);
void read_graph(graph* g, bool directed);
void insert_edge(graph* g, int vertexId, int next_label, bool directed);
void print_graph(graph* g);

#endif

