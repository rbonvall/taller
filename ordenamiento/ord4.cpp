#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

// si algun dia cambia el numero de meses del an~o, se puede cambiar aqui
enum {N_MONTHS = 12};

struct month {
    int n;
    char abr[4];

    // definir la relacion "<" para dos meses como el orden cronologico;
    // este es el criterio con el que se ordenaran los meses por omision
    bool operator< (const month& other_month) const {
        return this->n < other_month.n;
    }
};


// funcion para poder imprimir un mes paltosamente
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

    // desordenar lista
    random_shuffle(&months[0], &months[N_MONTHS]);
    cout << "Meses desordenados:" << endl;
    copy(&months[0], &months[N_MONTHS], ostream_iterator<month>(cout, "\n"));
    cout << endl;

    // ordenar los meses; como no se especifica la funcion de comparacion,
    // se ocupa la comparacion por omision, que definimos arriba
    sort(&months[0], &months[N_MONTHS]);
    cout << "Meses ordenados segun criterio por omision:" << endl;
    copy(&months[0], &months[N_MONTHS], ostream_iterator<month>(cout, "\n"));
    cout << endl;

    // ordenar los meses por orden alfabetico
    // se ocupa la comparacion por omision, que es la que definimos arriba
    sort(&months[0], &months[N_MONTHS], by_name);
    cout << "Meses en orden alfabetico:" << endl;
    copy(&months[0], &months[N_MONTHS], ostream_iterator<month>(cout, "\n"));
    cout << endl;

    // TODO: busqueda binaria
}

