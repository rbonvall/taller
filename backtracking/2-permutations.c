#include <stdio.h>
#define MAX 6

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
    for (i = 0; i < MAX; ++i) {    /* i: candidato potencial */
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


void backtrack(int a[], int n, int k) {
    if (n == k)
        print_solution(a, n);
    else {
        int nr_candidates;
        int candidates[MAX];
        find_candidates(a, n, k, candidates, &nr_candidates);

        int i;
        for (i = 0; i < nr_candidates; ++i) {
            a[k] = candidates[i];
            backtrack(a, n, k + 1);
        }
    }
}


int main() {
    int a[MAX];
    backtrack(a, MAX, 0);
    return 0;
}

