#ifndef snake_h
#define snake_h
#define LINII 20
#define COLOANE 40
#define SNAKE_COLOR "\033[32m" // Verde
#define FOOD_COLOR "\033[31m"  // Roșu
#define SCORE_COLOR "\033[33m" // Galben

typedef enum {stop=0,sus,jos,stanga,dreapta} Directia;

typedef struct {
    int x;
    int y;
}PUNCT;

typedef struct snake{
    PUNCT *corp;
    int lungime_actuala;
    int capacitate;
    Directia directia_actuala;
    int scorul;
}SNAKE;

void setup(SNAKE *s, PUNCT* mancare);
void matrice(SNAKE *s, PUNCT mancare);
void free_memorie(SNAKE *s);
void initSnake(SNAKE *s);
void generaremancare(PUNCT *mancare, SNAKE*s);
void taste(SNAKE *s);
void logica(SNAKE *s,PUNCT *mancare, int *GAMEON);

#endif /* snake_h */