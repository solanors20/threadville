#ifndef BUS_LOGIC_H_
#define BUS_LOGIC_H_

#include "vehicle_position_logic.h"

//----------------------------------BUS ROJO
void init_busRojo() {
    int paradas[12] = {0, 6, 11, 71, 86, 119, 179, 173, 168, 108, 92, 60};
    int cantidadParadas = 12;
    char *name = "BUS-ROJO";
    hiloBusRojo = contadorHilos;
    add_bus(name, cantidadParadas, paradas, 5, 1);

    //Periferica Grande - Roja> A1, D1, F2, L4, Z (dandole la vuelta), R2, X5, U5, S6, M1, Y (dandole la vuelta)
}

//----------------------------------GREEN-BUS
void init_GreenBus() {
    int stops[6] = {2, 9, 59, 86, 83, 48};
    int totalStops = 6;
    char *name = "GREEN-BUS";
    add_bus(name, totalStops, stops, 5, 3);
}

void initBuses()
{
	init_busRojo();
    init_GreenBus();
}

#endif