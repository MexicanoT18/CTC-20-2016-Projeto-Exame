#ifndef HOPCROFTKARPMCBM_H
#define HOPCROFTKARPMCBM_H

#include "BipartideGraph.h"
#include <time.h>

class HopcroftKarpMCBM
{
    public:
        HopcroftKarpMCBM();
        //Recebe um grafo e retorna o fluxo máximo.
        int computeMCBM(BipartideGraph graph);
        //Printa o emparelhamento.
        void printMatching();
    double getTime() { return ((double)time)/(double)CLOCKS_PER_SEC; }
        virtual ~HopcroftKarpMCBM();
    protected:
    private:
        vector<int> firstLayerPair;
        vector<int> secondLayerPair;
        vector<int> dist;
        bool bfs(vector< vector< int > > & firstLayer);
        bool dfs(int u, vector< vector< int > > & firstLayer);
        int firstLayerSize;
        int secondLayerSize;
        int INF;
        clock_t time;
};

#endif // HOPCROFTKARPMCBM_H
