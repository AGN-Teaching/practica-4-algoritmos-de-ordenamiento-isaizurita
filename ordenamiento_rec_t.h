void merge(int A[], int inicio, int medio, int fin) {
    int *aux = new int[fin - inicio + 1];
    int i = inicio;     // índice de la primera mitad
    int j = medio + 1;  // índice de la segunda mitad
    int h = 0;

    // Se recorren ambos subarreglos y se van combinando sus
    // elementos ordenadamente hasta que se haya recorrido
    // totalmente uno de ellos
    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }

    // Si se copiaron todos los elementos de la primera mitad,
    // se copia el resto de la segunda mitad
    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } // Si no, se copia el resto de la primera mitad
    else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }
    
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
    delete [] aux;
}

void merge_sort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        merge_sort(A, inicio, medio);
        merge_sort(A, medio + 1, fin);
        merge(A, inicio, medio, fin);
    }
}



void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

int partition(int A[], int p, int r) {
    // A[r] es el registro elegido cuya llave será el pivote
    int pivote = A[r];
    
    // Indica el índice del último registro cuyo valor
    // es menor a pivote
    int ultimo = p - 1;

    // Se agrupan los elementos menores a pivote en las primeras
    // posiciones de A
    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    // Y se mueve al pivote a su posición correcta
    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}


/*Modificación*/

// Función de inserción utilizada para sublistas pequeñas
void insertion_sort_sublist(int A[], int inicio, int fin)
    {
        for(int j=inicio+1;j<=fin;j++) 
            {
                int k=A[j];
                int i=j-1;

                //Se mueven los elementos de A[inicio...i-1], que son
                //mayores que k, a una posición hacia la derecha
                //de su posición actual
                while(i>=inicio&&A[i]>k) 
                    {
                        A[i+1]=A[i];
                        i=i-1;
                    }
                A[i+1]=k;
            }
    }

// Función merge modificada para utilizar insertion sort en sublistas pequeñas
void merge_modified(int A[], int inicio, int medio, int fin, int k) 
    {
        if(fin-inicio+1<=k) 
            {
                insertion_sort_sublist(A, inicio, fin);
            } 

        else 
            {
                int *aux=new int[fin - inicio + 1];
                int i=inicio;     //Índice de la primera mitad
                int j=medio+1;  //Índice de la segunda mitad
                int h=0;

                //Se recorren ambos subarreglos y se van combinando suS elementos ordenadamente hasta que se haya recorrido
                //totalmente uno de ellos
                while((i<=medio)&&(j<=fin)) 
                    {
                        if(A[i]<=A[j]) 
                            {
                                aux[h]=A[i];
                                i+=1;
                            } 
                        else 
                            {
                                aux[h]=A[j];
                                j+=1;
                            }
                        h+=1;
                    }

                //Si se copiaron todos los elementos de la primera mitad,
                //entonces se copia el resto de la segunda mitad
                if(i>medio) 
                    {
                        while(j<=fin) 
                            {
                                aux[h] = A[j];
                                j += 1;
                                h += 1;
                            }
                    } 
                //Si no, se copia el resto de la primera mitad
                else 
                    {
                        while(i<=medio)
                            {
                                aux[h]=A[i];
                                i+=1;
                                h+=1;
                            }
                    }

                h=0;
                for(int k=inicio;k<=fin;k++) 
                    {
                        A[k]=aux[h];
                        h+=1;
                    }
                delete[] aux;
            }
    }

// Función merge sort modificada que utiliza insertion sort para sublistas pequeñas
void merge_sort_modified(int A[], int inicio, int fin, int k) 
    {
        if(inicio<fin) 
        {
            int medio=(inicio + fin)/2;
            merge_sort_modified(A, inicio, medio, k);
            merge_sort_modified(A, medio + 1, fin, k);
            merge_modified(A, inicio, medio, fin, k);
        }
    }
