#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuPrincipalGeneral.h"
#include "MenuListasSimples/MenuPrincipalListaSimple.h"
#include "MenuListasDobles/MenuPrincipalListaDoble.h"


// Incluye aquí los headers para Lista Doble, Lista Circular, y Lista Circular Doble cuando estén disponibles.

enum Opciones {
    LISTA_SIMPLE,
    LISTA_DOBLE,
    LISTA_CIRCULAR,
    LISTA_CIRCULAR_DOBLE,
    NUM_OPCIONES
};

void setConsole1Color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuGeneral(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Lista Simple",
        "Lista Doble",
        "Lista Circular",
        "Lista Circular Doble"
    };

    std::cout << "Menu Principal General\n\n";
    for (int i = 0; i < NUM_OPCIONES; ++i) {
        if (i == opcion) {
            setConsole1Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsole1Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
}

void MenuPrincipalGeneral() {
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuGeneral(opcion);

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
            case LISTA_SIMPLE:
                MenuPrincipalListaSimple();
                break;
            case LISTA_DOBLE:
                MenuPrincipalListaDoble();
                break;
            case LISTA_CIRCULAR:
                // Llamar a la función correspondiente para Lista Circular
                break;
            case LISTA_CIRCULAR_DOBLE:
                // Llamar a la función correspondiente para Lista Circular Doble
                break;
            }
            std::cout << "Presione cualquier tecla para volver al menu principal...";
            (void)_getch();  // Almacenar el valor de retorno
            break;
        }
    }
}
