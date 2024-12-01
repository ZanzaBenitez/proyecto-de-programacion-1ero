#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// variables de colores
const string VERDE = "\033[1;32m";
const string AZUL = "\033[1;34m";
const string REINICIAR = "\033[0m";
const string ROJO = "\033[1;31m";

// datos de los productos
string nombresProductos[100]; 
float precios[100];
string descripciones[100];
int cantidades[100];
string codigosProductos[100];

// Arreglos usados cuando vayamos a usar la función ordenar
int ordenadoPorNumero[1];
string ordenadoPorLetra[1];

// Declaración de funciones
void alta(void);
void baja(void);
void cambio(void);
void generarReporte(void);
void historial(void);
void ordenarPorNumero(void);
void ordenarPorLetra(void);

int opcion;

int main()
{
    cout << VERDE << "==========================================" << REINICIAR << endl;
    cout << VERDE << "           Base de Datos Walmart          " << REINICIAR << endl;
    cout << VERDE << "==========================================" << REINICIAR << endl;
    cout << endl;
    cout << AZUL << "Por favor selecciona una de las siguientes opciones:" << REINICIAR << endl;
    cout << "------------------------------------------" << endl;
    cout << "  " << AZUL << "1." << REINICIAR << "  Registrar Productos" << endl;
    cout << "  " << AZUL << "2." << REINICIAR << "  Eliminar Productos" << endl;
    cout << "  " << AZUL << "3." << REINICIAR << "  Editar Productos" << endl;
    cout << "  " << AZUL << "4." << REINICIAR << "  Reporte de Productos" << endl;
    cout << "  " << AZUL << "5." << REINICIAR << "  Entradas y Salidas" << endl;
    cout << "  " << AZUL << "6." << REINICIAR << "  Cerrar Sesión" << endl;
    cout << "------------------------------------------" << endl;
    cin >> opcion;
    cout << "------------------------------------------" << endl;

    switch (opcion)
    {
    case 1:
        cout << VERDE << "===========================================" << REINICIAR << endl;
        cout << VERDE << "            Registrar Productos            " << REINICIAR << endl;
        cout << VERDE << "===========================================" << REINICIAR << endl;
        cout << endl;
        cout << AZUL << "   Ingresa el nombre del producto:" << REINICIAR << endl;
        cin >> nombresProductos[0];
        cout << AZUL << "   Ingresa el precio del producto:" << REINICIAR << endl;
        cin >> precios[0];
        cout << AZUL << "   Ingresa la descripción del producto:" << REINICIAR << endl;
        cin >> descripciones[0];
        cout << AZUL << "   Ingresa la cantidad del producto:" << REINICIAR << endl;
        cin >> cantidades[0];
        cout << AZUL << "   Ingresa el código del producto:" << REINICIAR << endl;
        cin >> codigosProductos[0];
        cout << VERDE << "¡Datos del producto registrados exitosamente!" << REINICIAR << endl;
        break;

    case 2:
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << VERDE << "              ELIMINAR PRODUCTOS          " << REINICIAR << endl;
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << endl;
        break;

    case 3:
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << VERDE << "               EDITAR PRODUCTO            " << REINICIAR << endl;
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << endl;
        cout << AZUL << "Selecciona qué deseas editar:" << REINICIAR << endl;
        cout << "------------------------------------------" << endl;
        cout << "  " << AZUL << "1." << REINICIAR << "  Nombre" << endl;
        cout << "  " << AZUL << "2." << REINICIAR << "  Descripción" << endl;
        cout << "  " << AZUL << "3." << REINICIAR << "  Precio" << endl;
        cout << "  " << AZUL << "4." << REINICIAR << "  Stock" << endl;
        cout << "  " << AZUL << "5." << REINICIAR << "  Código" << endl;
        cout << "------------------------------------------" << endl;
        break;

    case 4:
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << VERDE << "            REPORTE DE PRODUCTOS          " << REINICIAR << endl;
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << endl;
        break;

    case 5:
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << VERDE << "               ENTRADAS Y SALIDAS         " << REINICIAR << endl;
        cout << VERDE << "==========================================" << REINICIAR << endl;
        cout << endl;
        break;

    case 6:
        cout << ROJO << "Sesión terminada correctamente" << REINICIAR << endl;
        break;

    default:
        cout << ROJO << "Opción inválida, intenta de nuevo." << REINICIAR << endl;
        break;
    }

    return 0;
}

// Función para registrar productos
void alta(void)
{
    // Implementar lógica de registro
}

// Función para eliminar productos
void baja(void)
{
    // Implementar lógica de eliminación
}

// Función para modificar productos
void modificar(void)
{
    // Implementar lógica de modificación
}

// Función para generar reportes
void generarReporte(void)
{
    // Implementar lógica de reporte
}

// Función para mostrar historial
void historial(void)
{
    // Implementar lógica de historial
}

// Función para ordenar por número
void ordenarPorNumero(void)
{
    // Implementar lógica de ordenamiento numérico
}

// Función para ordenar por letra
void ordenarPorLetra(void)
{
    // Implementar lógica de ordenamiento alfabético
}


// Nota 1: Hagan las variables GLOBALES!!!!!!!!!!!!!!!

/*  Lista de cosas por hacer. Pon tu nombre al lado para reclamar la tarea
    Hacer reporte del proyecto --- Benitez
    Añadir documentación de las funciones --- Stratta
    Función alta --- stratta DONE 50%
    Función baja --- Cesar
    Función cambio --- strattA
    Función generar reporte --- Angel Towers
    Función generar historial --- César
    Función ordenar por numero --- César
    Función ordenar por letra --- César
    Hacer menú  DONE

Nota 2:
    Para colorear partes del codigo es necesario declarar globalmente el color, 
    en el siguiente commit subo la tabla de codigos aqui en comentarios
    USAR ESTO PARA CADA OPCION
    cout << GREEN <<"===========================================" << RESET << endl;
    cout << GREEN << "            Register Products              " << RESET << endl;
    cout << GREEN << "===========================================" << RESET << endl;
    cout << endl;


*/