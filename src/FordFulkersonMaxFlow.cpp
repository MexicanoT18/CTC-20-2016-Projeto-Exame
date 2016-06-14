#include "FordFulkersonMaxFlow.h"

FordFulkersonMaxFlow::FordFulkersonMaxFlow()
{
    //ctor
}

int FordFulkersonMaxFlow::computeMaxFlow(Graph graph)
{
    int maxFlow = 0, u, v;
    numNodes = graph.getNumNodes();
    source = graph.getSource();
    destination = graph.getDestination();
    vector< vector<int> > & residual = graph.getAdjMatrix();
    vector< vector<int> > & adjList = graph.getAdjList();
    vector<int> parent;

    if (source < 0 || destination < 0){
        return -1;
    }

    parent.resize(numNodes);

    while (true){
        parent.assign(numNodes, -1);

        parent[source] = -1;
        dfsStack.push(source);

        while (!dfsStack.empty() && parent[destination] < 0){
            u = dfsStack.top();
            dfsStack.pop();

            for (int i = 0; i < (int)adjList[u].size(); i++){
                v = adjList[u][i];
                if (residual[u][v] > 0 && parent[v] < 0){
                    parent[v] = u;
                    dfsStack.push(v);
                }
            }
        }
        while(!dfsStack.empty()) dfsStack.pop();

        if (parent[destination] >= 0){
            int p = parent[destination];
            int maxCapacity = residual[p][destination];

            while (p != source){
                maxCapacity = min(maxCapacity, residual[parent[p]][p]);
                p = parent[p];
            }

            p = destination;
            while (p != source){
                residual[parent[p]][p] -= maxCapacity;
                residual[p][parent[p]] += maxCapacity;
                p = parent[p];
            }

            maxFlow += maxCapacity;
        }

        else break;
    }

    return maxFlow;
}

FordFulkersonMaxFlow::~FordFulkersonMaxFlow()
{
    //dtor
}
