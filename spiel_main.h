/******************************************************************************
spiel_main.h
******************************************************************************/
#ifndef GAME_H
#define GAME_H
#include <Arduino.h>
#include "Configuration.h"
#include "Colors.h"


#define  FIELD_WIDTH       11
#define  FIELD_HEIGHT      10
#define  DIR_UP    1
#define  DIR_DOWN  2
#define  DIR_LEFT  3
#define  DIR_RIGHT 4

#define  BTN_NONE  0
#define  BTN_UP    1
#define  BTN_DOWN  2
#define  BTN_LEFT  3
#define  BTN_RIGHT  4
#define  BTN_START  5
#define  BTN_STOP   6
#define  BTN_EXIT   7

#define SNAKE 1
#define TETRIS 2
#define BRICKS 3
#define PONG 4

uint8_t curControl = BTN_NONE;
uint8_t aktgame = 0;

bool gameisrunning = false;
uint16_t highscore[5] = {0,0,0,0,0}; //Snake, Tetris, Bricks,...
uint8_t gamecount[5] = {0,0,0,0,0}; 

uint16_t aktscore;

int debugval;
int gamesound = 1;

#endif
