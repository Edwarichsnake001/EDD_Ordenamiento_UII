#include <iostream>
#include <conio.h>
#include <windows.h>
#include "menuQuickSortLS.h"

using namespace std;

enum Opciones {
    PRIMER_NOMBRE,
    SEGUNDO_NOMBRE,
    APELLIDO_PATERNO,
    APELLIDO_MATERNO,
    CEDULA,
    CORREO,
    NUM_OPCIONES
};

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuLS(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Primer Nombre",
        "Segundo Nombre",
        "Apellido Paterno",
        "Apellido Materno",
        "Cedula",
        "Correo",
        "Regresar"
    };

    std::cout << "ORDENAMIENTO DE LISTA POR QUICKSORT\n\n";
    for (int i = 0; i < NUM_OPCIONES; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
}

void menuQuickSort() {
	cout << "Algoritmo de Quick Sort";
}