#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>

#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

using namespace std;
using namespace std::chrono;

void ejecutarExperimentos(int n, int m, int k) 
    {
        //Se abre el archivo de salida que guardará los datos de ejecución
        ofstream outFile("resultados.txt");

        //Encabezado
        outFile << "#Ejec | is_t | ss_t | bs_t | ms_t | qs_t" << endl;

        //Inicialización
        srand((unsigned)time(0));

        //Ciclo principal para "m" ejecuciones
        for (int ejecucion = 1; ejecucion <= m; ejecucion++) 
            {
                int *A = new int[n];

                //Ciclo para generar un arreglo con números aleatorios
                for (int i = 0; i < n; i++) 
                    {
                        A[i] = rand() % (10 * n) + 1;
                    }

                outFile << ejecucion << " | ";

                /*Esta sección del código está midiendo el tiempo de ejecución del algoritmo de ordenamiento 
                insertion_sort en un arreglo aleatorio y registrando ese tiempo en el archivo de salida.
                Y cada bloque es análogo para todos los algoritmos de ordenamiento*/

                //Medición del tiempo para insertion sort
                int *aux_insertion = copiar_arreglo(A, n); //Se crea un puntero que apunta a un nuevo arreglo de tamaño n, este arreglo es una copia de A
                high_resolution_clock::time_point inicio_insertion = high_resolution_clock::now(); //Registro del tiempo
                    insertion_sort(aux_insertion, n); //Llamado al algoritmo de ordenamiento
                high_resolution_clock::time_point fin_insertion = high_resolution_clock::now(); //Registro del tiempo
                duration<double> tiempo_insertion = duration_cast<duration<double>>(fin_insertion - inicio_insertion); //Se calcula la diferencia de tiempo entre el inicio y el final de la ejecución del algoritmo, esto se almacena en la variable de tiempo y se convierte a segundos
                    outFile << tiempo_insertion.count() << " | "; //Escritura en el archivo de salida
                delete[] aux_insertion; //Liberación de la memoria dinámica del arreglo copiado

                //Medición del tiempo para selection sort
                int *aux_selection = copiar_arreglo(A, n);
                high_resolution_clock::time_point inicio_selection = high_resolution_clock::now();
                    selection_sort(aux_selection, n);
                high_resolution_clock::time_point fin_selection = high_resolution_clock::now();
                duration<double> tiempo_selection = duration_cast<duration<double>>(fin_selection - inicio_selection);
                    outFile << tiempo_selection.count() << " | ";
                delete[] aux_selection;

                //Medición del tiempo para bubblesort
                int *aux_bubblesort = copiar_arreglo(A, n);
                high_resolution_clock::time_point inicio_bubblesort = high_resolution_clock::now();
                    bubblesort(aux_bubblesort, n);
                high_resolution_clock::time_point fin_bubblesort = high_resolution_clock::now();
                duration<double> tiempo_bubblesort = duration_cast<duration<double>>(fin_bubblesort - inicio_bubblesort);
                    outFile << tiempo_bubblesort.count() << " | ";
                delete[] aux_bubblesort;

                //Medición del tiempo para merge sort
                int *aux_merge = copiar_arreglo(A, n);
                high_resolution_clock::time_point inicio_merge = high_resolution_clock::now();
                    merge_sort(aux_merge, 0, n - 1);
                high_resolution_clock::time_point fin_merge = high_resolution_clock::now();
                duration<double> tiempo_merge = duration_cast<duration<double>>(fin_merge - inicio_merge);
                    outFile << tiempo_merge.count() << " | ";
                delete[] aux_merge;

                //Medición del tiempo para quicksort
                int *aux_quicksort = copiar_arreglo(A, n);
                high_resolution_clock::time_point inicio_quicksort = high_resolution_clock::now();
                    quicksort(aux_quicksort, 0, n - 1);
                high_resolution_clock::time_point fin_quicksort = high_resolution_clock::now();
                duration<double> tiempo_quicksort = duration_cast<duration<double>>(fin_quicksort - inicio_quicksort);
                outFile << tiempo_quicksort.count() << endl;
                delete[] aux_quicksort;

                duration<double> ordenar_merge_sort_modified(int* A, int TAM_ARREGLO, int k);
                high_resolution_clock::time_point inicio = high_resolution_clock::now();
                merge_sort_modified(aux_merge, 0, n - 1, k);
                high_resolution_clock::time_point fin = high_resolution_clock::now();
                duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    

                delete[] A;
            }

        outFile.close(); //Se cierra el archivo "resultados.txt"
    }
