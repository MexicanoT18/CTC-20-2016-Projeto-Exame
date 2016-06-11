#include "Graph.h"
#include <stdio.h>

Graph::Graph()
{
    numNodes = 0;
    numEdges = 0;
    source = -1;
    destination = -1;
}

void Graph::printGraph()
{
    printf("Graph:\n");
    for(int i=0; i<numNodes; i++){
        printf("\tNode %d:", i);
        for(int j=0; j<(int)adjList[i].size(); j++){
            printf(" %d", adjList[i][j]);
        }
        printf("\n");
    }
}

bool Graph::readFile(const char* path)
{
    FILE * in = fopen(path, "r");
    if (in == NULL){
        printf("Erro: não conseguiu ler o grafo no arquivo %s\n.", path);
        return false;
    }

    int edges, from, to, capacity;
    fscanf(in, "%d %d", &numNodes, &edges);
    allocateGraph(numNodes);

    while(numEdges < edges){
        fscanf(in, "%d %d %d", &from, &to, &capacity);
        addEdge(from, to, capacity);
    }

    fscanf(in, "%d %d", &source, &destination);

    fclose(in);

    return true;
}

void Graph::clearGraph()
{
    adjList.clear();
    adjMatrix.clear();
    numNodes=0;
    numEdges=0;
    source = -1;
    destination = -1;
}

bool Graph::addEdge(int from, int to, int capacity)
{
    if (from < 0 || from >= numNodes || to < 0 || to >= numNodes || capacity <= 0)
        return false;

    if (adjMatrix[from][to] == 0){
        adjList[from].push_back(to);
    }

    adjMatrix[from][to] += capacity;
    numEdges++;
    return true;
}

void Graph::allocateGraph(int nodes)
{
    clearGraph();

    numNodes = nodes;
    adjList.resize(numNodes);
    adjMatrix.resize(numNodes);

    for(int i=0; i<numNodes; i++){
        adjList[i].clear();

        adjMatrix[i].resize(numNodes);
        adjMatrix[i].assign(numNodes, 0);
    }
}

Graph::~Graph()
{
    //dtor
}
