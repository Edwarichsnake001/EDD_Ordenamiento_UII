#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "menuQuickSortLC.h"
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

void setConsoleQLCColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuQLC(int opcion) {
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

    std::cout << "ORDENAMIENTO DE LISTA DOBLE POR QUICKSORT\n\n";
    for (int i = 0; i < NUM_OPCIONES; ++i) {
        if (i == opcion) {
            setConsoleQLCColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleQLCColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
}

void menuQuickSortLC() {
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuQLC(opcion);

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

//este comentario es olo para ver  si se actualiza en el quicksort