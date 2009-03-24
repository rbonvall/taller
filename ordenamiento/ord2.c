#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* estructura para representar meses del an~o */
struct month {
    int n;
    char abr[4];
};

/* lista de meses */
struct month months[] = {
    {1, "Ene"}, {2, "Feb"}, {3, "Mar"}, { 4, "Abr"}, { 5, "May"}, { 6, "Jun"},
    {7, "Jul"}, {8, "Ago"}, {9, "Sep"}, {10, "Oct"}, {11, "Nov"}, {12, "Dic"},
};


/* funcion de comparacion, para ordenar meses alfabeticamente */
int compare_alpha(const void *a_ptr, const void *b_ptr) {
    struct month m1 = *((struct month *) a_ptr);
    struct month m2 = *((struct month *) b_ptr);
    return strcmp(m1.abr, m2.abr);
}


int main() {
    int i;

    /* mostrar meses */
    printf("Meses en orden cronologico:\n");
    for (i = 0; i < 12; ++i)
        printf("%2d %s\n", months[i].n, months[i].abr);
    printf("\n");

    /* ordenar meses en orden alfabetico */
    qsort(months, 12, sizeof *months, &compare_alpha);

    /* mostrar meses ordenados */
    printf("Meses en orden alfabetico:\n");
    for (i = 0; i < 12; ++i)
        printf("%2d %s\n", months[i].n, months[i].abr);
    printf("\n");

    struct month input;
    struct month *result;

    /* buscar el numero del mes ingresado por el usuario,
     * usando busqueda binaria */
    printf("Escriba la abreviacion de un mes\n");
    while (scanf("%s", input.abr) == 1) {
        result = (struct month *) bsearch(&input, months, 12, sizeof *months, &compare_alpha);
        if (result == NULL)
            printf("El mes '%s' no existe\n\n", input.abr);
        else
            printf("'%s' es el mes numero %d\n\n", input.abr, result->n);
    }

    return 0;
}

