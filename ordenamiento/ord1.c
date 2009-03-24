#include <stdio.h>
#include <stdlib.h>


/* funcion de comparacion, * para ordenar enteros en orden ascendente */
int compare_int(const void *a_ptr, const void *b_ptr) {
    int a = *((int *) a_ptr);
    int b = *((int *) b_ptr);
    return a - b;
}


/* funcion de comparacion, * para ordenar por paridad
 * (impares a la izquierda, pares a la derecha) */
int compare_parity(const void *a_ptr, const void *b_ptr) {
    int a = *((int *) a_ptr);
    int b = *((int *) b_ptr);
    return a % 2 - b % 2;
}


int main() {
    int i;
    int values[] = {8, 4, 1, 7, 2, 6, 0, 9, 3, 5};

    /* mostrar arreglo original */
    printf("Lista desordenada: ");
    for (i = 0; i < 10; ++i)
        printf("%d ", values[i]);
    printf("\n");

    /* ordenar arreglo */
    qsort(values, 10, sizeof *values, &compare_int);

    /* mostrar arreglo ordenado */
    printf("Lista ordenada:   ");
    for (i = 0; i < 10; ++i)
        printf("%d ", values[i]);
    printf("\n");

    return 0;
}

