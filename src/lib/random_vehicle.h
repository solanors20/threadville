#include <time.h>
#include <pthread.h>
#include "graph.h"
#include "map.h"
#include "vehicle.h"

void* create_car(pthread_t thread) {

    srand(time(NULL));
    int color = rand() % 6; // There are six types of color
    int speed;
    int destination = rand() % 179; //Number of destinies
    char str_id[10];
    sprintf(str_id, "%d", thread);


    VEHICLE* v;

    switch (color) {
        case 1:
            speed = 1;
            v = createCar(*str_id, speed);
            generateRoute(v, linkedList[74], linkedList[destination]); //if the car is red
            break;
        case 2:
            speed = 2;
            v = createCar(*str_id, speed);
            generateRoute(v, linkedList[74], linkedList[3]); //if the car is blue
            break;
        case 3:
            speed = 3;
            v = createCar(*str_id, speed);
            generateRoute(v, linkedList[74], linkedList[destination]); //if the car is green
            break;
        case 4:
            speed = 4;
            v = createCar(*str_id, speed);
            generateRoute(v, linkedList[74], linkedList[destination]); //if the car is black
            break;
        case 5:
            speed = 5;
            v = createCar(*str_id, speed);
            generateRoute(v, linkedList[74], linkedList[destination]); //if the car is white
            break;
        case 6:
            speed = 6;
            v = createCar(*str_id, speed);
            generateRoute(v, linkedList[74], linkedList[destination]); //if the car is yellow
            break;
        default:
            g_print("something went wrong\n");
    }
    g_print("color: %d\n", color);
    g_print("speed: %d \n", speed);
    g_print("number of destinations: %s \n", str_id);
}

