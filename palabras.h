#ifndef PALABRAS_H
#define PALABRAS_H

#define TRUE	1
#define FALSE	0
#define NUM_LETRAS_PALABRA	5
#define IDIOMA_DEBUG	0
#define IDIOMA_CAT	1
#define IDIOMA_EN	2
#define IDIOMA_ES	3
#define IDIOMA_FI	4
#define IDIOMA_MIO	5
#define NUM_IDIOMAS	6

void imprimir_nombre_idioma(int idioma);
int contar_palabras(int idioma);
void inicializar_azar();
void palabra_al_azar(int idioma, int num_palabras, char palabra[NUM_LETRAS_PALABRA]);
int es_palabra_correcta(int idioma, char palabra[NUM_LETRAS_PALABRA]);

#endif // PALABRAS_H

