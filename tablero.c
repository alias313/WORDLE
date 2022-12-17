#include <stdio.h>
#include "tablero.h"
#include "colores.h"
#include "palabras.h"

int menu() {
    int opcion;

    printf("*-*-*-*-*-*-*-*-*-*WORDLE*-*-*-*-*-*-*-*-*-*\n\n");
    printf("Seleccione el idioma de las palabras:\n");
    printf("0) Debug (te pedira la palabra solucion) (0 palabras).\n");
    printf("1) Catalan (%d palabras)\n", contar_palabras(IDIOMA_CAT));
    printf("2) Ingles (%d palabras)\n", contar_palabras(IDIOMA_EN));
    printf("3) Castellano (%d palabras)\n", contar_palabras(IDIOMA_ES)); 
    printf("4) Finlandes (%d palabras)\n", contar_palabras(IDIOMA_FI));

    do {
        printf("\nIntroduzca la opcion elegida: ");
        scanf("%d%*c", &opcion);
    } while (opcion<0 || opcion>4);
    
    return opcion;
}

void imprimir_tablero(wordle tablero) {
    int i, j;

    for (i=0; i<FILAS; i++) {
        printf("\n    +-+-+-+-+-+-+-+-+-+-+\n    |");
        for (j=0; j<MAX_LETRAS; j++) {
            printf(" ");
            //Condicional para pintar la letra
            if (tablero.tab[i][j].l!=' ')
                printf_color(tablero.tab[i][j].color);
            printf("%c", tablero.tab[i][j].l);
            printf_color(COLOR_DEFAULT);
            printf(" |");
        }
    }
    printf("\n    +-+-+-+-+-+-+-+-+-+-+\n\n");
    
}

void inicializar_tablero(wordle *tablero) {
  int i, j;
  tablero->fila=0;
  //tablero->tab[6][5] = {[0 ... 5]={[0 ... 4]=' '}};
  for (i = 0; i < FILAS; i++) {
    for (j = 0; j < MAX_LETRAS; j++) 
      tablero->tab[i][j].l = ' ';
      tablero->tab[i][j].color = COLOR_DEFAULT;
  }
}

void introducir_palabra(wordle *partida) {
    int i, intento;
    intento = partida->fila;
    printf("Introduce una palabra de 5 letras: ");
    for (i=0; i<MAX_LETRAS; i++) {
        scanf("%c", &partida->tab[intento][i].l);
        //Pasar a mayusculas
        if (partida->tab[intento][i].l > 'Z')
            partida->tab[intento][i].l-= 'a'-'A';
    }
    scanf("%*c");


}

void pintar_palabra(wordle *tablero, char solucion[MAX_LETRAS]) {
    int i, j, count;
    
    for (i=0; i<MAX_LETRAS; i++) {
        count=0;
        //Si encuentra la misma letra en la misma posicion pintarla de verde
        if (tablero->tab[tablero->fila][i].l==solucion[i]) {
            tablero->tab[tablero->fila][i].color=COLOR_LETRA_Y_POSICION_OK;
        }
        else {
            for (j=0; j<MAX_LETRAS; j++) {
                //Si encuentra la misma letra en una posicion distinta la pinta de marron
                if (tablero->tab[tablero->fila][i].l==solucion[j] && i!=j) {
                    tablero->tab[tablero->fila][i].color=COLOR_LETRA_OK;
                    count++;
                }
            // Si en no ha encontrado ninguna letra similar pintarla de gris
            if (count==0)
                tablero->tab[tablero->fila][i].color=COLOR_LETRA_KO; 

            }
        }
    }
}

int partida_acabada(char palabra[MAX_LETRAS], char solucion[MAX_LETRAS], int intento) {
    int i, count;

    count=0;
    for (i=0; i<MAX_LETRAS; i++) {
        if (palabra[i]==solucion[i])
            count++;
    }   

    if (count==5)
        return TRUE;
    else if (intento==FILAS)
        return TRUE;
    else
        return FALSE;
}
