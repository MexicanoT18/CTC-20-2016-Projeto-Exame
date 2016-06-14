#include "EdmondsKarpMaxFlow.h"

EdmondsKarpMaxFlow::EdmondsKarpMaxFlow()
{
	INF = (1<<30);
}

int EdmondsKarpMaxFlow::computeMaxFlow(Graph graph)
{
	//Vetores com as arestas e o valor do fluxo residual de cada aresta
	vector< vector< int > > adjList = graph.getAdjList();
	vector< vector< int > > residual = graph.getAdjMatrix();

	//Vetor auxiliar que guarda o antecessor de um vértice ao buscar um "augmenting path"
	vector<int> parent;

	//Modifica o vetor com as arestas de modo a incluir as arestas reversas
	int numnodes = adjList.size();
	for (int i = 0; i < numnodes; i++) {
		for (int j = 0; j < adjList[i].size(); j++) {
			int u = adjList[i][j];
			if (residual[u][i] == 0) {
				adjList[u].push_back(i);
			}
		}
	}

	//Redimensiona o vetor de antecessores
	parent.clear();
	parent.resize(numnodes);

	//Seta os vértices que correspondem ao destino e a fonte
	int source = graph.getSource();
	int destination = graph.getDestination();
	if (source < 0 || destination < 0) {
		return -1;
	}

	//Caso trivial
	if (source == destination) {
		return 0;
	}

	//Valor do fluxo total e do fluxo atual
	int flow = 0;
	int currentflow;

	//Loop (Será percorrido no máximo O(VE) vezes)
	while (true) {

		parent.assign(numnodes, -1);
		parent[source] = -2;

		//Busca um "augmenting path"
		BFS(source, destination, adjList, residual, parent);

		//Retorna o fluxo do caminho encontrado ou 0 caso não encontre nenhum
		currentflow = augment(source, destination, INF, residual,parent);

		//Todos os caminhos foram encontrados então termina o LOOP
		if (currentflow == 0) {
			break;
		}

		//Atualiza fluxo total
		flow += currentflow;
	}

	return flow;
}

EdmondsKarpMaxFlow::~EdmondsKarpMaxFlow()
{
	//dtor
}

void EdmondsKarpMaxFlow::BFS(int source,int dest, vector< vector< int > > adjList,
	vector< vector< int > > residual, vector<int> &parent)
{
	int v,u;
	queue<int> vertices;

	//Variável auxiliar que termina o loop após encontrar o destino
	bool found;

	vertices.push(source);
	found = false;

	while (!vertices.empty()&&!found) {
		v = vertices.front();
		vertices.pop();

		//Para o vértice atual verifica todos os seus vizinhos que ainda não foram percorridos
		for (int i = 0; i < adjList[v].size(); i++) {
			u = adjList[v][i];
			if (residual[v][u]>0 && parent[u]==-1) {
				parent[u] = v;

				//Loop termina caso o destino seja encontrado
				if (u == dest){
					found = true;
					break;
				}
				vertices.push(u);
			}
		}
	}
}

int EdmondsKarpMaxFlow::augment(int source,int v, int minedge, vector< vector< int > > &residual,vector<int> parent)
{
	if (v == source) {
		return minedge;
	}
	if (parent[v] != -1) {
		int value = augment(source, parent[v], min(minedge, residual[parent[v]][v]),residual,parent);
		residual[parent[v]][v] -= value;
		residual[v][parent[v]] += value;
		return value;
	}
	return 0;
}
