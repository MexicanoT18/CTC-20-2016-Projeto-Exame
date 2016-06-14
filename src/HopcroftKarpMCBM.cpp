#include "HopcroftKarpMCBM.h"
#include <queue>
#include <stdio.h>
using namespace std;

HopcroftKarpMCBM::HopcroftKarpMCBM()
{
    INF = (1<<30);
}

int HopcroftKarpMCBM::computeMCBM(BipartideGraph graph)
{
    vector< vector< int > > & firstLayer = graph.getFirstLayer();
    firstLayerSize = graph.getFirstLayerSize();
    secondLayerSize = graph.getSecondLayerSize();

    firstLayerPair.resize(firstLayerSize+1);
    secondLayerPair.resize(secondLayerSize+1);
    dist.resize(firstLayerSize+1);

    for (int u=0; u<firstLayerSize; u++)
        firstLayerPair[u] = secondLayerSize;
    for (int v=0; v<secondLayerSize; v++)
        secondLayerPair[v] = firstLayerSize;

    int result = 0;

    while (bfs(firstLayer)){
        for (int u=0; u<firstLayerSize; u++){
            if (firstLayerPair[u]==secondLayerSize && dfs(u, firstLayer))
                result++;
        }
    }

    firstLayerPair.pop_back();
    for (int u=0; u<firstLayerSize; u++){
        if(firstLayerPair[u] == secondLayerSize)
            firstLayerPair[u] = -1;
    }
    secondLayerPair.pop_back();
    for (int v=0; v<secondLayerSize; v++){
        if(secondLayerPair[v] == firstLayerSize)
            secondLayerPair[v] = -1;
    }

    return result;
}

bool HopcroftKarpMCBM::bfs(vector< vector< int > > & firstLayer)
{
    queue<int> bfsQueue;

    for (int u=0; u<firstLayerSize; u++){
        if (firstLayerPair[u]==secondLayerSize){
            dist[u] = 0;
            bfsQueue.push(u);
        }
        else dist[u] = INF;
    }

    dist[firstLayerSize] = INF;
    int u, v;

    while (!bfsQueue.empty())
    {
        u = bfsQueue.front();
        bfsQueue.pop();

        if (dist[u] < dist[firstLayerSize]){
            for (int i=0; i<(int)firstLayer[u].size(); ++i){
                v = firstLayer[u][i];
                if (dist[secondLayerPair[v]] == INF){
                    dist[secondLayerPair[v]] = dist[u] + 1;
                    bfsQueue.push(secondLayerPair[v]);
                }
            }
        }
    }

    return (dist[firstLayerSize] != INF);
}

bool HopcroftKarpMCBM::dfs(int u, vector< vector< int > > & firstLayer)
{
    if (u == firstLayerSize) return true;

    int v;
    for (int i=0; i<(int)firstLayer[u].size(); i++){
        v = firstLayer[u][i];
        if (dist[secondLayerPair[v]] == dist[u]+1){
            if (dfs(secondLayerPair[v], firstLayer)){
                secondLayerPair[v] = u;
                firstLayerPair[u] = v;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}

void HopcroftKarpMCBM::printMatching()
{
    printf("Emparelhamento por Hopcroft Karp:\t(Primera camada, segunda camada):");
    for(int i=0; i<(int)firstLayerPair.size(); i++){
        if (firstLayerPair[i] != -1)
            printf(" (%d,%d)", i, firstLayerPair[i]);
    }
    printf("\n");
}

HopcroftKarpMCBM::~HopcroftKarpMCBM()
{
    //dtor
}
