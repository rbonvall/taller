=====================
Clase #2, 16 de marzo
=====================

`« Página de inicio`__

.. __: ../taller

Resumen de clases
-----------------
En clases vimos dos temas:

1. **Entrada de datos**, que según convenga puede hacerse:

  - por caracteres (``fgetc``)
  - por líneas (``fgets``)
  - por ítemes (``scanf`` y ``sscanf``)

2. **Tipos de datos abstractos**.  Los TDAs son tipos de datos definidos por
   las operaciones que se desea aplicar sobre los datos.  Los TDAs ofrecen
   una manera de alto nivel para definir la organización del programa.  Algunos
   TDAs que hay que conocer son:

   - `pila`_ (*stack*): conjunto

     + operaciones: ``push(s, x)``, ``pop(s)``, ``top(s)``
     + implementación típica: arreglo con marca de tope.

   - `cola`_ (*queue*)

     + operaciones: ``enqueue(q, x)``, ``dequeue(q)``
     + implementaciones típicas: `arreglo circular`_, `lista enlazada`_.

   - `diccionario`_

     + operaciones: ``insert(d, k, v)``, ``search(d, k)``, ``delete(d, k)``
     + implementaciones típicas: `lista de asociación`_, `árbol binario
       balanceado`_, `tabla hash`_.

   - `cola de prioridad`_
     
     + operaciones: ``insert(q, x)``, ``getMax(q)``, ``deleteMax(q)``
     + implementación típica: `montículo`_ (heap).

   - `conjunto`_

     + operaciones: ``∪``, ``∩``, ``∈``, ``⊆``, ``−``, ``#``.
     + implementaciones típicas: `tabla hash`_, `árbol binario balanceado`_, 
       `mapa de bits`_.

.. _pila: http://en.wikipedia.org/wiki/Stack_(data_structure)
.. _cola: http://en.wikipedia.org/wiki/Queue_(data_structure)
.. _diccionario: http://en.wikipedia.org/wiki/Dictionary_(data_structure)
.. _cola de prioridad: http://en.wikipedia.org/wiki/Priority_queue
.. _conjunto: http://en.wikipedia.org/wiki/Set_(data_structure)
.. _arreglo circular: http://en.wikipedia.org/wiki/Circular_buffer
.. _lista enlazada: http://en.wikipedia.org/wiki/Linked_list
.. _lista de asociación: http://en.wikipedia.org/wiki/Association_list#Association_lists
.. _árbol binario balanceado: http://en.wikipedia.org/wiki/Binary_search_tree 
.. _tabla hash: http://en.wikipedia.org/wiki/Hash_table
.. _montículo: http://en.wikipedia.org/wiki/Heap_(data_structure)
.. _mapa de bits: http://en.wikipedia.org/wiki/Bit_array

El tema que no alcanzamos a ver fue:

3. **Funciones de ránking**.  Una FdR asocia un entero a cada uno de los
   elementos de un conjunto, de modo que muchas operaciones se pueden
   realizar más convenientemente sobre el conjunto de enteros.

   Por ejemplo, una mazo de naipes puede ser mapeada a enteros entre 1 y 52.
   De este modo:
   
     - barajar el mazo corresponde a obtener una permutación de enteros;
     - elegir una carta al azar corresponde a obtener un entero aleatorio;
     - enumerar las cartas corresponde a recorrer enteros.

Un resumen sobre estos temas los pueden encontrar en la página de `CSE392 (Week
2)`_, el curso en que está basado este ramo.

.. _CSE392 (Week 2): http://www.cs.sunysb.edu/~skiena/392/lectures/week2/

Además, definimos los horarios de laboratorio.  La idea es que asistan a uno de
los horarios de laboratorio y resuelvan allí las tareas, de modo que yo pueda
asistirlos y enseñarles técnicas de resolución más convenientes.  Los
laboratorios serán martes y jueves a las 17:30 en el LabComp.

Problemas asignados para esta semana
------------------------------------

* 110203 `Hartals`_
* 110204 `Crypt Kicker`_
* 110206 `Erdős Numbers`_
* 110207 `Contest Scoreboard`_
* 110208 `Yahtzee`_

.. _Hartals:            http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110203&format=html
.. _Crypt Kicker:       http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110204&format=html
.. _Erdős Numbers:      http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110206&format=html
.. _Contest Scoreboard: http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110207&format=html
.. _Yahtzee:            http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110208&format=html


Discusión sobre la materia y los problemas de esta semana
---------------------------------------------------------
.. include:: comments.rst

