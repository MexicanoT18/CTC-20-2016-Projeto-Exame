#include "Graph.h"
#include <queue>

class EdmondsKarpMaxFlow
{
public:
	EdmondsKarpMaxFlow();
	//Recebe um grafo de fluxo e retorna seu fluxo m�ximo.
	int computeMaxFlow(Graph graph);
	virtual ~EdmondsKarpMaxFlow();
protected:
private:
    int INF;
    int source;
    int destination;
    vector<vector<int> > residual;

	//Vetor auxiliar que guarda o antecessor de um v�rtice ao buscar um "augmenting path"
    vector<int> parent;
	//Busca um "augmenting path" da fonte at� o destino usando BFS
	void BFS(vector< vector<int> > & adjList);

	//Percorre o "augmenting path" computando o valor do fluxo
	int augment(int v, int minedge);
};
