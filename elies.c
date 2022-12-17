#include <stdio.h>
#include "colores.h"
#include "tablero.h"
#include "palabras.h"

int main()
{
    wordle partida;
    char palabra[MAX_LETRAS], solucion[MAX_LETRAS];
    int resultado, idioma, letra_correcta, i;
     
    idioma = menu();
    palabra_al_azar(idioma, contar_palabras(idioma), solucion);

	inicializar_tablero(&partida);
    resultado=FALSE;
	do {
		introducir_palabra(&partida);

        //Guardando la palabra leida en el string palabra
        for (i=0; i<MAX_LETRAS; i++)
            palabra[i]=partida.tab[partida.fila][i].l;
        //Comprobacion de si la palabra existe
        if (!es_palabra_correcta(idioma, palabra)) {
            printf("La palabra que has introducido no existe, por favor vuelvalo a intentar.\n");
        }
        else {
            pintar_palabra(&partida, solucion);
            imprimir_tablero(partida);
            partida.fila++;
        }
	} while (!partida_acabada(palabra, solucion, partida.fila));
   
    letra_correcta=0;
    for (i=0; i<MAX_LETRAS; i++) {
        if (palabra[i]==solucion[i])
            letra_correcta++;
    }
    if (letra_correcta==5)
        resultado=TRUE;

    if (resultado)
        printf("¡¡¡PALABRA CORRECTA!!! Felicidades :)\n");
    else {
        printf("Se te acabaron los intentos. La palabra correcta era ");
        for (i=0; i<MAX_LETRAS; i++)
            printf("%c", solucion[i]);
        printf(".\n");
    }
}
