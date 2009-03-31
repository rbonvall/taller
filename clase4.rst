=====================
Clase #4, 30 de marzo
=====================

`« Página de inicio`__

.. __: ../taller

Resumen de clases
-----------------
Vimos los siguientes temas.

1. **Funciones de ránking**:  representar elementos de un conjunto a través de números enteros.
   Los ejemplos típicos:

   * subconjuntos,
   * permutaciones,
   * naipes.

   Algunas operaciones que se simplifican al usar funciones de ránking:

   * iterar sobre los elementos,
   * elegir un elemento al azar,
   * imponer un orden entre los elementos,
   * obtener una permutación de los elementos.

2. **Representación de strings**:  un string es una secuencia de símbolos
   (abstractos), que suelen representarse como arreglos de caracteres.  En
   aplicaciones del "mundo real", es importante tener en consideración las
   consecuencias de detalles de implementación como:

   * codificación utilizada internamente,
   * mutabilidad vs. inmutabilidad,
   * "null-terminated" vs. arreglo+tamaño.

3. **Aritmética de enteros grandes**:  los enteros nativos que proveen los
   lenguajes de programación suelen estar limitados por la arquitectura; para
   trabajar con números arbitrariamente grandes, es necesario implementar a mano
   el tipo entero (típicamente como arreglos de dígitos) y las operaciones
   aritméticas.

   Afortunadamente en Java el problema ya está resuelto en la biblioteca
   estándar en la clase `java.math.BigInteger`_.  También hay bibliotecas de
   enteros grandes para C y C++, como `GMP`_, que sin embargo hay que instalar
   separadamente, y que probablemente el juez virtual no tiene instalada.  Hay
   otros lenguajes (como Python) donde los enteros nativos se convierten
   transparentemente en enteros grandes cuando es necesario.

   En los apuntes de `CSE392 (Week 5)`_ pueden encontrar implementaciones en C
   de operaciones elementales con enteros grandes.

.. _java.math.BigInteger: http://java.sun.com/j2se/1.4.2/docs/api/java/math/BigInteger.html
.. _GMP: http://gmplib.org/
.. _CSE392 (Week 5): http://www.cs.sunysb.edu/~skiena/392/lectures/week5/



Problemas asignados para esta semana
------------------------------------
Relacionados con las materias de las dos últimas clases:

* 110202 `Poker Hands`_
* 110302 `Where's Waldorf?`_
* 110502 `Reverse and Add`_
* 110405 `Shoemaker's Problem`_

.. _Poker Hands: http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110202&format=html
.. _Where's Waldorf?: http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110302&format=html
.. _Reverse and Add: http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110502&format=html
.. _Shoemaker's Problem: http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110405&format=html




Discusión sobre la materia de esta semana
-----------------------------------------
.. include:: comments.rst

