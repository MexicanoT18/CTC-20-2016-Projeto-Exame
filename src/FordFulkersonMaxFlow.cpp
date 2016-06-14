#include "FordFulkersonMaxFlow.h"
#include <iostream>

FordFulkersonMaxFlow::FordFulkersonMaxFlow()
{
    //ctor
}

int FordFulkersonMaxFlow::computeMaxFlow(Graph graph)
{
    bool exit = false;
    int maxFlow = 0;
    int n = graph.getNumNodes();
    int s = graph.getSource();
    int d = graph.getDestination();
    vector< vector<int> > adjMatrix = graph.getAdjMatrix();
    vector< vector<int> > adjList = graph.getAdjList();
    vector< vector<int> > capacity;
    vector<int> parent;
    queue<int> bfs;

    if (s < 0 || d < 0)
        return -1;

    parent.resize(n);

    capacity.resize(n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            capacity[i].push_back(adjMatrix[i][j]);

    while (!exit){
        for (int i=0; i<n; i++)
            parent[i] = -1;

        while (!bfs.empty())
            bfs.pop();

        parent[s] = s;
        bfs.push(s);

        while (!bfs.empty() && parent[d] < 0){
            int v = bfs.front();
            bfs.pop();

            for (int i=0; i<adjList[v].size(); i++){
                int viz = adjList[v][i];

                if (capacity[v][viz] > 0 && parent[viz] < 0){
                    parent[viz] = v;
                    bfs.push(viz);
                }
            }
        }

        if (parent[d] >= 0){
            int p = parent[d];
            int maxCapacity = capacity[p][d];

            while (p != s){
                maxCapacity = min(maxCapacity, capacity[parent[p]][p]);
                p = parent[p];
            }

            p = d;
            while (p != s){
                capacity[parent[p]][p] -= maxCapacity;
                capacity[p][parent[p]] += maxCapacity;
                p = parent[p];
            }

            maxFlow += maxCapacity;
        }

        else exit = true;
    }

    return maxFlow;
}

FordFulkersonMaxFlow::~FordFulkersonMaxFlow()
{
    //dtor
}
