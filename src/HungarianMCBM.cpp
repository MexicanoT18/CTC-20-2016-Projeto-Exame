#include "HungarianMCBM.h"
#include <stdio.h>


HungarianMCBM::HungarianMCBM()
{
    //ctor
}

int HungarianMCBM::computeMCBM(BipartideGraph graph)
{
    time = clock();
    int result = 0;
    firstLayerSize = graph.getFirstLayerSize();
    secondLayerSize = graph.getSecondLayerSize();

    firstLayerPair.resize(firstLayerSize);
    firstLayerPair.assign(firstLayerSize, -1);
    secondLayerPair.resize(secondLayerSize);
    secondLayerPair.assign(secondLayerSize, -1);

    for(int u = 0; u < firstLayerSize; u++){
        visited.assign(firstLayerSize, false);
        result += augment(u, graph);
    }

	time = clock() - time;
    return result;
}

bool HungarianMCBM::augment(int u, BipartideGraph & graph){
    if (visited[u])
        return false;
    visited[u] = true;

    int v;
    vector< vector< int > > & adjList = graph.getFirstLayer();

    for(int i = 0; i < (int)adjList[u].size(); i++){
        v = adjList[u][i];
        if(secondLayerPair[v] == -1 || augment(secondLayerPair[v], graph)){
            secondLayerPair[v] = u;
            firstLayerPair[u] = v;
            return true;
        }
    }
    return false;
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
