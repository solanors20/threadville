#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "node.h"
#include "graph.h"
#include "route.h"
#include "dijkstra.h"
#include "constants.h"

typedef struct VEHICLE
{
    char *id;
    int type; 
    int delay;
    bool run;
    int x, y;
    int dx, dy;
    int speed;
    int color;
    int width, height;
    int stopsCounter;
    char *nextDestination;
    struct ROUTE *route;
    struct VEHICLE *next;
    struct NODE **stops;
} VEHICLE;



VEHICLE* createCar(char *id, int carSpeed)
{
    VEHICLE *car = malloc(sizeof(VEHICLE));
    
    car->id = strdup(id);
    car->type = CAR;
    car->delay = 3;
    car->run=true;
    car->dx=1;
    car->dy=0;
    
    if(carSpeed == 0) 
    {
        srand(time(NULL));
        car->speed=rand()%7;
    }
    else
    {
        car->speed = carSpeed;
    }
    
    car->color = car->speed;
    car->width=TILE_SIZE;
    car->height=TILE_SIZE;
    car->nextDestination = "-";
    car->next = NULL;
    car->route = NULL;
    
    return car;
}

VEHICLE* createBus(char *id, int speed, int color)
{
    VEHICLE *bus = malloc(sizeof(VEHICLE));
    bus->id = strdup(id);
    bus->type = BUS;
    bus->delay = 3;
    bus->run = true;
    bus->x = 0;
    bus->y = 0;
    bus->dx = 1;
    bus->dy = 0;
    bus->speed = speed;
    bus->color = color;
    bus->width = TILE_SIZE;
    bus->height = TILE_SIZE;
    bus->next = NULL;
    bus->route = NULL;

    return bus;
}

VEHICLE* createAmbulance(char *id)
{
    VEHICLE *ambulance = malloc(sizeof(VEHICLE));
    ambulance->id = strdup(id);
    ambulance->type = AMBULANCE;
    ambulance->delay = 3;
    ambulance->run = true;
    ambulance->x = 0;
    ambulance->y = 0;
    ambulance->dx = 1;
    ambulance->dy = 0;
    ambulance->speed = 10; // TO-DO set correct speed
    ambulance->color = 10; // TO-DO set correct color
    ambulance->width = TILE_SIZE;
    ambulance->height = TILE_SIZE;
    ambulance->next = NULL;
    ambulance->route = NULL;

    return ambulance;
}

void generateRoute(VEHICLE *vehicle, NODE *start, NODE *end)
{
    ROUTE *route = createRoute();
    route->destination = createDestination();
    DESTINATION *destination = route->destination;
    
    int size;
    
    int path[VERTEXES];
    initArray(path);
    
    int *shortestPath = getPath(start->id, end->id, start->paths, path, &size);

    for(int i = 0; i < size; i++)
    {
        destination->node = linkedList[shortestPath[i]];        
        destination->next = createDestination();
        
        if(i == (size-1))
        {
            destination->next = NULL;
        }
        else
        {
            destination = destination->next;
        }
    }

    vehicle->route = createRoute();
    vehicle->route = route;
}

void releaseVehicle(VEHICLE *vehicle)
{
    if(vehicle)
    {
        if(vehicle->id)
        {
            free(vehicle->id);
        }
        free(vehicle);
    }
}

#endif