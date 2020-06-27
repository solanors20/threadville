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
  add_bus(name, stopsCounter, stops, 1, RED);
}

void enable_green_bus()
{
  int stops[6] = {9, 59, 87, 92, 48, 2};
  int totalStops = 6;
  char *name = "GREEN-BUS";
  busGreenThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 3, GREEN);
}

void enable_blue_bus()
{
  int stops[6] = {131, 177, 170, 120, 93, 89};
  int totalStops = 6;
  char *name = "BLUE-BUS";
  busBlueThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 2, BLUE);
}

void enable_white_bus()
{
  int stops[6] = {65, 125, 171, 110, 50, 4};
  int totalStops = 6;
  char *name = "WHITE-BUS";
  busWhiteThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 5, WHITE);
}

void enable_gray_bus()
{
  int stops[6] = {173, 112, 52, 6, 67, 127};
  int totalStops = 6;
  char *name = "GRAY-BUS";
  busGrayThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 4, GRAY);
}

void enable_black_bus()
{
  int stops[6] = {54, 8, 69, 129, 175, 114};
  int totalStops = 6;
  char *name = "BLACK-BUS";
  busBlackThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 4, BLACK);
}

void enable_orange_bus()
{
  int stops[22] = {121, 124, 16, 17, 125, 128, 20, 21, 129, 167, 166, 58, 55, 163, 162, 54, 51, 159, 158, 50, 12, 13};
  int totalStops = 22;
  char *name = "ORANGE-BUS";
  busOrangeThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 7, ORANGE);
}

void enable_pink_bus()
{
  int stops[22] = {47, 36, 0, 11};
  int totalStops = 4;
  char *name = "PINK-BUS";
  busPinkThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 3, PINK);
}

void enable_lightblue_bus()
{
  int stops[22] = {168, 132, 143, 179};
  int totalStops = 4;
  char *name = "LIGHT-BLUE-BUS";
  busLightBlueThreadCounter = threadCounter;
  add_bus(name, totalStops, stops, 3, LIGHT_BLUE);
}

void init_buses()
{
  enable_red_bus();
  enable_green_bus();
  enable_blue_bus();
  enable_white_bus();
  enable_gray_bus();
  enable_black_bus();
  enable_pink_bus();
  enable_lightblue_bus();
  enable_orange_bus();
}

#endif