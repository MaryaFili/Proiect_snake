#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "snake.h"
void setup(SNAKE *s, PUNCT *mancare)
{
    srand(time(NULL));
    initSnake(s);
    generaremancare(mancare, s);
}

void matrice(SNAKE *s,PUNCT mancare){
    PUNCT init;
    init.x=0;
    init.y=0;
    //pentru a functiona functia folosita mai jos, avem nevoie de o structura de tip COORD, iar pentru a nu schimba structura Programului am ales sa fac asa:
    COORD cordW;
    cordW.X=init.x;
    cordW.Y=init.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cordW);
    int i,j;
    for(i=0;i<COLOANE+2;i++)
    {
        printf("-");
    }
    printf("\n");
    for(i=0;i<LINII;i++)
    {
        for(j=0;j<=COLOANE;j++)
        {
            if(j==0 || j==COLOANE)
            {
                printf("#");
            }
            if(i==s->corp[0].y && j==s->corp[0].x)
            {
                printf(SNAKE_COLOR "O" "\033[0m");
            }
            else if(i==mancare.y && j==mancare.x)
            {
                printf(FOOD_COLOR "$" "\033[0m");
            }
            else{
                int ok=0;
                int k;
                for(k=1;k<s->lungime_actuala;k++)
                {
                    if(i==s->corp[k].y && j==s->corp[k].x)
                    {
                        printf(SNAKE_COLOR "o" "\033[0m");
                        ok=1;
                        break;
                    }
                }
                if(ok==0 && j<COLOANE)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
        for (i=0;i<COLOANE+2;i++)
        printf("-");
        printf("\n");
        printf(SCORE_COLOR "Scor: %d\n" "\033[0m", s->scorul);
        printf("\033[0m"); // Resetare culoare;
        printf("Control: W (sus), A (stanga), S (jos), D (dreapta), X(pentru a iesi)\n");
}
void initSnake(SNAKE *s) {
    s->lungime_actuala = 1;
    s->capacitate = 10; // Capacitatea inițială a corpului șarpelui
    s->scorul=0;
    s->directia_actuala=stop;
    s->corp = (PUNCT *)malloc(s->capacitate *sizeof(PUNCT));
    if (s->corp==NULL) {
        fprintf(stderr, "Eroare la alocarea memoriei pentru corpul șarpelui.\n");
        exit(EXIT_FAILURE);
    }
    s->corp[0].x=COLOANE/2; // Poziția inițială pe axa x
    s->corp[0].y=LINII/2;   // Poziția inițială pe axa y
}

void generaremancare(PUNCT *mancare, SNAKE *s) {
    int ok=0;
    while(ok==0)
{
    mancare->x=rand()%(COLOANE-2)+1;
    mancare->y=rand()%(LINII-2)+1;
    ok=1;
    for(int v=0;v<s->lungime_actuala;v++)
    {
        if(s->corp[v].x==mancare->x && s->corp[v].y==mancare->y)
        {
            ok=0;
            break;
        }
    }
}
    printf("Mâncare generată la poziția (%d, %d)\n", mancare->x, mancare->y);
}
void taste(SNAKE *s)
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'w':
            if(s->directia_actuala!=jos)
            {
                s->directia_actuala=sus;
            }
            break;
            case 's':
            if(s->directia_actuala!=sus)
            {
                s->directia_actuala=jos;
            }
            break;
            case 'a':
            if(s->directia_actuala!=dreapta)
            {
                s->directia_actuala=stanga;
            }
            break;
            case 'd':
            if(s->directia_actuala!=stanga)
            {
                s->directia_actuala=dreapta;
            }
            break;
            case 'x':
            {
                s->directia_actuala=stop;
            }
            break;
        }
    }
}
void logica(SNAKE *s, PUNCT *mancare, int *GAMEON)
{
    if(s->directia_actuala==stop)
    return;
    PUNCT poz_anterioara=s->corp[s->lungime_actuala-1];
    for(int i=s->lungime_actuala-1;i>0;i--)
    {
        s->corp[i]=s->corp[i-1];
    }
    switch(s->directia_actuala)
    {
        case sus:
        {
            s->corp[0].y--;
        }
        break;
        case jos:
        {
            s->corp[0].y++;
        }
        break;
        case stanga:
        {
            s->corp[0].x--;
        }
        break;
        case dreapta:
        {
            s->corp[0].x++;
        }
        break;
        default: break;
    }
    for(int i=1;i<s->lungime_actuala;i++)
    {
        if((s->corp[0].x==s->corp[i].x) && (s->corp[0].y==s->corp[i].y))
        {
            *GAMEON=0;
        }
    }
    if((s->corp[0].x<=0) || (s->corp[0].x>=COLOANE) || (s->corp[0].y<0 || s->corp[0].y>=LINII))
    {
        *GAMEON=0;
    }
    if((s->corp[0].x==mancare->x) && (s->corp[0].y==mancare->y))
    {
        s->scorul+=5;
        if(s->lungime_actuala==s->capacitate)
        {
            s->capacitate+=10;
            PUNCT *buff=(PUNCT*)realloc(s->corp,s->capacitate*sizeof(PUNCT));
            if(buff==NULL)
            {
                perror("Eraoare la realocarea memoriei");
                *GAMEON=0;
            }
            s->corp=buff;
        }
        s->lungime_actuala++;
        s->corp[s->lungime_actuala-1]=poz_anterioara;
        generaremancare(mancare,s);
    }
}
void free_memorie(SNAKE *s)
{
    if(s->corp!=NULL)
    {
        free(s->corp);
        s->corp=NULL;
    }
}