#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuPrincipalListaDoble.h"
#include "menuIntercambioLD.h"
#include "menuBurbujaLD.h"
#include "menuQuickSortLD.h"
#include "menuShellSortLD.h"
#include "menuDistribucionLD.h"
#include "menuRadixLD.h"

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

void setConsole2Color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuLD(int opcion) {
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

    std::cout << "Menu Principal Lista Doble\n\n";
    for (int i = 0; i < NUM_OPCIONES; ++i) {
        if (i == opcion) {
            setConsole2Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsole2Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
}

void MenuPrincipalListaDoble() {
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuLD(opcion);

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
                menuIntercambioLD();
                break;
            case BURBUJA:
                menuBurbujaLD();
                break;
            case QUICKSORT:
                menuQuickSortLD();
                break;
            case SHELLSORT:
                menuShellSortLD();
                break;
            case DISTRIBUCION:
                menuDistribucionLD();
                break;
            case RADIXSORT:
                menuRadixLD();
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
