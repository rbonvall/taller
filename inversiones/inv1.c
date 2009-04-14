#include <stdio.h>

unsigned long long inv(int n, int k) {
    if (n == 0 && k == 0)
        return 1;
    if (k < 0 || k > n * (n - 1) / 2)
        return 0;

    unsigned long long sum = 0;
    int t;
    for (t = k - n + 1; t <= k; ++t)
        sum += inv(n - 1, t);
    return sum;
}


int main() {
    int n, k;

    while (scanf("%d %d", &n, &k) == 2) {
        if (n == 0 && k == 0)
            break;
        printf("%llu\n", inv(n, k));
    }

    return 0;
}

