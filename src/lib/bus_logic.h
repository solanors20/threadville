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
    int stops[6] = {2, 9, 59, 89, 93, 48};
    int totalStops = 6;
    char *name = "GREEN-BUS";
    add_bus(name, totalStops, stops, 5, 3); 
}

//----------------------------------Blue-BUS
void init_BlueBus() {
    int stops[6] = {131, 177, 170, 120, 93, 89};
    int totalStops = 6;
    char *name = "BLUE-BUS";
    add_bus(name, totalStops, stops, 5, 2); 
}

void init_buses()
{
	init_red_bus();
    init_GreenBus();
    init_BlueBus();
}

#endif