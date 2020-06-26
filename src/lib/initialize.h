#ifndef INITIALIZE_H_
#define INITIALIZE_H_

#include "graph.h"
#include "vehicle.h"


void initialize()
{
    initLinkedList();
    fillLinkedList();
    setNextLink();
    setWeightsMatrix();
    performDijkstra();
    createBridges();
    setGraphCoordinatesForGui();
}


#endif