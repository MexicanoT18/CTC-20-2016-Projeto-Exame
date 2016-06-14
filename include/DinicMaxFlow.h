#ifndef DINICMAXFLOW_H
#define DINICMAXFLOW_H

#include "Graph.h"
#include <queue>
using namespace std;

class DinicMaxFlow
{
    public:
        DinicMaxFlow();
        //Recebe um grafo de fluxo e retorna seu fluxo máximo.
        int computeMaxFlow(Graph graph);
        virtual ~DinicMaxFlow();
    protected:
    private:
        int DFS(int u, int inFlow);
        bool BFS();
        vector< vector<int> > residual;
        vector< vector<int> > adjList;
        vector<int> dist;
        vector<int> work;
        queue<int> bfsQueue;
        int INF;
        int source;
        int destination;
        int numNodes;
};

#endif // DINICMAXFLOW_H
