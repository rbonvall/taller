#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

const int N_MONTHS = 12;

struct month {
    int n;
    char abr[4];

    // definir la relacion "<" para dos meses como el orden cronologico;
    // este es el criterio con el que se ordenaran los meses por omision
    bool operator< (const month& other_month) const {
        return (*this).n < other_month.n;
    }
};


// funcion para imprimir un mes paltosamente
ostream& operator<< (ostream& out, month const& m) {
    return out << m.n << " " << m.abr;
}


// funcion de comparacion para ordenamiento alfabetico
bool by_name(const month& m1, const month& m2) {
    return lexicographical_compare(&m1.abr[0], &m1.abr[4],
                                   &m2.abr[0], &m2.abr[4]); }



int main() {
    month months[] = {
        { 1, "Ene"}, { 2, "Feb"}, { 3, "Mar"}, { 4, "Abr"},
        { 5, "May"}, { 6, "Jun"}, { 7, "Jul"}, { 8, "Ago"},
        { 9, "Sep"}, {10, "Oct"}, {11, "Nov"}, {12, "Dic"},
    };

    random_shuffle(&months[0], &months[N_MONTHS]);

    cout << "Meses desordenados:" << endl;
    copy(&months[0], &months[N_MONTHS], ostream_iterator<month>(cout, "\n"));
    cout << endl;

    // como no se especifica la funcion de comparacion, se ordena
    // cronologicamente, que es el criterio por omision que definimos arriba
    sort(&months[0], &months[N_MONTHS]);

    cout << "Meses en orden cronologico:" << endl;
    copy(&months[0], &months[N_MONTHS], ostream_iterator<month>(cout, "\n"));
    cout << endl;

    // para ordenar alfabeticamente, especificamos una funcion de comparacion
    sort(&months[0], &months[N_MONTHS], by_name);

    cout << "Meses en orden alfabetico:" << endl;
    copy(&months[0], &months[N_MONTHS], ostream_iterator<month>(cout, "\n"));
    cout << endl;

    // TODO: busqueda binaria
}

