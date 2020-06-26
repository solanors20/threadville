#ifndef BUS_LOGIC_H_
#define BUS_LOGIC_H_

#include "vehicle_position_logic.h"


void init_red_bus() {
    int stops[12] = {0, 6, 11, 71, 86, 119, 179, 173, 168, 108, 92, 60};
    int stopsCounter = 12;
    char *name = "RED-BUS";
    busRedThreadCounter = threadCounter;
    add_bus(name, stopsCounter, stops, 5, 1);
}

void init_buses()
{
	init_red_bus();
}

#endif