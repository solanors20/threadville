#ifndef BUS_LOGIC_H_
#define BUS_LOGIC_H_

#include "vehicle_position_logic.h"

void disable_bus(int bus_index)
{
  vehicules[bus_index]->run = false;
  vehicules[bus_index]->x = 0;
  vehicules[bus_index]->y = 0;
}


void enable_red_bus() {
    int stops[12] = {0, 6, 11, 71, 86, 119, 179, 173, 168, 108, 92, 60};
    int stopsCounter = 12;
    char *name = "RED-BUS";
    busRedThreadCounter = threadCounter;
    add_bus(name, stopsCounter, stops, 5, 1);
}

void disable_red_bus()
{
  disable_bus(busRedThreadCounter);
}


void enable_green_bus() {
    int stops[6] = {9, 59, 87, 92, 48, 2};
    int totalStops = 6;
    char *name = "GREEN-BUS";
    busGreenThreadCounter = threadCounter;
    add_bus(name, totalStops, stops, 5, 3);
}

void disable_green_bus()
{
  disable_bus(busGreenThreadCounter);
}

void init_buses()
{
	enable_red_bus();
  enable_green_bus();
}



#endif