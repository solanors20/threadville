#ifndef NODE_H_
#define NODE_H_

#include "string.h"
#include "stdlib.h"
#include <stdbool.h>

#include "constants.h"

typedef struct NODE 
{
	int id;
    char *name;
	int capacity;
	bool isSpecial;
	bool isFree;
	int paths[VERTEXES];
	int x;
    int y;
    struct NODE *nextNode1;
    struct NODE *nextNode2;
} NODE;

NODE* createNode(int id, char *name, int capacity)
{
	NODE *node = malloc(sizeof(NODE));
	node->id = id;
	node->name = strdup(name);
	node->capacity = capacity;
	node->isSpecial = false;

	return (NODE *)node;
}

void releaseNode(NODE *node)
{
	if(node)
    {
		if(node->name)
        {
            free(node->name);
        }
	    free(node);
	}
}

void setNextNodesInList (int index, int* nextNodes, NODE* linkedList)
{
    if(nextNodes[0] != -1) 
    {
        linkedList[index].nextNode1 = &linkedList [nextNodes[0]];
    }
    else
    {
        linkedList[index].nextNode1 = NULL;
    }
    if(nextNodes[1] != -1) 
    {
        linkedList[index].nextNode2 = &linkedList [nextNodes[1]];
    }
    else 
    {
        linkedList[index].nextNode2 = NULL;
    }
}

#endif