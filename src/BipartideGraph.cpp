#include "BipartideGraph.h"

#include <stdio.h>

BipartideGraph::BipartideGraph()
{
    firstLayerSize = 0;
    secondLayerSize = 0;
    numEdges = 0;
}

void BipartideGraph::printGraph()
{
    printf("Biartide Graph Layer 1:\n");
    for(int i=0; i<firstLayerSize; i++){
        printf("\tNode %d:", i);
        for(int j=0; j<(int)firstLayer[i].size(); j++){
            printf(" %d", firstLayer[i][j]);
        }
        printf("\n");
    }
    printf("Biartide Graph Layer 2:\n");
    for(int i=0; i<secondLayerSize; i++){
        printf("\tNode %d:", i);
        for(int j=0; j<(int)secondLayer[i].size(); j++){
            printf(" %d", secondLayer[i][j]);
        }
        printf("\n");
    }
}

Graph BipartideGraph::convertToFlowGraph()
{
    return Graph();
}

bool BipartideGraph::readFile(const char* path)
{
    FILE * in = fopen(path, "r");
    if (in == NULL){
        printf("Erro: não conseguiu ler o grafo bipartido no arquivo %s\n.", path);
        return false;
    }

    int edges, from, to;
    fscanf(in, "%d %d %d", &firstLayerSize, &secondLayerSize, &edges);
    allocateGraph(firstLayerSize, secondLayerSize);
    printf("fls: %d sls: %d\n", firstLayerSize, secondLayerSize);

    while(numEdges < edges){
        fscanf(in, "%d %d", &from, &to);
        addEdge(from, to);
    }

    fclose(in);

    return true;
}

void BipartideGraph::clearGraph()
{
    firstLayer.clear();
    secondLayer.clear();
    firstLayerSize = 0;
    secondLayerSize = 0;
    numEdges=0;
}

bool BipartideGraph::addEdge(int from, int to)
{
    if (from < 0 || from >= firstLayerSize || to < 0 || to >= secondLayerSize)
        return false;

    firstLayer[from].push_back(to);
    secondLayer[to].push_back(from);

    numEdges++;
    return true;
}

void BipartideGraph::allocateGraph(int firstSize, int secondSize)
{
    clearGraph();

    firstLayer.resize(firstSize);
    firstLayerSize = firstSize;
    secondLayer.resize(secondSize);
    secondLayerSize = secondSize;
}

BipartideGraph::~BipartideGraph()
{
    //dtor
}
