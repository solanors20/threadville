
#include <unistd.h>
#include <pthread.h>

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

static void draw_LarrySemaphore(int direction, cairo_t *cr){
    if(direction)
        cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
    else
        cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
        

    cairo_rectangle(cr, 10, 5,TILESIZE,TILESIZE);
    cairo_fill (cr);
}



#endif