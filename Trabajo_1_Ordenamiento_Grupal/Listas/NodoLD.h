#pragma once

template <typename T>
class NodoLD {
public:
    T dato;
    NodoLD* siguiente;
    NodoLD* anterior;

    NodoLD(const T& d) : dato(d), siguiente(nullptr), anterior(nullptr) {}
};