#include <iostream>
#include <string.h>
using namespace std;

// Lista de cosas por hacer. Pon tu nombre al lado para reclamar la tarea
/*
    Hacer reporte del proyecto --- Benitez
    Añadir documentación de las funciones --- Stratta
    Función alta --- Stratta
    Función baja --- Cesar
    Función cambio --- Benitez / stratta
    Función generar reporte --- Angel Towers
    Función generar historial --- tentativo >:D
    Función ordenar por numero --- César
    Función ordenar por letra --- César
    Hacer menú (solicitar datos al usuario, imprimir menú, etc...) --- Benitez
*/

int codigo[]; // Código del i-esimo producto
string descripcion[]; // Descripcion del del i-esimo producto
double precio[]; // Precio del del i-esimo producto
int cantidad[]; // Cantidad de unidades en el inventario del del i-esimo producto

// Arreglos usados cuando vayamos a usar la funcion ordenar
int ordenadoPorNumero[];
string ordenadoPorLetra[];

void alta(void);
void baja(void);
void cambio(void);
void generarReporte(void);
void historial(void);

int main(void)
{
    // TODO: Imprimir menu, manejado con switch case

    int opcion; 

    // TODO: Solicitar al usuario opcion a elegir del menú

    switch (opcion)
    {
    case 1:
        // TODO: Dar de alta un producto
        break;
    case 2:
        // TODO: Dar de baja un producto
        break;
    case 3:
        // TODO: Modificar un producto
        break;
    case 4:
        // TODO: Generar reporte
        break;
    case 5:
        // TODO: Entradas y salidas
        break;
    case 6:
        // TODO: Salir del menu
    break;
    default:
        // Cuando el usuario pone algo que no está en el menú
        break;
    }

    return 0;
}

// Hacer descripción de qué hace esto
void alta(void)
{
    //
}

// Hacer descripción de qué hace esto
void baja(void)
{
    //
}

// Hacer descripción de qué hace esto
void modificar(void)
{
    //
}

// Hacer descripción de qué hace esto
void generarReporte(void)
{
    //
}

// Hacer descripción de qué hace esto
void historial(void)
{
    //
}

// Hacer descripción de qué hace esto
void ordenarPorNumero(void)
{

}

// Hacer descripción de qué hace esto
void ordenarPorLetra(void)
{

}