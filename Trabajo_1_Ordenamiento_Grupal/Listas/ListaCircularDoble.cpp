#include "ListaCircularDoble.h"

#include <iostream>
#include "ListaCircularDoble.h"

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble() : cabeza(nullptr), cola(nullptr) {}

template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble() {
    if (!cabeza) return;
    NodoCD<T>* actual = cabeza;
    do {
        NodoCD<T>* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);
}

template <typename T>
void ListaCircularDoble<T>::insertarAlFinal(T valor) {
    NodoCD<T>* nuevoNodo = new NodoCD<T>(valor);
    if (!cabeza) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }
    else {
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        nuevoNodo->siguiente = cabeza;
        cabeza->anterior = nuevoNodo;
        cola = nuevoNodo;
    }
}

template <typename T>
void ListaCircularDoble<T>::mostrar() const {
    if (!cabeza) return;
    NodoCD<T>* actual = cabeza;
    do {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    std::cout << std::endl;
}