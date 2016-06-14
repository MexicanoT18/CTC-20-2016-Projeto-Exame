#ifndef DINICMAXFLOW_H
#define DINICMAXFLOW_H

#include "Graph.h"

class DinicMaxFlow
{
    public:
        DinicMaxFlow();
        //Recebe um grafo de fluxo e retorna seu fluxo máximo.
        int computeMaxFlow(Graph graph);
        virtual ~DinicMaxFlow();
    protected:
    private:
        int augment(int v, int minEdge, vector< vector<int> > & adjMatrix, int s);
        vector<int> p;
        int INF;
};

#endif // DINICMAXFLOW_H
