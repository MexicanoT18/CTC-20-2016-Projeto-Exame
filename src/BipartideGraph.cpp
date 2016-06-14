#include "BipartideGraph.h"
#include <time.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

BipartideGraph::BipartideGraph()
{
    firstLayerSize = 0;
    secondLayerSize = 0;
    numEdges = 0;
}

void BipartideGraph::printGraph()
{
    printf("Bipartide Graph Layer 1:\n");
    for(int i=0; i<firstLayerSize; i++){
        printf("\tNode %d:", i);
        for(int j=0; j<(int)firstLayer[i].size(); j++){
            printf(" %d", firstLayer[i][j]);
        }
        printf("\n");
    }
    printf("Bipartide Graph Layer 2:\n");
    for(int i=0; i<secondLayerSize; i++){
        printf("\tNode %d:", i);
        for(int j=0; j<(int)secondLayer[i].size(); j++){
            printf(" %d", secondLayer[i][j]);
        }
        printf("\n");
    }
}

void BipartideGraph::buildRandomGraph(int firstSize, int secondSize, int edges)
{
    allocateGraph(firstSize, secondSize);

    vector<pair<int, int> > pairs;
    for(int i = 0; i < firstSize; i++){
        for(int j = 0; j < secondSize; j++){
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
        addEdge(u, v);
    }
}

Graph BipartideGraph::convertToFlowGraph()
{
    Graph graph;

    graph.allocateGraph(firstLayerSize+secondLayerSize+2);

    //Setar Source e Destination
    int s = firstLayerSize+secondLayerSize;
    int t = s+1;
    graph.setSource(s);
    graph.setDestination(t);

    //Cria arestas de S para a primeira camada
    for (int i=0; i<firstLayerSize; i++){
        graph.addEdge(s, i, 1);
    }

    //Cria arestas da primeira para a segunda camada
    vector< vector< int > > & adjlist = getFirstLayer();
    for (int i = 0; i < firstLayerSize; i++){
        for (int j = 0; j < (int)adjlist[i].size(); j++){
            graph.addEdge(i,adjlist[i][j]+firstLayerSize,1);
        }
    }

    //Cria arestas da segunda camada para T
    for (int i=0; i<secondLayerSize; i++){
        graph.addEdge(firstLayerSize+i, t, 1);
    }

    return graph;
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
