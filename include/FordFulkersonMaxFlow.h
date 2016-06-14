#ifndef FORDFULKERSONMAXFLOW_H
#define FORDFULKERSONMAXFLOW_H

#include "Graph.h"
#include <queue>

class FordFulkersonMaxFlow
{
    public:
        FordFulkersonMaxFlow();
        //Recebe um grafo de fluxo e retorna seu fluxo máximo.
        int computeMaxFlow(Graph graph);
        virtual ~FordFulkersonMaxFlow();
    protected:
    private:
};

#endif // FORDFULKERSONMAXFLOW_H
