#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuPrincipalListaCircularDoble.h"
#include "menuIntercambioLCD.h"
#include "menuBurbujaLCD.h"
#include "menuQuickSortLCD.h"
#include "menuShellSortLCD.h"
#include "menuDistribucionLCD.h"
#include "menuRadixLCD.h"

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

void setConsole4Color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuLCD(int opcion) {
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
            setConsole4Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsole4Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
}

void MenuPrincipalListaCircularDoble() {
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuLCD(opcion);

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
                menuIntercambioLCD();
                break;
            case BURBUJA:
                menuBurbujaLCD();
                break;
            case QUICKSORT:
                menuQuickSortLCD();
                break;
            case SHELLSORT:
                menuShellSortLCD();
                break;
            case DISTRIBUCION:
                menuDistribucionLCD();
                break;
            case RADIXSORT:
                menuRadixLCD();
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
