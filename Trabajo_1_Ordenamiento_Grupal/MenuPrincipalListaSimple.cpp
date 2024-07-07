#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuPrincipalListaSimple.h"
#include "menuIntercambioLS.h"
#include "menuBurbujaLS.h"
#include "menuQuickSortLS.h"
#include "menuShellSortLS.h"
#include "menuDistribucionLS.h"
#include "menuRadixLS.h"

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

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenu(int opcion) {
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

    std::cout << "Menu Principal Lista Simple\n\n";
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

void MenuPrincipalListaSimple() {
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

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
                menuIntercambio();
                break;
            case BURBUJA:
                menuBurbuja();
                break;
            case QUICKSORT:
                menuQuickSort();
                break;
            case SHELLSORT:
                menuShellSort();
                break;
            case DISTRIBUCION:
                menuDistribucion();
                break;
            case RADIXSORT:
                menuRadix();
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
