#ifndef INITIALIZE_H_
#define INITIALIZE_H_

#include "graph.h"
#include "vehicle.h"


#define NUM_VEHICLE 100

VEHICLE* vehicules[NUM_VEHICLE];
pthread_t threads[NUM_VEHICLE];

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