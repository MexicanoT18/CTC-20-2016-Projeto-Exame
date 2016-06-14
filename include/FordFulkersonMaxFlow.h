#ifndef FORDFULKERSONMAXFLOW_H
#define FORDFULKERSONMAXFLOW_H

#include "Graph.h"
#include <stack>

class FordFulkersonMaxFlow
{
    public:
        FordFulkersonMaxFlow();
        //Recebe um grafo de fluxo e retorna seu fluxo máximo.
        int computeMaxFlow(Graph graph);
        virtual ~FordFulkersonMaxFlow();
    protected:
    private:
        int numNodes;
        int source;
        int destination;
        stack<int> dfsStack;
};

#endif // FORDFULKERSONMAXFLOW_H
