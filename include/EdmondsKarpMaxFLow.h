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
	//Busca um "augmenting path" da fonte até o destino usando BFS
	void BFS(int source, int dest, vector< vector<int> > & adjList, vector<vector<int> > & residual, vector<int> & parent);

	//Percorre o "augmenting path" computando o valor do fluxo
	int augment(int source, int v, int minedge, vector< vector<int> > & residual, vector<int> & parent);
};
