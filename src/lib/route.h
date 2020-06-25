#ifndef ROUTE_H_
#define ROUTE_H_

#include <stdlib.h>

#include "destination.h"

typedef struct ROUTE
{
	struct DESTINATION *destination;
	struct ROUTE *next;
} ROUTE;

ROUTE* createRoute()
{
	ROUTE *route = malloc(sizeof(ROUTE));
	route->destination = createDestination();
	route->next = NULL;
	return route;
}

void releaseRoute(ROUTE *route)
{
	if(route)
    {
		free(route);
	}
}

#endif