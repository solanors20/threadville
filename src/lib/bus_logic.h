#ifndef BUS_LOGIC_H_
#define BUS_LOGIC_H_

#include "vehicle_position_logic.h"


void enable_red_bus() {
    int stops[12] = {0, 6, 11, 71, 86, 119, 179, 173, 168, 108, 92, 60};
    int stopsCounter = 12;
    char *name = "RED-BUS";
    busRedThreadCounter = threadCounter;
    add_bus(name, stopsCounter, stops, 5, 1);
}

void disable_red_bus()
{
  vehicules[busRedThreadCounter]->run = false;
  vehicules[busRedThreadCounter]->x = 0;
  vehicules[busRedThreadCounter]->y = 0;
}

void init_buses()
{
	enable_red_bus();
}

#endif