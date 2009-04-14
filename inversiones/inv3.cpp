/* programacion dinamica usando un map en C++,
 * modificando el programa original lo menos posible */

#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, unsigned long long> cache;

unsigned long long inv(int n, int k) {
    if (n == 0 && k == 0)
        return 1;
    if (k < 0 || k > n * (n - 1) / 2)
        return 0;

    /* retornar de inmediato si el valor esta precalculado */
    if (cache.find(make_pair(n, k)) != cache.end())
        return cache[make_pair(n, k)];

    unsigned long long sum = 0;
    int t;
    for (t = k - n + 1; t <= k; ++t)
        sum += inv(n - 1, t);

    /* guardar el valor antes de retornarlo */
    cache[make_pair(n, k)] = sum;
    return sum;
}


int main() {
    int n, k;

    while (cin) {
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        cout << inv(n, k) << endl;
    }

    return 0;
}

