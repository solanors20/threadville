#ifndef VEHICLE_POSITION_LOGIC_H_
#define VEHICLE_POSITION_LOGIC_H_

#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include "initialize.h"
#include "threadville_globals.h"
#include "graph.h"
#include "vehicle.h"

bool are_two_vehicles_near(VEHICLE *car1, VEHICLE *car2)
{
  int are_equal = memcmp(&car1, &car2, sizeof(car1));
  if (are_equal == 0)
    return false;

  if (
      (car1->x + (car1->width + 5) * fabs(car1->dx) >= car2->x && car1->x < car2->x && (car1->y == car2->y) && car1->dx == 1) ||
      (car1->x - (car1->width + 5) * fabs(car1->dx) < car2->x && car1->x > car2->x && (car1->y == car2->y) && car1->dx == -1) ||
      ((car1->y + (car1->height + 5) * fabs(car1->dy) >= car2->y && car1->y < car2->y) && (car1->x == car2->x) && car1->dy == 1) ||
      ((car1->y - (car1->height + 5) * fabs(car1->dy) < car2->y && car1->y > car2->y) && (car1->x == car2->x) && car1->dy == -1))
  {
    return true;
  }

  return false;
}

bool is_vehicle_in_red_light(VEHICLE *car1, NODE *semaphore)
{

  if (
      (car1->x + (car1->width + 5) * fabs(car1->dx) >= semaphore->x && car1->x < semaphore->x && (car1->y == semaphore->y) && car1->dx == 1) ||
      (car1->x - (car1->width + 5) * fabs(car1->dx) < semaphore->x && car1->x > semaphore->x && (car1->y == semaphore->y) && car1->dx == -1) ||
      ((car1->y + (car1->height + 5) * fabs(car1->dy) >= semaphore->y && car1->y < semaphore->y) && (car1->x == semaphore->x) && car1->dy == 1) ||
      ((car1->y - (car1->height + 5) * fabs(car1->dy) < semaphore->y && car1->y > semaphore->y) && (car1->x == semaphore->x) && car1->dy == -1))
  {
    return true;
  }

  return false;
}

