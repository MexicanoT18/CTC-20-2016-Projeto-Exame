#ifndef HUNGARIANMCBM_H
#define HUNGARIANMCBM_H

#include "BipartideGraph.h"

class HungarianMCBM
{
    public:
        HungarianMCBM();
        //Recebe um grafo bipartido e retorna o emparelhamento máximo.
        int computeMCBM(BipartideGraph graph);
        //Printa o emparelhamento.
        void printMatching();
        virtual ~HungarianMCBM();
    protected:
    private:
        int Aug(int l);
        vector<int> match;
        vector<int> vis;
        vector< vector< int > > adjList;
        vector<int> firstLayerPair;
        vector<int> secondLayerPair;
};

#endif // HUNGARIANMCBM_H
