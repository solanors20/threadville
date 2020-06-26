#ifndef DESTINATION_H_
#define DESTINATION_H_

#include <stdlib.h>

#include "node.h"

typedef struct DESTINATION
{
	struct NODE node;
	struct DESTINATION *next;
} DESTINATION;

DESTINATION* createDestination()
{
	DESTINATION *destination = malloc(sizeof(DESTINATION));
	//destination->node = NULL;
	destination->next = NULL;
	return destination;
}

void releaseDestination(DESTINATION *destination)
{
	if(destination)
	{
		free(destination);
	}
}

#endif