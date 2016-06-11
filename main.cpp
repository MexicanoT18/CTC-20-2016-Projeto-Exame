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

    printf("Emparelhamento m�ximo Ford Fulkerson: %d\n", ffmf.computeMaxFlow(convertedGraph));
    printf("Emparelhamento m�ximo Edmonds Karp: %d\n", ekmf.computeMaxFlow(convertedGraph));
    printf("Emparelhamento m�ximo Hungarian: %d\n", hmcbm.computeMCBM(BG));
    printf("Emparelhamento m�ximo Hopcroft Karp: %d\n", hkmcbm.computeMCBM(BG));

    return 0;
}
