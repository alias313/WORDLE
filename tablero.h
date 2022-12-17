#define FALSE 0
#define TRUE 1
#define MAX_LETRAS 5
#define FILAS 6

typedef struct{
    char l;
    int color;
}tletra;

typedef struct{
    int fila;
    tletra tab[FILAS][MAX_LETRAS];
}wordle;

int menu();
void inicializar_tablero(wordle *tablero); 
void imprimir_tablero(wordle tablero);
void introducir_palabra(wordle *tablero);
void pintar_palabra(wordle *tablero, char solucion[MAX_LETRAS]);
int partida_acabada(char palabra[MAX_LETRAS], char solucion[MAX_LETRAS], int intento);
