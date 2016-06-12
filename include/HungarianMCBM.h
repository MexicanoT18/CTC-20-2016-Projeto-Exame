#ifndef HUNGARIANMCBM_H
#define HUNGARIANMCBM_H

#include "BipartideGraph.h"

class HungarianMCBM
{
    public:
        HungarianMCBM();
        //Recebe um grafo bipartido e retorna o emparelhamento máximo.
        int computeMCBM(BipartideGraph & graph);
        //Printa o emparelhamento.
        void printMatching();
        virtual ~HungarianMCBM();
    protected:
    private:
        vector<int> firstLayerPair;
        vector<int> secondLayerPair;
};

#endif // HUNGARIANMCBM_H
