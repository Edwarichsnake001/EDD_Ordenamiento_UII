#pragma once
#include "NodoCD.h"
#include <iostream>

template <typename T>
class ListaCircularDoble {
private:
    NodoCD<T>* cabeza;
    NodoCD<T>* cola;

public:
    ListaCircularDoble();
    ~ListaCircularDoble();

    void insertarAlFinal(T valor);
    void mostrar() const;
};

