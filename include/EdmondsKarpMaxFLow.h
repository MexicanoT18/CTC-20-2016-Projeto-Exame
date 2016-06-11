#ifndef EDMONDSKARPMAXFLOW_H
#define EDMONDSKARPMAXFLOW_H

#include "Graph.h"

class EdmondsKarpMaxFLow
{
    public:
        EdmondsKarpMaxFLow();
        //Recebe um grafo de fluxo e retorna seu fluxo máximo.
        int computeMaxFlow(Graph & graph);
        virtual ~EdmondsKarpMaxFLow();
    protected:
    private:
};

#endif // EDMONDSKARPMAXFLOW_H
