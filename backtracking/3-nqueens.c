#include <stdio.h>
#define N 8

enum {FALSE = 0, TRUE = 1};

void print_solution(int a[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}


void find_candidates(int a[], int n, int k,
                       int candidates[], int *nr_candidates) {
    *nr_candidates = 0;
    int i, j;
    for (i = 0; i < N; ++i) {      /* i: candidato potencial */
        int already_assigned = FALSE;
        for (j = 0; j < k; ++j)    /* a[j]: valor ya asignado */
            if (i == a[j]) {
                already_assigned = TRUE;
                break;
            }
        if (!already_assigned) {
            candidates[*nr_candidates] = i;
            ++(*nr_candidates);
        }
    }
}


int is_valid_solution(int a[], int n) {
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = i + 1; j < n; ++j)
            if (j - i == a[j] - a[i] || j - i == a[i] - a[j])
                /* encontramos dos reinas que se comen */
                return FALSE;
    return TRUE;
}


/* retorna TRUE cuando encuentra una solucion valida */
int backtrack(int a[], int n, int k) {
    if (n == k) {
        if (is_valid_solution(a, n)) {
            print_solution(a, n);
            return TRUE;
        }
        else
            return FALSE;
    }
    else {
        int nr_candidates;
        int candidates[N];
        find_candidates(a, n, k, candidates, &nr_candidates);
        int found;

        int i;
        for (i = 0; i < nr_candidates; ++i) {
            a[k] = candidates[i];
            found = backtrack(a, n, k + 1);
            if (found)
                return TRUE;
        }
        return FALSE;
    }
}


int main() {
    int a[N];
    backtrack(a, N, 0);
    return 0;
}

