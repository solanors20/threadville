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

void *update_car_position(void *car)
{
  VEHICLE *tempCar = (VEHICLE *)car;
  int p = 0;

  generateRoute(tempCar, tempCar->stops[p], tempCar->stops[p + 1]);

  DESTINATION *currentDestination = tempCar->route->destination;
  currentDestination = currentDestination->next;
  tempCar->nextDestination = tempCar->stops[p + 1]->name;

  bool canMove = true;
  while (tempCar->run)
  {

    if (p < tempCar->stopsCounter - 1)
    {
      int i = 0;

      if (tempCar->x < currentDestination->node.x && tempCar->y <= currentDestination->node.y)
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
          ++p;
          if (p < tempCar->stopsCounter - 1)
          {
            generateRoute(tempCar, tempCar->stops[p % tempCar->stopsCounter], tempCar->stops[(p + 1) % tempCar->stopsCounter]);
            currentDestination = tempCar->route->destination;
            currentDestination = currentDestination->next;

            usleep(tempCar->delay * 1000000);
            tempCar->nextDestination = tempCar->stops[p + 1]->name;
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
              generateRoute(tempCar, tempCar->stops[p], tempCar->stops[0]);
              currentDestination = tempCar->route->destination;
              currentDestination = currentDestination->next;

              usleep(tempCar->delay * 1000000);
              tempCar->nextDestination = tempCar->stops[0]->name;
              p = -1;
            }
          }
        }
      }

      for (i; i < contadorHilos; i++)
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
      } // for
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
        p = 0;
      }
    }

    usleep(tempCar->speed * 10000);
  }
}

void add_bus(char *id, int stopsCounter, int stops[], int speed, int color)
{
  char *_id = id;
  int rc;

  vehicules[contadorHilos] = createBus(_id, speed, color);
  srand(time(NULL));
  vehicules[contadorHilos]->stopsCounter = stopsCounter;
  vehicules[contadorHilos]->stops = (NODE **)calloc(vehicules[contadorHilos]->stopsCounter, sizeof(NODE *));

  for (int i = 0; i < stopsCounter; i++)
  {
    vehicules[contadorHilos]->stops[i] = &linkedList[stops[i]];
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