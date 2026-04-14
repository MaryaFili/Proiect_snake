#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // pentru _kbhit() și _getch()
#include <windows.h> // pentru Sleep()

#define LINII 20
#define COLOANE 40

#define SNAKE_COLOR "\033[32m" // Verde
#define FOOD_COLOR "\033[31m"  // Roșu
#define SCORE_COLOR "\033[33m" // Galben

typedef enum {sus,jos,stanga,dreapta} Directia;

typedef struct {
    int x;
    int y;
}PUNCT;

typedef struct{
    PUNCT *corp;
    int lungime_actuala;
    int capacitate;
    Directia directia_actuala;
    int scorul;
} SNAKE;

//void matrice();
//void initSnake(SNAKE *s);
//void generaremancare();
#endif // SNAKE_H