void *update_car_position(void *car)
{
  VEHICLE *tempCar = (VEHICLE *)car;
  int stopIndex = 0;

  generateRoute(tempCar, tempCar->stops[stopIndex], tempCar->stops[stopIndex + 1]);

  DESTINATION *currentDestination = tempCar->route->destination;
  currentDestination = currentDestination->next;
  tempCar->nextDestination = tempCar->stops[stopIndex + 1]->name;

  bool canMove = true;
  while (tempCar->run)
  {

    if (stopIndex < tempCar->stopsCounter - 1)
    {
      int i = 0;

      if((larry->northLeftBridge->isFree
      && tempCar->x == 180
      && tempCar->y > 298 && tempCar->y < 300) ||
      (larry->southRightBridge->isFree
      && tempCar->x == 200
      && tempCar->y < 360 && tempCar->y > 358)){
        pthread_mutex_lock(&lock_police);
        car_counter_police--;
        pthread_mutex_unlock(&lock_police);
      }

      if((joe->southRightBridge->isFree
      && tempCar->x == 840
      && tempCar->y < 360 && tempCar->y > 358) ||
      (joe->northLeftBridge->isFree
      && tempCar->x == 830
      && tempCar->y > 298 && tempCar->y < 300)){
        pthread_mutex_lock(&lock_police);
        printf("habia %i %i", tempCar->x , tempCar->y);
        car_counter_police--;
        pthread_mutex_unlock(&lock_police);
      }

      if((!curly->northLeftBridge->isFree
      && tempCar->x == 340 
      && tempCar->y > 298 && tempCar->y < 300) ||
      (!curly->southRightBridge->isFree
      && tempCar->x == 360
      && tempCar->y < 360 && tempCar->y > 358) ||
      (!shemp->southRightBridge->isFree
      && tempCar->x == 680 
      && tempCar->y < 360 && tempCar->y > 358) ||
        (!shemp->northLeftBridge->isFree
      && tempCar->x == 660 
      && tempCar->y > 298 && tempCar->y < 300) ||
      (!joe->southRightBridge->isFree
      && tempCar->x == 840
      && tempCar->y < 360 && tempCar->y > 358) ||
      (!joe->northLeftBridge->isFree
      && tempCar->x == 830
      && tempCar->y > 298 && tempCar->y < 300) ||
      (!larry->northLeftBridge->isFree
      && tempCar->x == 180
      && tempCar->y > 298 && tempCar->y < 300) ||
      (!larry->southRightBridge->isFree
      && tempCar->x == 200
      && tempCar->y < 360 && tempCar->y > 358)){
        tempCar->dx = 0;
        tempCar->dy = 0;
      }
      else if (tempCar->x < currentDestination->node.x && tempCar->y <= currentDestination->node.y)
      {
        tempCar->dx = 1;
        tempCar->dy = 0;
      }
      else if (tempCar->y < currentDestination->node.y)
      {
        tempCar->dx = 0;
        tempCar->dy = 1;
      }
      else if (tempCar->x > currentDestination->node.x)
      {
        tempCar->dx = -1;
        tempCar->dy = 0;
      }
      else if (tempCar->y > currentDestination->node.y)
      {
        tempCar->dx = 0;
        tempCar->dy = -1;
      }
      else
      {
        if ((currentDestination = currentDestination->next) != NULL)
        {
          ;
        }
        else
        {
          ++stopIndex;
          if (stopIndex < tempCar->stopsCounter - 1)
          {
            generateRoute(tempCar, tempCar->stops[stopIndex % tempCar->stopsCounter], tempCar->stops[(stopIndex + 1) % tempCar->stopsCounter]);
            currentDestination = tempCar->route->destination;
            currentDestination = currentDestination->next;

            usleep(tempCar->delay * 1000000);
            tempCar->nextDestination = tempCar->stops[stopIndex + 1]->name;
          }
          else
          {

            if (tempCar->type == 1)
            {
              tempCar->run = false;
              tempCar->x = 0;
              tempCar->x = 0;
              usleep(tempCar->delay * 1000000);
              break;
            }
            else
            {
              generateRoute(tempCar, tempCar->stops[stopIndex], tempCar->stops[0]);
              currentDestination = tempCar->route->destination;
              currentDestination = currentDestination->next;

              usleep(tempCar->delay * 1000000);
              tempCar->nextDestination = tempCar->stops[0]->name;
              stopIndex = -1;
            }
          }
        }
      }

      for (i; i < threadCounter; i++)
      {

        if (!are_two_vehicles_near(tempCar, vehicules[i]))
        {
          canMove = true;
        }
        else
        {
          canMove = false;
          break;
        }
      }

      if (canMove)
      {
        if (currentDestination->node.isSpecial && currentDestination->node.isFree == false)
        {
        }
        else
        {
          tempCar->x += tempCar->dx;
          tempCar->y += tempCar->dy;
        }
      }
      else
      {

        usleep(10000);
      }
    }
    else
    {
      if (tempCar->type == 1)
      {
        tempCar->run = false;
        tempCar->x = 0;
        tempCar->y = 0;
      }
      else
      {
        stopIndex = 0;
      }
    }

    usleep(tempCar->speed * 10000);
  }
}
void *update_ambulance_position(void *car)
{
    VEHICLE *tempCar = (VEHICLE *)car;
    int stopIndex = 0;

    generateRoute(tempCar, tempCar->stops[stopIndex], tempCar->stops[stopIndex + 1]);

    DESTINATION *currentDestination = tempCar->route->destination;
    currentDestination = currentDestination->next;
    tempCar->nextDestination = tempCar->stops[stopIndex + 1]->name;

    bool canMove = true;
    while (tempCar->run)
    {

        if (stopIndex < tempCar->stopsCounter - 1)
        {
            int i = 0;
            if((!curly->northLeftBridge->isFree
                && tempCar->x < 390 && tempCar->x > 380
                && tempCar->y == 300) ||
               (!curly->southRightBridge->isFree
                && tempCar->x > 330 && tempCar->x < 340
                && tempCar->y == 360) ||
               (!shemp->southRightBridge->isFree
                && tempCar->x > 650 && tempCar->x < 660
                && tempCar->y == 360) ||
               (!shemp->northLeftBridge->isFree
                && tempCar->x < 710 && tempCar->x > 690
                && tempCar->y == 300)){
                tempCar->dx = 0;
                tempCar->dy = 0;
            }
            else if (tempCar->x < currentDestination->node.x && tempCar->y <= currentDestination->node.y)
            {
                tempCar->dx = 1;
                tempCar->dy = 0;
            }
            else if (tempCar->y < currentDestination->node.y)
            {
                tempCar->dx = 0;
                tempCar->dy = 1;
            }
            else if (tempCar->x > currentDestination->node.x)
            {
                tempCar->dx = -1;
                tempCar->dy = 0;
            }
            else if (tempCar->y > currentDestination->node.y)
            {
                tempCar->dx = 0;
                tempCar->dy = -1;
            }
            else
            {
                if ((currentDestination = currentDestination->next) != NULL)
                {
                    ;
                }
                else
                {
                    ++stopIndex;
                    if (stopIndex < tempCar->stopsCounter - 1)
                    {
                        generateRoute(tempCar, tempCar->stops[stopIndex % tempCar->stopsCounter], tempCar->stops[(stopIndex + 1) % tempCar->stopsCounter]);
                        currentDestination = tempCar->route->destination;
                        currentDestination = currentDestination->next;

                        usleep(tempCar->delay * 3000000);
                        tempCar->nextDestination = tempCar->stops[stopIndex + 1]->name;
                    }
                    else
                    {

                        if (tempCar->type == 1)
                        {
                            tempCar->run = false;
                            tempCar->x = 0;
                            tempCar->x = 0;
                            usleep(tempCar->delay * 3000000);
                            break;
                        }
                        else
                        {
                            generateRoute(tempCar, tempCar->stops[stopIndex], tempCar->stops[0]);
                            currentDestination = tempCar->route->destination;
                            currentDestination = currentDestination->next;

                            usleep(tempCar->delay * 3000000);
                            tempCar->nextDestination = tempCar->stops[0]->name;
                            stopIndex = -1;
                        }
                    }
                }
            }

            for (i; i < threadCounter; i++)
            {

                if (!are_two_vehicles_near(tempCar, vehicules[i]))
                {
                    canMove = true;
                }
                else
                {
                    canMove = false;
                    break;
                }
            }

            if (canMove)
            {
                if (currentDestination->node.isSpecial && currentDestination->node.isFree == false)
                {
                }
                else
                {
                    tempCar->x += tempCar->dx;
                    tempCar->y += tempCar->dy;
                }
            }
            else
            {

                usleep(9000);
            }
        }
        else
        {
            if (tempCar->type == 1)
            {
                tempCar->run = false;
                tempCar->x = 0;
                tempCar->y = 0;
            }
            else
            {
                stopIndex = 0;
            }
        }

        usleep(tempCar->speed * 9000);
    }
}
void add_vehicule()
{

  int rc;
  vehicules[threadCounter] = createCar("v", 0);

  srand(time(NULL));
  vehicules[threadCounter]->stopsCounter = (rand() % 4 + 1) + 2;
  vehicules[threadCounter]->stops = (NODE **)calloc(vehicules[threadCounter]->stopsCounter, sizeof(NODE *));
  vehicules[threadCounter]->stops[0] = &linkedList[72];
  int i;
  for (i = 1; i < vehicules[threadCounter]->stopsCounter - 1; i++)
  {
    int value = rand() % 170 + 2;
    vehicules[threadCounter]->stops[i] = &linkedList[value];
  }
  vehicules[threadCounter]->stops[vehicules[threadCounter]->stopsCounter - 1] = &linkedList[105];
  vehicules[threadCounter]->x = vehicules[threadCounter]->stops[0]->x;
  vehicules[threadCounter]->y = vehicules[threadCounter]->stops[0]->y;

  rc = pthread_create(&threads[threadCounter], NULL, update_car_position, (void *)vehicules[threadCounter]);
  if (rc)
  {
    printf("error, return frim pthread creation\n");
    exit(4);
  }
  threadCounter++;
}

