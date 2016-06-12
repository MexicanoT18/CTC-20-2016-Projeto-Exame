#ifndef BIPARTIDEGRAPH_H
#define BIPARTIDEGRAPH_H

#include "Graph.h"

class BipartideGraph
{
    public:
        BipartideGraph();
        virtual ~BipartideGraph();
        //Adiciona uma fonte e um destino de fluxo e retorna o grafo de fluxo.
        Graph convertToFlowGraph();
        //Lê o grafo a partir de um arquivo.
        bool readFile(const char* path);
        //Limpa o grafo.
        void clearGraph();
        //Adiciona uma aresta.
        bool addEdge(int from, int to);
        //Aloca um grafo novo.
        void allocateGraph(int firstSize, int secondSize);
        //Getters.
        vector< vector< int > > & getFirstLayer() { return firstLayer; }
        vector< vector< int > > & getSecondLayer() { return secondLayer; }
        int getFirstLayerSize() { return firstLayerSize; }
        int getSecondLayerSize() { return secondLayerSize; }
        //Printa o grafo.
        void printGraph();
    protected:
    private:
        //Lista de adjacência com índices da outra camada.
        vector< vector< int > > firstLayer;
        vector< vector< int > > secondLayer;
        //Tamanho da primeira camada.
        int firstLayerSize;
        //Tamanho da segunda camada.
        int secondLayerSize;
        //Número de arestas.
        int numEdges;
};

#endif // BIPARTIDEGRAPH_H
