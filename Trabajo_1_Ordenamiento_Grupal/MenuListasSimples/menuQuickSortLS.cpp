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
    REGRESAR,
    NUM_OPCIONES
};

void setConsoleQSLColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuQLS(int opcion) {
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
            setConsoleQSLColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleQSLColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
}

void menuQuickSort() {
	cout << "Algoritmo de Quick Sort";

    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuQLS(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion)
            {
            case PRIMER_NOMBRE:
                break;
            case SEGUNDO_NOMBRE:
                break;
            case APELLIDO_PATERNO:
                break;
            case APELLIDO_MATERNO:
                break;
            case CEDULA:
                break;
            case CORREO:
                break;
            case REGRESAR:
                continuar = false;
                break;
            }
            if (opcion != REGRESAR) {
                std::cout << "Presione cualquier tecla para volver al menu principal...";
                (void)_getch();  // Almacenar el valor de retorno
            }
            break;
        }
    }
}