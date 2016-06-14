#include <stdio.h>
#include "Graph.h"
#include "BipartideGraph.h"
#include "FordFulkersonMaxFlow.h"
#include "EdmondsKarpMaxFLow.h"
#include "HungarianMCBM.h"
#include "HopcroftKarpMCBM.h"
#include "DinicMaxFlow.h"

using namespace std;

int main()
{
    Graph G;

    FordFulkersonMaxFlow ffmf;
    EdmondsKarpMaxFlow ekmf;
    DinicMaxFlow dmf;
    HungarianMCBM hmcbm;
    HopcroftKarpMCBM hkmcbm;

    while(getchar() != 'c'){
        G.buildRandomGraph(10, 25);
        G.printGraph();

        printf("Fluxo Ford Fulkerson: %d\n", ffmf.computeMaxFlow(G));
        printf("Fluxo Edmonds Karp: %d\n", ekmf.computeMaxFlow(G));
        printf("Fluxo Dinic: %d\n", dmf.computeMaxFlow(G));
    }

    BipartideGraph BG;
    BG.readFile("bipartide_graph_3.txt");
    BG.printGraph();
    Graph convertedGraph = BG.convertToFlowGraph();

    printf("Emparelhamento máximo Ford Fulkerson: %d\n", ffmf.computeMaxFlow(convertedGraph));
    printf("Emparelhamento máximo Edmonds Karp: %d\n", ekmf.computeMaxFlow(convertedGraph));
    printf("Emparelhamento máximo Dinic: %d\n", dmf.computeMaxFlow(convertedGraph));
    printf("Emparelhamento máximo Hungarian: %d\n", hmcbm.computeMCBM(BG));
    hmcbm.printMatching();
    printf("Emparelhamento máximo Hopcroft Karp: %d\n", hkmcbm.computeMCBM(BG));
    hkmcbm.printMatching();

    return 0;
}
