#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <limits.h>
#include <stdio.h>

#include "constants.h"

void initArray(int result[])
{
    for(int i = 0; i < VERTEXES; i++)
    {
        result[i] = INT_MAX;
    }
}

int shortestDistance(int dist[], int shortestPath[])
{

    int min = INT_MAX;
    int min_index;
    int v;
    for (v = 0; v < VERTEXES; v++) {
        if (shortestPath[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[VERTEXES][VERTEXES], int source, int paths[])
{
	int distance[VERTEXES];
	int shortestPath[VERTEXES];

    for(int i = 0; i < VERTEXES; i++)
    {
        paths[i] = 0;
    }

    for (int i = 0; i < VERTEXES; i++) 
    {
        distance[i] = INT_MAX;
        shortestPath[i] = 0;
    }

    distance[source] = 0;

    for (int i = 0; i < VERTEXES-1; i++) 
    {

        int chosenVertex = shortestDistance(distance, shortestPath);
        shortestPath[chosenVertex] = 1;

        for (int j = 0; j < VERTEXES; j++) 
        {
            if (!shortestPath[j] && graph[chosenVertex][j] && distance[chosenVertex] != INT_MAX && 
                distance[chosenVertex] + graph[chosenVertex][j] < distance[j])
            {
                distance[j] = distance[chosenVertex] + graph[chosenVertex][j];
                paths[j] = chosenVertex;
            }
        }
	}
}

int* getPath(int from, int to, int paths[], int result[], int *size)
{
    result[0] = to;
    int i = 1;

    while(paths[to] != from){
	result[i] = paths[to];
        to = paths[to];
        i++;
    }

    result[i] = from;

    int *path;
    if(i == 1) 
    {
        path = (int*) malloc (i * sizeof(int));
        *(size) = i;
    }
    else 
    {
        path = (int*) malloc ((i+1) * sizeof(int));
        *(size) = (i+1);
    }
    
    path = result;

    // Reverse the path since it was built from destination to source
    for (int low = 0, high = *(size) - 1; low < high; low++, high--)
	{
		int temp = path[low];
		path[low] = path[high];
		path[high] = temp;
	}

    return path;
}

#endif