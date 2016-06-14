#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
    public:
        Graph();
        virtual ~Graph();
        //L� o grafo a partir de um arquivo.
        bool readFile(const char* path);
        //Gera um grafo aleat�rio.
        void buildRandomGraph(int nodes, int edges);
        //Limpa o grafo.
        void clearGraph();
        //Adiciona uma aresta com uma determinada capacidade.
        bool addEdge(int from, int to, int capacity);
        //Aloca espa�o para um novo grafo.
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
        //Lista de adjac�ncia com �ndices dos vizinhos.
        vector< vector< int > > adjList;
        //Matriz de adjac�ncia com as capacidades das arestas.
        vector< vector< int > > adjMatrix;
        //N�mero de n�s.
        int numNodes;
        //N�mero de arestas.
        int numEdges;
        //Fonte de fluxo.
        int source;
        //Destino do fluxo.
        int destination;
};

#endif // GRAPH_H
