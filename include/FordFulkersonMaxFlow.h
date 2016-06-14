#ifndef FORDFULKERSONMAXFLOW_H
#define FORDFULKERSONMAXFLOW_H

#include "Graph.h"
#include <stack>
#include <time.h>

class FordFulkersonMaxFlow
{
    public:
        FordFulkersonMaxFlow();
        //Recebe um grafo de fluxo e retorna seu fluxo máximo.
        int computeMaxFlow(Graph graph);
    double getTime() { return ((double)time)/(double)CLOCKS_PER_SEC; }
        virtual ~FordFulkersonMaxFlow();
    protected:
    private:
        int numNodes;
        int source;
        int destination;
        stack<int> dfsStack;
        clock_t time;
};

#endif // FORDFULKERSONMAXFLOW_H
