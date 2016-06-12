#include "HungarianMCBM.h"
#include <stdio.h>

HungarianMCBM::HungarianMCBM()
{
    //ctor
}

int HungarianMCBM::computeMCBM(BipartideGraph & graph)
{
    return 0;
}

void HungarianMCBM::printMatching()
{
    printf("Emparelhamento por Hungarian Algorithm:\t(Primera camada, segunda camada):");
    for(int i=0; i<(int)firstLayerPair.size(); i++){
        if (firstLayerPair[i] != -1)
            printf(" (%d,%d)", i, firstLayerPair[i]);
    }
    printf("\n");
}

HungarianMCBM::~HungarianMCBM()
{
    //dtor
}
