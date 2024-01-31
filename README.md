[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ke8zCzPd)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13581279)
# Práctica 4: Algoritmos de ordenamiento

<br>
<br>

<p align="center">
UNIVERSIDAD AUTÓNOMA METROPOLITANA
<br>
UNIDAD CUAJIMALPA
</p>
<br>
<p align="center">
INGENIERÍA EN COMPUTACIÓN
</p>
<br>
<p align="center">
ESTRUCTURA DE DATOS LINEALES
</p>

<p align="center">
DR. ABEL GARCÍA NÁJERA
</p>
<br>
<p align="center">
PRÁCTICA IV: ALGORITMOS DE ORDENAMIENTO
</p>
<br>
<p align="center">
ZURITA PRADO ISAÍ OBED
</p>

<p align="center">
2223029036
</p>
<br>
<p align="center">
MIÉRCOLES 31 DE ENERO DE 2024  
<p align="center">

<br>
<br>

**Introducción**

Un algoritmo de ordenamiento es un conjunto de reglas o pasos sistemáticos diseñados para organizar elementos de una lista en un orden específico. Estos algoritmos son esenciales en ciencias de la computación y se aplican a conjuntos de datos para facilitar búsquedas eficientes, mejorando el rendimiento de diversas operaciones. Cada algoritmo sigue estrategias únicas, como comparación y intercambio de elementos, para lograr la tarea de ordenar la lista de manera ascendente o descendente. La elección del algoritmo depende del contexto y de las características del conjunto de datos.

<br>
<br>

**Objetivo**

Verificar de forma experimental el tiempo de ejecución de algunos algoritmos de ordenamiento.

<br>
<br>

**Desarrollo y análisis de los datos**

Se inició con la implementación de *ordenamiento.h* y *ordenamiento.cpp* para obtener los datos a analizar. En ellos se trabajará con los algoritmos ```insertionSort```, ```selectionSort```, ```bubbleSort```, ```mergeSort``` y ```quickSort```.

_ordenamiento.h_: Este archivo contiene las declaraciones de funciones y las inclusiones de bibliotecas necesarias para realizar experimentos con algoritmos de ordenamiento. En particular, se incluyen las implementaciones de _ordenamiento_t.h_ y _ordenamiento_rec_t.h_. La función principal es ```ejecutarExperimentos```, que realiza experimentos de rendimiento para varios algoritmos de ordenamiento y registra los tiempos de ejecución en un archivo llamado "resultados.txt". 

_ordenamiento.cpp_: En este archivo se encuentran las implementaciones de funciones relacionadas con experimentos y operaciones en arreglos. La función ```mostrar_arreglo``` imprime un arreglo en la consola, mientras que ```copiarArreglo``` crea y devuelve una copia de un arreglo dado. Las funciones ```arreglo_pseudoaleatorio``` y ```arreglo_ordenado``` generan arreglos pseudoaleatorios y ordenados respectivamente. La función experimentos lleva a cabo experimentos utilizando algoritmos de ordenamiento, generando arreglos según el modo especificado (ascendente, descendente o aleatorio). La función ```main``` maneja la entrada de línea de comandos y llama a la función experimentos para realizar los experimentos según los parámetros proporcionados.

Y los datos obtenidos fueron los siguientes.

Realizaremos un análisis detallado de datos específicos, seguido del cálculo del tiempo promedio y la desviación estándar para cada uno de los algoritmos de ordenamiento.

En el primer escenario, al considerar arreglos pequeños de tamaño 5, se obtiene la siguiente información. Se evidencia una marcada diferencia (aunque medida en nanosegundos), entre el rendimiento de mergeSort en comparación con los demás algoritmos. Esta disparidad se atribuye a la complejidad inherente de ```mergeSort```. En contraste, los algoritmos iterativos, junto con ```quickSort```, exhiben una velocidad de ejecución más favorable para arreglos de este tamaño. Fue un caso bastante similar para arreglos de tamaño 10 y 50, ya que se podrían considerar también arreglos pequeños.


![Captura de pantalla 2024-01-31 a la(s) 12 08 15 a m](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/3b167f1c-54f1-40f4-afde-33018808d66b)


<img width="715" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/2e729884-4c17-45e0-839d-ebd9296c4280">

<br>
<br>


En el contexto de arreglos de tamaños variados (100, 500, 1000, 5000, 10000, 50000, 100000, 500000), se observa un cambio significativo en el panorama. Destaca la clara ventaja que presentan los algoritmos ```mergeSort``` y ```quickSort```, ya que muestran valores de ejecución notablemente bajos en comparación con los demás algoritmos iterativos.

En particular, al analizar el caso del arreglo de tamaño 100000, se evidencia una especie de "linealidad" entre los datos, sugiriendo la eficiencia de cada algoritmo y su estabilidad en el manejo de conjuntos de datos extensos. Cabe resaltar que la ejecución de estos últimos experimentos representó un desafío considerable, ya que consumieron toda una noche y parte de la mañana para generar los resultados registrados en las tablas. Este aspecto destaca la ventaja de los algoritmos recursivos sobre los iterativos en términos de eficiencia temporal para conjuntos de datos considerables.

