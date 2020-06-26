#ifndef BUS_TEST
#define BUS_TEST

#include <unistd.h>
#include <pthread.h>
#include "vehicle.h"


void* moveBus( void *bus){
	VEHICLE *vehicle = (VEHICLE *)bus;
	while(1){
	
		//printf("Cambiando los semáforos en puente %s en %i segundos \n", 'a', random);
		sleep(1);
		vehicle->x = vehicle->x + 10;
	}
}

void create_bus(VEHICLE *bus){
 	int rc;
	pthread_t northSemaphore_thread;
	rc = pthread_create(&northSemaphore_thread, NULL, &moveBus, bus);
	if (rc)
    {
        //printf("error, return frim pthread creation\n");            
    }
}

static void draw_Bus(VEHICLE *bus, cairo_t *cr){
    cairo_set_source_rgb (cr, 1.0, 0.0, 1.0);
   	cairo_rectangle(cr, bus->x-10, bus->y,TILESIZE+TILESIZE*1,TILESIZE+TILESIZE*1);
    cairo_fill (cr);
    cairo_move_to(cr, bus->x-8, bus->y+12);
    cairo_set_font_size(cr, 12);
    cairo_show_text(cr, "test");
}



#endif