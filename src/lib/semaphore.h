
#include <unistd.h>
#include <pthread.h>
#include "graph.h"
#include "constants.h"
#ifndef TV_ADT


#define TV_ADT

void* semaphoreWithConstantTime(void *bridge_ptr){

	BRIDGE *bridge = (BRIDGE *)bridge_ptr;
	int random;

	while(true){
		sleep(3);
		bridge->northLeftBridge->isFree = !bridge->northLeftBridge->isFree;
        bridge->southRightBridge->isFree = !bridge->southRightBridge->isFree;
        bridge->northRightBridge->isFree = !bridge->northRightBridge->isFree;
        bridge->southLeftBridge->isFree = !bridge->southLeftBridge->isFree;
	}
}

void* semaphoreWithPolices(void *bridge_ptr){

	BRIDGE *bridge = (BRIDGE *)bridge_ptr;
	int random;

	while(true){
        if(car_counter_police < 1){
            bridge->northLeftBridge->isFree = !bridge->northLeftBridge->isFree;
            bridge->southRightBridge->isFree = !bridge->southRightBridge->isFree;
            bridge->northRightBridge->isFree = !bridge->northRightBridge->isFree;
            bridge->southLeftBridge->isFree = !bridge->southLeftBridge->isFree;
            pthread_mutex_lock(&lock_police);
            car_counter_police = max_cars;
            pthread_mutex_unlock(&lock_police);
        }
        
	}
}

void semaphorePoliceThreadInit(BRIDGE *bridge){
	bridge->northLeftBridge->isSpecial=true;
	bridge->northLeftBridge->isFree = true;

    bridge->northRightBridge->isSpecial=true;
	bridge->northRightBridge->isFree = false;

	bridge->southRightBridge->isSpecial = true;
	bridge->southRightBridge->isFree = false;

    bridge->southLeftBridge->isSpecial = true;
	bridge->southLeftBridge->isFree = true;

	int rc;
	pthread_t northSemaphore_thread;
	rc = pthread_create(&northSemaphore_thread, NULL, &semaphoreWithPolices, bridge);
	if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
}

void semaphoreThreadInit(BRIDGE *bridge){
	bridge->northLeftBridge->isSpecial=true;
	bridge->northLeftBridge->isFree = true;

    bridge->northRightBridge->isSpecial=true;
	bridge->northRightBridge->isFree = false;

	bridge->southRightBridge->isSpecial = true;
	bridge->southRightBridge->isFree = false;

    bridge->southLeftBridge->isSpecial = true;
	bridge->southLeftBridge->isFree = true;

	int rc;
	pthread_t northSemaphore_thread;
	rc = pthread_create(&northSemaphore_thread, NULL, &semaphoreWithConstantTime, bridge);
	if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
}

void create_semaphores(){
 	semaphoreThreadInit(curly);   
    semaphoreThreadInit(shemp); 
    semaphorePoliceThreadInit(larry);
    semaphorePoliceThreadInit(joe); 
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
    /*cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
    cairo_rectangle(cr, 860, 301, 30, 40);
    cairo_fill (cr);*/
}





#endif