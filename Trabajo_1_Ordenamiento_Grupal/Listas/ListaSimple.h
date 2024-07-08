#pragma once
#include "Nodo.h"

using namespace std;

template<typename T>
class ListaSimple {
private:
    SinglyNode<T>* head;

public:
    ListaSimple() : head(nullptr) {}
    ~ListaSImple() {
        while (head) {
            SinglyNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertFront(const T& value) {
        SinglyNode<T>* newNode = new SinglyNode<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void insertBack(const T& value) {
        SinglyNode<T>* newNode = new SinglyNode<T>(value);
        if (!head) {
            head = newNode;
        }
        else {
            SinglyNode<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int Obtener(int _pos) {
        SinglyNode<T>* aux = head;
        int cont = 0;
        while (aux != NULL) {
            if (cont == _pos) {
                return aux->data;
            }
            cont++;
            aux = aux->next;
        }
        return -1;
    }

    //para quicksort
    int Intercambiar(int _pos1, int _pos2) {
        SinglyNode<T>* aux1 = head;
        SinglyNode<T>* aux2 = head;
        int cont = 0;
        while (aux1 != NULL) {
            if (cont == _pos1) {
                break;
            }
            cont++;
            aux1 = aux1->next;
        }
        cont = 0;
        while (aux2 != NULL) {
            if (cont == _pos2) {
                break;
            }
            cont++;
            aux2 = aux2->next;
        }
        int temp = aux1->data;
        aux1->data = aux2->data;
        aux2->data = temp;
        return 0;
    }

    //para quicksort
    void Mostrar() {
        SinglyNode<T>* aux = head;
        while (aux != NULL) {
            cout << aux->data << " -> ";
            aux = aux->next;
        }
        cout << "NULL" << endl;
    }

    //para quicksort
    int Tamano() {
        SinglyNode<T>* aux = head;
        int cont = 0;
        while (aux != NULL) {
            cont++;
            aux = aux->next;
        }
        return cont;
    }


    bool isEmpty() const {
        return head == nullptr;
    }

    SinglyNode<T>* getHead() const {
        return head;
    }
};