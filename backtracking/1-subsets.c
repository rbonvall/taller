#include <stdio.h>

void print_solution(int a[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}


void backtrack(int a[], int n, int k) {
    if (n == k)
        print_solution(a, n);
    else {
        int nr_candidates = 2;
        int candidates[] = {0, 1};
        int i;

        for (i = 0; i < nr_candidates; ++i) {
            a[k] = candidates[i];
            backtrack(a, n, k + 1);
        }
    }
}


int main() {
    int a[6];
    backtrack(a, 6, 0);
    return 0;
}

