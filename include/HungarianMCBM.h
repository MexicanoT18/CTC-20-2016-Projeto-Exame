#ifndef HUNGARIANMCBM_H
#define HUNGARIANMCBM_H

#include "BipartideGraph.h"

class HungarianMCBM
{
    public:
        HungarianMCBM();
        //Recebe um grafo bipartido e retorna o emparelhamento máximo.
        int computeMCBM(BipartideGraph & graph);
        virtual ~HungarianMCBM();
    protected:
    private:
};

#endif // HUNGARIANMCBM_H
