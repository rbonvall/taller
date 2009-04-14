// igual que inv3, pero con codigo C++ mas idiomatico

#include <iostream>
#include <map>
#include <utility>

template <class T>
T inv(int n, int k) {
    if (n == 0 && k == 0)
        return 1;
    if (k < 0 || k > n * (n - 1) / 2)
        return 0;

    typedef std::pair<int, int> ArgsPair;
    typedef std::map<ArgsPair, T> InvCache;

    static InvCache cache;

    // retornar de inmediato si el valor esta precalculado
    ArgsPair args(n, k);
    typename InvCache::iterator pos(cache.find(args));
    if (pos != cache.end())
        return pos->second;

    T sum(0);
    int t;
    for (t = k - n + 1; t <= k; ++t)
        sum += inv<T>(n - 1, t);

    // guardar el valor antes de retornarlo
    cache[args] = sum;
    return sum;
}


int main() {
    int n, k;

    while (std::cin) {
        std::cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        std::cout << inv<unsigned long long>(n, k) << std::endl;
    }

    return 0;
}

