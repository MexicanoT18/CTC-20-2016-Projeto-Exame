#ifndef HOPCROFTKARPMCBM_H
#define HOPCROFTKARPMCBM_H

#include "BipartideGraph.h"

class HopcroftKarpMCBM
{
    public:
        HopcroftKarpMCBM();
        //Recebe um grafo e retorna o fluxo máximo.
        int computeMCBM(BipartideGraph & graph);
        virtual ~HopcroftKarpMCBM();
    protected:
    private:
};

#endif // HOPCROFTKARPMCBM_H
