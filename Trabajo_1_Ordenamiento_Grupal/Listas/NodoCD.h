#pragma once

template <typename T>
class NodoCD {
public:
    T dato;
    NodoCD* siguiente;
    NodoCD* anterior;

    NodoCD(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};