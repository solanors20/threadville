
#include <unistd.h>
#include <pthread.h>
#include "graph.h"
#include "constants.h"
#ifndef TV_ADT


#define TV_ADT

void* createLarrySemaphore( void *direction){
	int *direct = (int *)direction;
    int counter = 0;
	while(1){
	
		//printf("Cambiando los semáforos en puente %s en %i segundos \n", 'a', random);
		sleep(5);
		*direct = (*direct == 0) ? 1 : 0;
	}
}

void create_semaphores(int *direction){
 	int rc;
	pthread_t northSemaphore_thread;
	rc = pthread_create(&northSemaphore_thread, NULL, &createLarrySemaphore, direction);
	if (rc)
    {
        //printf("error, return frim pthread creation\n");            
    }
}

void draw_semaphore_by_node(NODE *node, cairo_t *cr){
    if(node->isFree)
        cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
    else
        cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
    cairo_rectangle(cr, node->x-10, node->y, TILE_SIZE, TILE_SIZE);
    cairo_fill (cr);
}

static void draw_semaphores(cairo_t *cr){
    draw_semaphore_by_node(larry->northLeftBridge, cr);
    draw_semaphore_by_node(larry->southRightBridge, cr);
    draw_semaphore_by_node(joe->northLeftBridge, cr);
    draw_semaphore_by_node(joe->southRightBridge, cr);
    draw_semaphore_by_node(curly->northLeftBridge, cr);
    draw_semaphore_by_node(curly->southRightBridge, cr);
    draw_semaphore_by_node(shemp->northLeftBridge, cr);
    draw_semaphore_by_node(shemp->southRightBridge, cr);
    draw_semaphore_by_node(moe->northLeftBridge, cr);
    draw_semaphore_by_node(moe->southRightBridge, cr);
}





#endif