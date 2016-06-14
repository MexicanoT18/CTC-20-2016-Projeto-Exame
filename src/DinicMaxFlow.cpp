#include "DinicMaxFlow.h"
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;

DinicMaxFlow::DinicMaxFlow()
{
    INF = (1<<30);
}

int DinicMaxFlow::augment(int v, int minEdge, vector< vector<int> > & adjMatrix, int s) {
	if (v == s) { return minEdge; }
	else if (p[v] != -1) {
		int f = augment(p[v], min(minEdge, adjMatrix[p[v]][v]), adjMatrix, s);
		adjMatrix[p[v]][v] -= f;
		adjMatrix[v][p[v]] += f;
		return f;
	}
	return 0;
}

int DinicMaxFlow::computeMaxFlow(Graph graph)
{
    vector< vector<int> > & adjMatrix = graph.getAdjMatrix();
    vector< vector<int> > & adjList = graph.getAdjList();
	int u, maxFlow = 0, v, f, s = graph.getSource(), t = graph.getDestination();
	int n=10;
	while (n--) {
		vector<int> dist(graph.getNumNodes(), INF);
		dist[s] = 0;
		queue<int> q; q.push(s);
		p.assign(graph.getNumNodes(), -1);
		while (!q.empty()) {
			u = q.front(); q.pop();
			if (u == t) break;
			for(int i = 0; i<(int)adjList[u].size(); i++){
				v = adjList[u][i];
				if (adjMatrix[u][v] > 0 && dist[v] == INF){
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		f = augment(t, INF, adjMatrix, s);
		if (f == 0) break;
		maxFlow += f;
	}
	return maxFlow;
}

DinicMaxFlow::~DinicMaxFlow()
{
    //dtor
}
