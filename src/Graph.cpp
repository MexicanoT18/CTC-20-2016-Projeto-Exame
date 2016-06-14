#include "Graph.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

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
            printf(" %d(%d)", adjList[i][j], adjMatrix[i][adjList[i][j]]);
        }
        printf("\n");
    }
    printf("\tSource: %d Destination: %d\n", source, destination);
}

void Graph::buildRandomGraph(int nodes, int edges)
{
    allocateGraph(nodes);

    vector<pair<int, int> > pairs;
    for(int i = 0; i < numNodes; i++){
        for(int j = 0; j < numNodes; j++){
            pairs.push_back(make_pair(i, j));
        }
    }
    random_shuffle(pairs.begin(), pairs.end());

    int pairToChoose;
    int u, v;
    for(int i = 0; !pairs.empty() && i < edges; i++){
        pairToChoose = rand()%((int)pairs.size());
        u = pairs[pairToChoose].first;
        v = pairs[pairToChoose].second;
        pairs[pairToChoose] = pairs[(int)pairs.size()-1];
        pairs.pop_back();
        addEdge(u, v, (rand()%20) + 1);
    }

    source = rand()%numNodes;
    destination = rand()%numNodes;
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

    if (adjMatrix[from][to] == 0 && adjMatrix[to][from] == 0){
        adjList[from].push_back(to);
        adjList[to].push_back(from);
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
