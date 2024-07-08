#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Nodo {
    T data;
    Nodo* next;

    Node(const T& value) : data(value), next(nullptr) {}
};