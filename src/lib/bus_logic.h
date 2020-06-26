#ifndef BUS_LOGIC_H_
#define BUS_LOGIC_H_

#include <pthread.h>
#include "initialize.h"
#include "threadville_globals.h"
#include "graph.h"

void *update_car_position(void * car)
{    
    VEHICULE* tempCar=car;    
    int p=0;

    generateRoute(tempCar, tempCar->stops[p], tempCar->stops[p+1]);
    //displayDestinations(tempCar->route->destinations);
    DESTINY *destinoActual = tempCar->route->destinations;
    destinoActual=destinoActual->next;
    tempCar -> nextDestiny = tempCar -> stops[p + 1] -> name;

    bool mover=true;
    while(tempCar->run){
                   
        if(p < tempCar->stopsCounter-1){
            int i=0;

            if(tempCar->x < destinoActual->node->x && tempCar->y <= destinoActual->node->y){
                tempCar->dx=1;
                tempCar->dy=0;
            }else if(tempCar->y < destinoActual->node->y ){
                tempCar->dx=0;
                tempCar->dy=1;
            }else if(tempCar->x > destinoActual->node->x){
                tempCar->dx=-1;
                tempCar->dy=0;
            }else if(tempCar->y > destinoActual->node->y){
                tempCar->dx=0;
                tempCar->dy=-1;
            }else {
                if((destinoActual=destinoActual->next) != NULL){
			;
                }else{
                    ++p;
                    if(p < tempCar->stopsCounter-1){
                        generateRoute(tempCar, tempCar->stops[p%tempCar->stopsCounter], tempCar->stops[(p+1)%tempCar->stopsCounter]);
                        destinoActual = tempCar->route->destinations;
                        destinoActual=destinoActual->next;

                        usleep(tempCar->delay*1000000);
                        tempCar -> nextDestiny = tempCar -> stops[p + 1] -> name;
                    }else{

                        if(tempCar->type==1){
                            tempCar->run=false;
                            tempCar->x=0;
                            tempCar->x=0;
                            usleep(tempCar->delay*1000000);
                            break;
                        }else {
                            generateRoute(tempCar, tempCar->stops[p], tempCar->stops[0]);
                            destinoActual = tempCar->route->destinations;
                            destinoActual=destinoActual->next;

                            usleep(tempCar->delay*1000000);
                            tempCar -> nextDestiny = tempCar -> stops[0] -> name;
                            p=-1;
                            
                        }
                        
                    }
                }                    

            }
                
            for(i; i<contadorHilos; i++){
                
                    if(!near_car(tempCar, vehicules[i])){
                        mover=true;
                    }else{
                        mover=false;
                        break;
                    }
            } // for            
            if(mover){
		if(destinoActual->node->especial && destinoActual->node->allowTravel==false){

		}else{
			tempCar->x+=tempCar->dx;
                	tempCar->y+=tempCar->dy;
		}

            }else{

                usleep(10000);
            }
                
        }else{
            if(tempCar->type==1){
                tempCar->run=false;
                tempCar->x=0;
                tempCar->y=0;
            }else {
                p=0;
	    }            
        }                
        
       usleep(tempCar->speed*10000);
       //sleep(1);
       
    } // while run
        
} // update_car_position


void add_bus(char *id, int stopsCounter, int stops[], int speed, int color){
	char *_id = id;    
	int rc;
    
        vehicules[contadorHilos]= createBus(_id, speed, color);
	srand(time(NULL));
        vehicules[contadorHilos].stopsCounter = stopsCounter;
        vehicules[contadorHilos]->stops = (NODE*) calloc(vehicules[contadorHilos]->stopsCounter, sizeof(NODE));

	for(int i = 0; i < stopsCounter; i++){	
             vehicules[contadorHilos]->stops[i]=linkedList[stops[i]];
         }
             
        vehicules[contadorHilos]->x = linkedList[stops[0]].x;
        vehicules[contadorHilos]->y = linkedList[stops[0]].y;

        rc = pthread_create(&threads[contadorHilos], NULL, update_car_position, (void *)vehicules[contadorHilos]);
    if (rc)
    {
            printf("error, return frim pthread creation\n");
            exit(4);
    }
    contadorHilos++;
}





#endif