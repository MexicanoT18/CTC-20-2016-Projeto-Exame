#ifndef DINICMAXFLOW_H
#define DINICMAXFLOW_H

#include "Graph.h"
#include <queue>
#include <time.h>
using namespace std;

class DinicMaxFlow
{
    public:
        DinicMaxFlow();
        //Recebe um grafo de fluxo e retorna seu fluxo máximo.
        int computeMaxFlow(Graph graph);
    double getTime() { return ((double)time)/(double)CLOCKS_PER_SEC; }
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
        clock_t time;
};

#endif // DINICMAXFLOW_H
