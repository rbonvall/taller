#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

// funcion de comparacion para ordenar por paridad
bool by_parity(int i, int j) { return i % 2 < j % 2; }

int main() {
    int v[] = {8, 4, 1, 7, 2, 6, 0, 9, 3, 5};

    // crear vector con los valores de v
    vector<int> values(&v[0], &v[10]);

    cout << "Lista original:             ";
    copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(values.begin(), values.end());

    cout << "Lista ordenada:             ";
    copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    reverse(values.begin(), values.end());

    cout << "Lista invertida:            ";
    copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(values.begin(), values.end());

    cout << "Lista desordenada:          ";
    copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    stable_sort(values.begin(), values.end(), by_parity);

    cout << "Lista ordenada por paridad: ";
    copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

}

