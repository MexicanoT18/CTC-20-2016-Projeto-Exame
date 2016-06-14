#include "Graph.h"
#include <queue>
#include <time.h>

class EdmondsKarpMaxFlow
{
public:
	EdmondsKarpMaxFlow();
	//Recebe um grafo de fluxo e retorna seu fluxo máximo.
	int computeMaxFlow(Graph graph);
    double getTime() { return ((double)time)/(double)CLOCKS_PER_SEC; }
	virtual ~EdmondsKarpMaxFlow();
protected:
private:
    int INF;
    int source;
    int destination;
    clock_t time;
    vector<vector<int> > residual;

	//Vetor auxiliar que guarda o antecessor de um vértice ao buscar um "augmenting path"
    vector<int> parent;
	//Busca um "augmenting path" da fonte até o destino usando BFS
	void BFS(vector< vector<int> > & adjList);
	queue<int> bfsQueue;

	//Percorre o "augmenting path" computando o valor do fluxo
	int augment(int v, int minedge);
};
