=====================
Clase #8, 27 de abril
=====================

`« Página de inicio`__

.. __: ../taller

Resumen de clases
-----------------
La clase fue sobre `backtracking`_, un método sistemático para enumerar todas
las configuraciones de un espacio de búsqueda.  El algoritmo funciona
probando todos los candidatos de una componente, continuando
recursivamente con las componentes siguientes, y volviendo a la componente
anterior para reasignarla.

Cosas a tener en cuenta al diseñar un backtracking:

* representación de la solución (vector **a**);
* cómo identificar cuando la solución construída está completa;
* qué hacer cuando se tiene una solución construída;
* cómo determinar los candidatos en cada paso.


Un backtracking típico en C se ve parecido a esto::

    void backtrack(int a[], int n, int k) {
        if (IS_A_SOLUTION(a, n, k))
            DO_SOMETHING(a, n, k);
        else {
            int nr_candidates, candidates[MAX];
            CONSTRUCT_CANDIDATES(a, n, k, &nr_candidates, candidates);

            for (i = 0; i < nr_candidates; ++i) {
                    a[k] = candidates[i];
                    backtrack(a, n, k + 1);
            }
        }
    }

.. _backtracking: http://en.wikipedia.org/wiki/Backtracking

En clases usamos backtracking para enumerar subconjuntos y permutaciones,
y para resolver el `problema de las ocho reinas`_.  Pueden `bajar los
programas`_ para estudiar el código con atención.

.. _problema de las ocho reinas: http://en.wikipedia.org/wiki/N-queens_problem
.. _bajar los programas: backtracking.tgz



Problemas asignados para esta semana
------------------------------------
* 110802 `15-Puzzle Problem`_
* 110803 `Queue`_
* 110805 `Tug of war`_

.. _15-Puzzle Problem: http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110802&format=html
.. _Queue:             http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110803&format=html
.. _Tug of war:        http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110805&format=html


Discusión sobre la materia y los ejercicios de esta semana
----------------------------------------------------------
.. include:: comments.rst

