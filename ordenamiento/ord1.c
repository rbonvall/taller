#include <stdio.h>
#include <stdlib.h>


/* funciones de comparacion */
int compare_int(const void *a_ptr, const void *b_ptr) {
    int a = *((int *) a_ptr);
    int b = *((int *) b_ptr);
    return a - b;
}

int compare_int_rev(const void *a_ptr, const void *b_ptr) {
    /* lo mismo de arriba pero menos legible y en el orden inverso */
    return *((int *) b_ptr) - *((int *) a_ptr);
}

int compare_parity(const void *a_ptr, const void *b_ptr) {
    int a = *((int *) a_ptr);
    int b = *((int *) b_ptr);
    return a % 2 - b % 2;
}



void print_array(int array[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}


int main() {
    int values[] = {8, 4, 1, 7, 2, 6, 0, 9, 3, 5};
    const int N = 10;

    printf("Lista original:             ");
    print_array(values, N);

    qsort(values, N, sizeof *values, &compare_int);

    printf("Lista ordenada:             ");
    print_array(values, N);

    qsort(values, N, sizeof *values, &compare_int_rev);

    printf("Lista invertida:            ");
    print_array(values, N);

    qsort(values, N, sizeof *values, &compare_parity);

    printf("Lista ordenada por paridad: ");
    print_array(values, N);

    return 0;
}

