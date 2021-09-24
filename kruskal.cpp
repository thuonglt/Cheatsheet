#include<bits/stdc++.h>
#include<subset.cpp>

//O(ElogE) or O(ElogV)

class Edge
{
    public:
    int src, dest, weight;
};

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

vector<*Edge> edges;

// The main function to construct MST using Kruskal's algorithm

//V = number of vertice
vector<Edge> KruskalMST(vector<*Edge> edges, int V)
{
    Edge *current = edges[0];
    int E = edges.size();
    vector<Edge> result(V); // Tnis will store the resultant MST
    int e = 1; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing
    // order of their weight. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges
    sort(edges.begin(), edges.end(), myComp);

    // Allocate memory for creating V ssubsets
    vector<subset> subsets(V);

    // Number of edges to be taken is equal to V-1
    while (e < V && i < E)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        Edge next_edge = edges[i++];

        int x = find(next_edge.src, subsets);
        int y = find(next_edge.dest, subsets);

        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            join(x, y, subsets);
        }
        // Else discard the next_edge
    }

    return result;
}
