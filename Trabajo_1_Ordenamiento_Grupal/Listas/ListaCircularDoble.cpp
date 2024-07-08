#include "ListaCircularDoble.h"
#include "NodoLCD.h"
#include <iostream>
#include <type_traits>

template <typename T>
class ListaDoble {
public:
    NodoLCD<T>* cabeza;
    NodoLCD<T>* cola;

    ListaDoble() : cabeza(nullptr), cola(nullptr) {}
    ~ListaDoble();

    void agregar(const T& dato);
    void eliminar(NodoLCD<T>* nodo);
    NodoLCD<T>* buscar(const T& dato);
    void mostrar() const;
};

// Implementaciones

template <typename T>
ListaDoble<T>::~ListaDoble() {
    NodoLCD<T>* actual = cabeza;
    while (actual) {
        NodoLCD<T>* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

template <typename T>
void ListaDoble<T>::agregar(const T& dato) {
    NodoLCD<T>* nuevo = new NodoLCD<T>(dato);
    if (!cabeza) {
        cabeza = cola = nuevo;
    }
    else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

template <typename T>
void ListaDoble<T>::eliminar(NodoLCD<T>* nodo) {
    if (!nodo) return;
    if (nodo == cabeza) {
        cabeza = nodo->siguiente;
        if (cabeza) cabeza->anterior = nullptr;
    }
    else if (nodo == cola) {
        cola = nodo->anterior;
        if (cola) cola->siguiente = nullptr;
    }
    else {
        nodo->anterior->siguiente = nodo->siguiente;
        nodo->siguiente->anterior = nodo->anterior;
    }
    delete nodo;
}

template <typename T>
NodoLCD<T>* ListaDoble<T>::buscar(const T& dato) {
    NodoLCD<T>* actual = cabeza;
    while (actual && actual->dato != dato) {
        actual = actual->siguiente;
    }
    return actual;
}

template <typename T>
void ListaDoble<T>::mostrar() const {
    NodoLCD<T>* actual = cabeza;
    while (actual) {
        if constexpr (std::is_pointer<T>::value) {
            actual->dato->mostrarInfo(); // Si T es un puntero, usa '->'
        }
        else {
            actual->dato.mostrarInfo(); // Si T no es un puntero, usa '.'
        }
        actual = actual->siguiente;
    }
}
