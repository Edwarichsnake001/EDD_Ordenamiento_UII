#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuPrincipalGeneral.h"
#include "MenuListasSimples/MenuPrincipalListaSimple.h"
#include "MenuListasDobles/MenuPrincipalListaDoble.h"
#include "MenuListasCirculares/MenuPrincipalListaCircular.h"
#include "MenuListasCircularesDobles/MenuPrincipalListaCircularDoble.h"
// Incluye aquí los headers para Lista Circular Doble cuando esté disponible.

enum Opciones {
    LISTA_SIMPLE,
    LISTA_DOBLE,
    LISTA_CIRCULAR,
    LISTA_CIRCULAR_DOBLE,
    SALIR,
    NUM_OPCIONES
};

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenuGeneral(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Lista Simple",
        "Lista Doble",
        "Lista Circular",
        "Lista Circular Doble",
        "Salir"
    };

    std::cout << "Menu \n\n";
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
                MenuPrincipalListaCircular();
                break;
            case LISTA_CIRCULAR_DOBLE:
                MenuPrincipalListaCircularDoble();
                break;
            case SALIR:
                continuar = false;
                break;
            }
            
        }
    }
}
