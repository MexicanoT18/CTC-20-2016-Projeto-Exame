#include "DinicMaxFlow.h"
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;

DinicMaxFlow::DinicMaxFlow()
{
    INF = (1<<30);
}

int DinicMaxFlow::DFS(int u, int inFlow) {

    //Encontrou o final.
	if (u == destination)
        return inFlow;

    //Variáveis auxiliares.
	int v, outFlow;

	//Percorre os adjacentes evitando percursos por onde já se sabe que não tem fluxo.
	for (int &i = work[u]; i<(int)adjList[u].size(); i++) {
		v = adjList[u][i];

		//Verifica pode haver fluxo seguindo.
		if (residual[u][v] <= 0) continue;

		if (dist[v] == dist[u] + 1) {

            //Procura fluxo de u pra v.
			outFlow = DFS(v, min(inFlow, residual[u][v]));

			//Se achou fluxo, atualiza a aresta e segue.
			if (outFlow > 0) {
				residual[u][v] -= outFlow;
				residual[v][u] += outFlow;
				return outFlow;
			}
		}
	}
	return 0;
}

bool DinicMaxFlow::BFS()
{
    //Inicializa o vetor de distâncias
    dist.assign(numNodes, -1);
    dist[source] = 0;
    bfsQueue.push(source);
    int u, v;
    while(!bfsQueue.empty()){
        u = bfsQueue.front();
        bfsQueue.pop();
        for (int i = 0; i<(int)adjList[u].size(); i++){
            v = adjList[u][i];
            if (dist[v] < 0 && residual[u][v] > 0){
                dist[v] = dist[u] + 1;
                bfsQueue.push(v);
            }
        }
    }
    while(!bfsQueue.empty()) bfsQueue.pop();
    return dist[destination] >= 0;
}

int DinicMaxFlow::computeMaxFlow(Graph graph)
{
    time = clock();
    int result = 0, flow;

    numNodes = graph.getNumNodes();
    residual = graph.getAdjMatrix();
    adjList = graph.getAdjList();
    work.resize(numNodes);
    dist.resize(numNodes);
    source = graph.getSource();
    destination = graph.getDestination();
	if (source < 0 || destination < 0) {
		return -1;
	}

	while (BFS()) {
		work.assign(numNodes, 0);
		do{
            flow = DFS(source, INF);
            result += flow;
		} while (flow > 0);
	}
	time = clock() - time;
	return result;
}

DinicMaxFlow::~DinicMaxFlow()
{
    //dtor
}