void add_ambulance()
{

    int rc;
    vehicules[threadCounter] = createAmbulance("a");

    srand(time(NULL));
    vehicules[threadCounter]->stopsCounter = 3;
    vehicules[threadCounter]->stops = (NODE **)calloc(vehicules[threadCounter]->stopsCounter, sizeof(NODE *));
    vehicules[threadCounter]->stops[0] = &linkedList[72];
    int i;
    for (i = 1; i < vehicules[threadCounter]->stopsCounter - 1; i++)
    {
        int value = rand() % 170 + 2;
        vehicules[threadCounter]->stops[i] = &linkedList[value];
    }
    vehicules[threadCounter]->stops[vehicules[threadCounter]->stopsCounter - 1] = &linkedList[105];
    vehicules[threadCounter]->x = vehicules[threadCounter]->stops[0]->x;
    vehicules[threadCounter]->y = vehicules[threadCounter]->stops[0]->y;

    rc = pthread_create(&threads[threadCounter], NULL, update_ambulance_position, (void *)vehicules[threadCounter]);
    if (rc)
    {
        printf("error, return frim pthread creation\n");
        exit(4);
    }
    threadCounter++;
}

void add_bus(char *id, int stopsCounter, int stops[], int speed, int color)
{
  char *_id = id;
  int rc;

  vehicules[threadCounter] = createBus(_id, speed, color);
  srand(time(NULL));
  vehicules[threadCounter]->stopsCounter = stopsCounter;
  vehicules[threadCounter]->stops = (NODE **)calloc(vehicules[threadCounter]->stopsCounter, sizeof(NODE *));

  for (int i = 0; i < stopsCounter; i++)
  {
    vehicules[threadCounter]->stops[i] = &linkedList[stops[i]];
  }

  vehicules[threadCounter]->x = linkedList[stops[0]].x;
  vehicules[threadCounter]->y = linkedList[stops[0]].y;

  rc = pthread_create(&threads[threadCounter], NULL, update_car_position, (void *)vehicules[threadCounter]);
  if (rc)
  {
    printf("error, return frim pthread creation\n");
    exit(4);
  }
  threadCounter++;
}

#endif