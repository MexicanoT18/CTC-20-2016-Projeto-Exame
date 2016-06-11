#include <stdio.h>
#include "Graph.h"
#include "BipartideGraph.h"
#include "FordFulkersonMaxFlow.h"
#include "EdmondsKarpMaxFLow.h"
#include "HungarianMCBM.h"
#include "HopcroftKarpMCBM.h"

using namespace std;

int main()
{
    Graph G;
    G.readFile("graph.txt");
    G.printGraph();

    FordFulkersonMaxFlow ffmf;
    EdmondsKarpMaxFLow ekmf;
    HungarianMCBM hmcbm;
    HopcroftKarpMCBM hkmcbm;

    printf("Fluxo Ford Fulkerson: %d\n", ffmf.computeMaxFlow(G));
    printf("Fluxo Edmonds Karp: %d\n", ekmf.computeMaxFlow(G));

    BipartideGraph BG;
    BG.readFile("bipartide_graph.txt");
    BG.printGraph();
    Graph convertedGraph = BG.convertToFlowGraph();

    printf("Emparelhamento máximo Ford Fulkerson: %d\n", ffmf.computeMaxFlow(convertedGraph));
    printf("Emparelhamento máximo Edmonds Karp: %d\n", ekmf.computeMaxFlow(convertedGraph));
    printf("Emparelhamento máximo Hungarian: %d\n", hmcbm.computeMCBM(BG));
    printf("Emparelhamento máximo Hopcroft Karp: %d\n", hkmcbm.computeMCBM(BG));

    return 0;
}
