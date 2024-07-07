#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuPrincipalListaCircular.h"
#include "menuIntercambioLC.h"
#include "menuBurbujaLC.h"
#include "menuQuickSortLC.h"
#include "menuShellSortLC.h"
#include "menuDistribucionLC.h"
#include "menuRadixLC.h"

enum Opciones {
    INTERCAMBIO,
    BURBUJA,
    QUICKSORT,
    SHELLSORT,
    DISTRIBUCION,
    RADIXSORT,
    REGRESAR,
    NUM_OPCIONES
};

void setConsole3Color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuLC(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Intercambio",
        "Burbuja",
        "Quick Sort",
        "Shell Sort",
        "Distribucion",
        "Radix Sort",
        "Regresar"
    };

    std::cout << "Menu Principal Lista Circular\n\n";
    for (int i = 0; i < NUM_OPCIONES; ++i) {
        if (i == opcion) {
            setConsole3Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsole3Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
}

void MenuPrincipalListaCircular() {
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuLC(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion) {
            case INTERCAMBIO:
                menuIntercambioLC();
                break;
            case BURBUJA:
                menuBurbujaLC();
                break;
            case QUICKSORT:
                menuQuickSortLC();
                break;
            case SHELLSORT:
                menuShellSortLC();
                break;
            case DISTRIBUCION:
                menuDistribucionLC();
                break;
            case RADIXSORT:
                menuRadixLC();
                break;
            case REGRESAR:
                continuar = false;
                break;
            }
           
        }
    }
}
