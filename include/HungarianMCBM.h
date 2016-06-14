#ifndef HUNGARIANMCBM_H
#define HUNGARIANMCBM_H

#include "BipartideGraph.h"
#include <time.h>

class HungarianMCBM
{
    public:
        HungarianMCBM();
        //Recebe um grafo bipartido e retorna o emparelhamento máximo.
        int computeMCBM(BipartideGraph graph);
        //Printa o emparelhamento.
        void printMatching();
    double getTime() { return ((double)time)/(double)CLOCKS_PER_SEC; }
        virtual ~HungarianMCBM();
    protected:
    private:
        bool augment(int u, BipartideGraph & graph);
        vector<bool> visited;
        vector<int> firstLayerPair;
        vector<int> secondLayerPair;
        int firstLayerSize;
        int secondLayerSize;
        clock_t time;
};

#endif // HUNGARIANMCBM_H
