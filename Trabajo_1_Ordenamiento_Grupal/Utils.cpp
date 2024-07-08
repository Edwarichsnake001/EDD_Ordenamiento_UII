#include "Utils.h"
#include "Listas/ListaSimple.h"

template <typename T>
void quicksort(ListaSimple<T>* arr, int low, int high)
{
    if (low < high) {
        int pivot = arr->Obtener((low + high) / 2);
        int i = low - 1;
        int j = high + 1;

        while (true) {
            do {
                i++;
            } while (arr->Obtener(i) < pivot);

            do {
                j--;
            } while (arr->Obtener(j) > pivot);

            if (i >= j)
                break;

            arr->Intercambiar(i, j);
        }

        quicksort(arr, low, j);
        quicksort(arr, j + 1, high);
    }
}
