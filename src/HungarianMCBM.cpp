#include "HungarianMCBM.h"
#include <stdio.h>


HungarianMCBM::HungarianMCBM()
{
    //ctor
}

int HungarianMCBM::computeMCBM(BipartideGraph graph)
{
    int MCBM = 0;
    int n = graph.getFirstLayerSize();

    adjList = graph.getFirstLayer();
    match.assign(graph.getFirstLayerSize()+graph.getSecondLayerSize(), -1);
    for(int l = 0; l < n; l++){
        vis.assign(n ,0);
        MCBM += Aug(l);
    }

    return MCBM;
}

int HungarianMCBM::Aug(int l){
    if (vis[l])
        return 0;
    vis[l] = 1;
    for(int j = 0; j < (int)adjList[l].size(); j++){
        int r = adjList[l][j];
        if(match[r] == -1 || Aug(match[r])){
            match[r] = 1;
            return 1;
        }
    }
    return 0;
}
void HungarianMCBM::printMatching()
{
    printf("Emparelhamento por Hungarian Algorithm:\t(Primera camada, segunda camada):");
    for(int i=0; i<(int)firstLayerPair.size(); i++){
        if (firstLayerPair[i] != -1)
            printf(" (%d,%d)", i, firstLayerPair[i]);
    }
    printf("\n");
}

HungarianMCBM::~HungarianMCBM()
{
    //dtor
}
