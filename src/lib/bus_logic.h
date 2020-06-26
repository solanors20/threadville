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

//----------------------------------GREEN-BUS
void init_GreenBus() {
    int stops[6] = {2, 9, 59, 86, 83, 48};
    int totalStops = 6;
    char *name = "GREEN-BUS";
    add_bus(name, totalStops, stops, 5, 3);
}


void init_buses()
{
	init_red_bus();
    init_GreenBus();
}

#endif