#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    Edge* edge;
};

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool myComp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    sort(graph->edge, graph->edge + graph->E, myComp);
    subset *subsets = new subset[V+1];
    for (int v = 1; v <= V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1)
    {
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                 result[i].weight);
    return;
}

int main()
{
    int V, E;

    cin >> V >> E;

    Graph* graph = createGraph(V, E);

    int u, v, w;

    for(int i=0; i<E; i++)
    {
    	cin >> graph->edge[i].src >> graph->edge[i].dest >> graph->edge[i].weight;
    }

    KruskalMST(graph);

    return 0;
}
