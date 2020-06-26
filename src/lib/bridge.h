#ifndef BRIDGE_H_
#define BRIDGE_H_

#include <stdlib.h>

#include "node.h"

typedef struct BRIDGE 
{
	char *id;
	struct NODE *northRightBridge;
	struct NODE *northLeftBridge;
	struct NODE *southRightBridge;
	struct NODE *southLeftBridge;

} BRIDGE;

BRIDGE* createBridge(char *id, NODE *northRight, NODE *northLeft, 
	NODE *southRight, NODE *southLeft)
{
	BRIDGE *bridge = malloc(sizeof(BRIDGE));
	
	bridge->id = strdup(id);
	bridge->northRightBridge = northRight;
	bridge->northLeftBridge = northLeft;	
	bridge->southRightBridge = southRight;
	bridge->southLeftBridge = southLeft;
	
	return bridge;
}

void releaseBridge(BRIDGE *bridge)
{
	if(bridge)
	{
		if(bridge->id)
		{
			free(bridge->id);
		}
		free(bridge);
	}
}

#endif