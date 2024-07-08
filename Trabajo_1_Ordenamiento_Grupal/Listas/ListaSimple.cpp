#include "ListaSimple.h"
using namespace std;

ListaSimples::ListaSimples() {
    cabeza = NULL;
}

void ListaSimples::Insertar(int _dato) {
    Nodo* nuevo = new Nodo(_dato);
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo* aux = cabeza;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

void ListaSimples::Buscar(int _dato) {
    Nodo* aux = cabeza;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " si se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

void ListaSimples::Eliminar(int _dato) {
    Nodo* aux = cabeza;
    Nodo* anterior = NULL;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            if (anterior == NULL) {
                cabeza = aux->getSiguiente();
            }
            else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            cout << "El dato " << _dato << " se ha eliminado de la lista" << endl;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

void ListaSimples::Mostrar() {
    Nodo* aux = cabeza;
    while (aux != NULL) {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

int ListaSimples::Obtener(int _pos) {
    Nodo* aux = cabeza;
    int cont = 0;
    while (aux != NULL) {
        if (cont == _pos) {
            return aux->getDato();
        }
        cont++;
        aux = aux->getSiguiente();
    }
    return -1;
}

int ListaSimples::Tamano() {
    Nodo* aux = cabeza;
    int cont = 0;
    while (aux != NULL) {
        cont++;
        aux = aux->getSiguiente();
    }
    return cont;
}

int ListaSimples::Intercambiar(int _pos1, int _pos2) {
    Nodo* aux1 = cabeza;
    Nodo* aux2 = cabeza;
    int cont = 0;
    while (aux1 != NULL) {
        if (cont == _pos1) {
            break;
        }
        cont++;
        aux1 = aux1->getSiguiente();
    }
    cont = 0;
    while (aux2 != NULL) {
        if (cont == _pos2) {
            break;
        }
        cont++;
        aux2 = aux2->getSiguiente();
    }
    int temp = aux1->getDato();
    aux1->setDato(aux2->getDato());
    aux2->setDato(temp);
    return 0;
}