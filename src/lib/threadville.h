#ifndef THREADVILLE_H_
#define THREADVILLE_H_

#include <stdlib.h>

#include "node.h"

typedef struct Threadville 
{
    NODE node;
} THREADVILLE;

THREADVILLE* createThreadville()
{
    THREADVILLE *threadville = malloc(sizeof(THREADVILLE));
    return threadville;
}

void releaseThreadville(THREADVILLE *threadville)
{
    if(threadville)
    {
        free(threadville);
    }
}

#endif