#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
    public:
        Graph();
        virtual ~Graph();
        //Lê o grafo a partir de um arquivo.
        bool readFile(const char* path);
        //Gera um grafo aleatório.
        void buildRandomGraph(int nodes, int edges);
        //Limpa o grafo.
        void clearGraph();
        //Adiciona uma aresta com uma determinada capacidade.
        bool addEdge(int from, int to, int capacity);
        //Aloca espaço para um novo grafo.
        void allocateGraph(int numNodes);
        //Getters.
        vector<int> & getAdjListOfNode(int node) { return adjList[node]; }
        vector<int> & getAdjMatrixOfNode(int node) { return adjMatrix[node]; }
        vector< vector<int> > & getAdjList() { return adjList; }
        vector< vector<int> > & getAdjMatrix() { return adjMatrix; }
        int getSource() { return source; }
        int getDestination() { return destination; }
        int getNumNodes() { return numNodes; }
        int getNumEdges() { return numEdges; }
        //Setters.
        void setSource(int s) { source = (s>=0 && s<numNodes ? s:source); }
        void setDestination(int t) { destination = (t>=0 && t<numNodes ? t:destination); }
        //Printa o grafo.
        void printGraph();
    protected:
    private:
        //Lista de adjacência com índices dos vizinhos.
        vector< vector< int > > adjList;
        //Matriz de adjacência com as capacidades das arestas.
        vector< vector< int > > adjMatrix;
        //Número de nós.
        int numNodes;
        //Número de arestas.
        int numEdges;
        //Fonte de fluxo.
        int source;
        //Destino do fluxo.
        int destination;
};

#endif // GRAPH_H
