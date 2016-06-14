#include "Graph.h"
#include <queue>

class EdmondsKarpMaxFlow
{
public:
	EdmondsKarpMaxFlow();
	//Recebe um grafo de fluxo e retorna seu fluxo máximo.
	int computeMaxFlow(Graph graph);
	virtual ~EdmondsKarpMaxFlow();
protected:
private:
    int INF;
    int source;
    int destination;
    vector<vector<int> > residual;

	//Vetor auxiliar que guarda o antecessor de um vértice ao buscar um "augmenting path"
    vector<int> parent;
	//Busca um "augmenting path" da fonte até o destino usando BFS
	void BFS(vector< vector<int> > & adjList);

	//Percorre o "augmenting path" computando o valor do fluxo
	int augment(int v, int minedge);
};
