#ifndef BUS_LOGIC_H_
#define BUS_LOGIC_H_

#include "vehicle_position_logic.h"

void disable_bus(int bus_index)
{
  vehicules[bus_index]->run = false;
  vehicules[bus_index]->x = 0;
  vehicules[bus_index]->y = 0;
}

void enable_red_bus()
{
  int stops[12] = {0, 6, 11, 71, 86, 119, 179, 173, 168, 108, 92, 60};
  int stopsCounter = 12;
  char *name = "RED-BUS";
  busRedThreadCounter = threadCounter;
  add_bus(name, stopsCounter, stops, 5, 1);
}



void enable_green_bus()
{
  int stops[6] = {9, 59, 87, 92, 48, 2};
  int totalStops = 6;
  char *name = "GREEN-BUS";
  busGreenThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 5, 3);
}


void enable_blue_bus()
{
  int stops[6] = {131, 177, 170, 120, 93, 89};
  int totalStops = 6;
  char *name = "BLUE-BUS";
  busBlueThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 5, 2);
}

void enable_white_bus() {
     int stops[6] = {65, 125, 171, 110, 50, 4};
     int totalStops = 6;
     char *name = "WHITE-BUS";
     busWhiteThreadCounter = threadCounter;
     add_bus(name, totalStops, stops, 4, 5);
}

void enable_gray_bus() {
    int stops[6] = {173, 112, 52, 6, 67, 127};
    int totalStops = 6;
    char *name = "GRAY-BUS";
    busGrayThreadCounter = threadCounter;
    add_bus(name, totalStops, stops, 4, 8);
}

void enable_black_bus() {
    int stops[6] = {54, 8, 69, 129, 175, 114};
    int totalStops = 6;
    char *name = "BLACK-BUS";
    busBlackThreadCounter = threadCounter;
    add_bus(name, totalStops, stops, 4, 4);
}


void init_buses()
{
  enable_red_bus();
  enable_green_bus();
  enable_blue_bus();
  enable_white_bus();
  enable_gray_bus();
  enable_black_bus();
}

#endif