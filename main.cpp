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
    BipartideGraph BG;

    FordFulkersonMaxFlow ffmf;
    EdmondsKarpMaxFlow ekmf;
    DinicMaxFlow dmf;
    HungarianMCBM hmcbm;
    HopcroftKarpMCBM hkmcbm;

    FILE* out = fopen("tempo.txt", "w");
    clock_t time;
    int numIter = 10;

    for(int n=90; n<200; n++){
        G.buildRandomGraph(n, n*(n-1)/2);
        //BG.buildRandomGraph(n, n, n*3);
        printf("%d\n", n);
        fprintf(out, "%d, ", n);

        time = clock();
        for(int i=0; i<numIter; i++)
            ffmf.computeMaxFlow(G);
        time = clock() - time;
        fprintf(out, " %f, ", ((double)time)/(CLOCKS_PER_SEC*numIter));
        time = clock();
        for(int i=0; i<numIter; i++)
            ekmf.computeMaxFlow(G);
        time = clock() - time;
        fprintf(out, " %f, ", ((double)time)/(CLOCKS_PER_SEC*numIter));
        time = clock();
        for(int i=0; i<numIter; i++)
            dmf.computeMaxFlow(G);
        time = clock() - time;
        fprintf(out, " %f;\n", ((double)time)/(CLOCKS_PER_SEC*numIter));

      //  fprintf(out, "%d %f %f %f\n", n, ffmf.getTime(), ekmf.getTime(), dmf.getTime());

       /* G = BG.convertToFlowGraph();

        printf("Emparelhamento máximo Ford Fulkerson: %d\n", ffmf.computeMaxFlow(G));
        printf("Emparelhamento máximo Edmonds Karp: %d\n", ekmf.computeMaxFlow(G));
        printf("Emparelhamento máximo Dinic: %d\n", dmf.computeMaxFlow(G));
        printf("Emparelhamento máximo Hungarian: %d\n", hmcbm.computeMCBM(BG));
        hmcbm.printMatching();
        printf("Emparelhamento máximo Hopcroft Karp: %d\n", hkmcbm.computeMCBM(BG));
        hkmcbm.printMatching();*/
    }

    fclose(out);

    return 0;
}
