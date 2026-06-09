#include <stdio.h>
#include <windows.h>
#include "snake.h"

void printTitle()
{
    printf("\t\t\033[1;32m SNAKE GAME\033[0m\n\n");
}
int main()
{
    HANDLE ConsoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    CursorInfo.dwSize=100;
    CursorInfo.bVisible=FALSE;
    SetConsoleCursorInfo(ConsoleHandle, &CursorInfo);
    system("cls");
    printTitle();
    Sleep(2000);
    SNAKE snake;
    PUNCT mancare;
    int GAMEON=1;
    setup(&snake, &mancare);
    while(GAMEON)
    {
        matrice(&snake, mancare);
        taste(&snake,&GAMEON);
        logica(&snake, &mancare, &GAMEON);
        Sleep(150);
    }
    free_memorie(&snake);
    system("cls");
    printf("\t\t\033[1;33m SCORUL:%d\033[0m\n",snake.scorul);
    printf("\t\t\033[1;31m GAME OVER! \033[0m\n");
    return 0;
}