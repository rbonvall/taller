#include <stdio.h>

#define N_MAX 19
#define K_MAX 201
unsigned long long cache[N_MAX][K_MAX];

unsigned long long inv(int n, int k) {
    if (n == 0 && k == 0)
        return 1;
    if (k < 0 || k > n * (n - 1) / 2)
        return 0;

    /* retornar de inmediato si el valor esta precalculado */
    if (cache[n][k] != 0)
        return cache[n][k];

    unsigned long long sum = 0;
    int t;
    for (t = k - n + 1; t <= k; ++t)
        sum += inv(n - 1, t);

    /* guardar el valor antes de retornarlo */
    cache[n][k] = sum;
    return sum;
}


int main() {
    int n, k;

    /* inicializar cache */
    for (n = 0; n < N_MAX; ++n)
        for (k = 0; k < K_MAX; ++k)
            cache[n][k] = 0;

    while (scanf("%d %d", &n, &k) == 2) {
        if (n == 0 && k == 0)
            break;
        printf("%llu\n", inv(n, k));
    }

    return 0;
}

