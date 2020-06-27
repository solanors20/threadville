#ifndef TV_GLOBALS

#define TV_GLOBALS

int threadCounter=0;

int busOrangeThreadCounter=0;
int busRedThreadCounter=0;
int busGreenThreadCounter=0;
int busBlueThreadCounter=0;
int busWhiteThreadCounter=0;
int busBlackThreadCounter=0;
int busGrayThreadCounter=0;
int busPinkThreadCounter=0;
int busLightBlueThreadCounter=0;

#define max_cars 1;
int car_counter_police = max_cars;
pthread_mutex_t lock_police;

#define WIDTH 1080
#define HEIGTH 720

#endif