Asimismo, se destaca que el rendimiento del algoritmo ```bubbleSort``` ya no resulta conveniente en estos escenarios. Este algoritmo muestra tiempos de ejecución significativamente más altos en comparación con los demás, llegando incluso a superar en tiempo al conjunto combinado de los demás algoritmos en ciertos casos. Este hallazgo refuerza la ineficacia de ```bubbleSort``` en situaciones con conjuntos de datos más extensos, subrayando la necesidad de optar por enfoques más eficientes en tales escenarios.


![Captura de pantalla 2024-01-31 a la(s) 12 13 35 a m](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/c1874a47-cbfd-4544-8d67-3169d317d011)

<img width="717" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/97a797cb-9f5a-4294-bda3-49a4b562fbdb">

<br>
<br>

En última instancia, en los casos de arreglos de tamaño considerable (1000000, 5000000, 10000000, 50000000, 100000000, 500000000, 1000000000), los algoritmos ```insertionSort```, ```selectionSort``` y ```bubbleSort``` se vuelven prácticamente obsoletos. Sus tiempos de ejecución proyectan lapsos que podrían extenderse a días, semanas o incluso meses, lo que motiva a limitar el análisis a los algoritmos ```mergeSort``` y ```quickSort```. Estos últimos demuestran ser más eficientes y muestran una gran estabilidad en arreglos de magnitudes tan amplias, con tiempos de ejecución relativamente rápidos. La comparación revela una varianza no tan pronunciada entre ambos algoritmos, destacando su capacidad eficiente para llevar a cabo ordenamientos en conjuntos de datos de esta envergadura. Los resultados detallados y gráficos respaldan este análisis.

n=100,000,000

![Captura de pantalla 2024-01-31 a la(s) 12 21 45 a m](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/2a62c401-3756-4ab8-a12c-9132429ac9c9)

<img width="846" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/370efa28-f09d-4c5e-8cef-77ce4872598a">

<br>
<br>

El conjunto de observaciones conduce a la elaboración de una tabla que engloba los datos completos, incluyendo el tiempo promedio de ejecución y la desviación estándar de múltiples ejecuciones en relación a los diversos tamaños de arreglos mencionados. Esta tabla se presenta como un compendio detallado que refleja la variabilidad y consistencia en el rendimiento de los algoritmos de ordenamiento bajo distintas condiciones, proporcionando una visión integral de su eficiencia en función del tamaño del conjunto de datos.

<img width="1173" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/91c26a62-e0a4-4a23-b53d-518fc712d617">

<img width="451" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/32f1bbca-4db3-4a29-a06b-16a3d33e7841">

Se observa la clara ventaja que tienen los algoritmos de ordenamiento recursivos sobre los iterativos.

<img width="462" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/95a9594d-6090-4ce2-bf99-0456b7cb67bb">


Mientras que para la desviación estándar, que básicamente es una medida que indica cuánto se alejan los valores individuales de un conjunto de datos respecto a su promedio, tenemos los siguientes resultados.

<img width="1173" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/0c29a377-3eef-4805-aa2d-7a11738c64f9">

Una desviación estándar baja sugiere que la mayoría de los valores están cerca del promedio, mientras que una desviación estándar alta indica que los valores están más dispersos alrededor del promedio. Es una herramienta útil para comprender la consistencia o la variabilidad de un conjunto de datos y evaluar la fiabilidad de la media como representante del conjunto.

<br>
<br>

Se examinó la desviación estándar en el contexto del algoritmo ```quickSort``` con una dimensión del conjunto de datos de 10,000,000 elementos revelando los siguientes hallazgos.

<img width="975" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/c3b0794a-dec3-4bb5-852d-b7bad65f3989">

Es evidente que la desviación estándar mantiene la mayor parte de los valores dentro del rango definido por el promedio más y menos la desviación estándar, demostrando la eficacia de este indicador para evaluar la dispersión de los datos y proporcionar una medida representativa de la variabilidad en el conjunto de resultados.

<br>
<br>

A pesar de que ```insertionSort``` no figura como la opción óptima para la clasificación de extensos arreglos, su valor se evidencia al observar la gráfica subsecuente. En esta, la desviación estándar de ```insertionSort``` se mantiene dentro de los límites establecidos. Aunque no compite en eficiencia con otros algoritmos, su habilidad para mantenerse en rangos aceptables sugiere que puede aplicarse de manera razonable en comparación con sus contrapartes. Aunque no sobresale en eficacia, sus resultados son tan precisos como los de otros algoritmos.

<img width="1198" alt="image" src="https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-isaizurita/assets/141947909/6aa200aa-1087-482a-aa6e-9146633ff851">









