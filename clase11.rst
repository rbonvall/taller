=====================
Clase #11, 18 de mayo
=====================

`« Página de inicio`__

.. __: ../taller

Resumen de clases
-----------------
La clase fue sobre `ordenamiento topológico`_.

El ordenamiento topológico de un `grafo acíclico dirigido`_ (DAG) es un
ordenamiento de los vértices de modo que cada vértice aparezca antes que sus
vecinos.  En otras palabras, en un orden topológico del grafo todos los arcos
van de izquierda a derecha.

Algunas aplicaciones son:

* encontrar ciclos (el ordenamiento topológico falla en grafos con ciclos);
* procesar los vértices en orden (por ejemplo, en diagramas PERT);
* simplificar problemas de búsquedas;
* algoritmo O(`n`) para ordenar cuando los datos tienen estructura de DAG.

El algoritmo es simple:

#. calcular el número de arcos entrantes de cada vértice;
#. meter los vértices con cero arcos entrantes en una cola;
#. si la cola no está vacía, sacar un vértice de la cola;
#. eliminar los arcos que salen del vértice "desencolado";
#. meter en la cola los vértices que quedaron con cero arcos entrantes;
#. volver al paso 3.
   
El orden en que uno va sacando los vértices de la cola es el orden topológico.

En los apuntes de `CSE392 (Week 9)`_ hay más discusión al respecto.

.. _ordenamiento topológico: http://en.wikipedia.org/wiki/Topological_sorting
.. _grafo acíclico dirigido: http://en.wikipedia.org/wiki/Directed_acyclic_graph
.. _CSE392 (Week 9): http://www.cs.sunysb.edu/~skiena/392/lectures/week9/

Pueden bajar los programas de ejemplo de `bfs, dfs y orden topológico`_.

.. _bfs, dfs y orden topológico: grafos.tgz

Problemas asignados para esta semana
------------------------------------
Las tareas de ordenamiento topológico las dejaremos para la próxima semana,
junto con las de otros algoritmos sobre grafos.  Los que tienen tareas
pendientes **deben** aprovechar de ponerse al día.


Discusión sobre la materia
--------------------------
.. include:: comments.rst

