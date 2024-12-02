#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
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

// Manejo del menu
void imprimirMenu(int opcion);
void limpiarPantalla(void);
int validarOpcion(string s);
void continuar(void);

// Declaración de funciones
void alta(void);
void baja(void);
void modificar(void);
void generarReporte(void);
void historial(void);
void ordenarPorNumero(void);
void ordenarPorLetra(void);


int main()
{
    string str; // Función auxiliar para validar la opcion que ponga el usuario
    int opcion; // Opcion a elegir en el menu

    while (true) // El programa acaba hasta que el usuario elija la opcion 6 (salir)
    {
        imprimirMenu(0);
        cin >> str;
        opcion = validarOpcion(str);

        limpiarPantalla();
        switch (opcion)
        {
            case 1: // Añadir producto
                imprimirMenu(opcion);
                alta();
                continuar();
            break;

            case 2: // Eliminar producto
                imprimirMenu(opcion);
                baja();
                continuar();
            break;

            case 3: // Editar producto
                imprimirMenu(opcion);
                modificar();
                continuar();
            break;

            case 4: // Generar reporte
                imprimirMenu(opcion);
                generarReporte();
                continuar();
            break;

            case 5: // Entradas y salidas
                imprimirMenu(opcion);
                historial();                
                continuar();
            break;

            case 6: // Terminar programa
                cout << ROJO << "Sesión terminada correctamente" << REINICIAR << endl;
                return 0;
            break;

            default:
                cout << ROJO << "Opción inválida, intenta de nuevo." << REINICIAR << endl;
                continuar();
            break;
        }
        limpiarPantalla();
    }
}

// Función para registrar productos
void alta(void)
{
    static int numeroProductos = 0; 

    if (numeroProductos >= 100)
    {
        cout << ROJO << "No se pueden registrar más productos. El inventario está lleno." << REINICIAR << endl;
        return;
    }

    cout << AZUL << "Ingresa los datos del nuevo producto:" << REINICIAR << endl;

    cout << "Nombre del producto: ";
    cin.ignore(); 
    getline(cin, nombresProductos[numeroProductos]);

    cout << "Descripción: ";
    getline(cin, descripciones[numeroProductos]);

    cout << "Precio: $";
    cin >> precios[numeroProductos];
    while (precios[numeroProductos] <= 0)
    {
        cout << ROJO << "El precio debe ser mayor a 0. Inténtalo de nuevo: $" << REINICIAR;
        cin >> precios[numeroProductos];
    }

    cout << "Cantidad en inventario: ";
    cin >> cantidades[numeroProductos];
    while (cantidades[numeroProductos] < 0)
    {
        cout << ROJO << "La cantidad no puede ser negativa. Inténtalo de nuevo: " << REINICIAR;
        cin >> cantidades[numeroProductos];
    }

    cout << "Código del producto: ";
    cin >> codigosProductos[numeroProductos];

    cout << VERDE << "Producto registrado exitosamente." << REINICIAR << endl;

    numeroProductos++; 
}

// Función para eliminar productos
void baja(void)
{
    cout << AZUL << "Ingresa el código del producto que deseas eliminar: " << REINICIAR;
    string codigoABorrar;
    cin >> codigoABorrar;

    bool encontrado = false;

    for (int i = 0; i < 100; i++)
    {
        if (codigosProductos[i] == codigoABorrar && !nombresProductos[i].empty())
        {
            encontrado = true;

            
            nombresProductos[i].clear();
            descripciones[i].clear();
            codigosProductos[i].clear();
            precios[i] = 0;
            cantidades[i] = 0;

            cout << VERDE << "Producto eliminado exitosamente." << REINICIAR << endl;
            break;
        }
    }

    if (!encontrado)
    {
        cout << ROJO << "No se encontró un producto con el código proporcionado." << REINICIAR << endl;
    }
}

// Función para modificar productos
void modificar(void)
{
    cout << AZUL << "Ingresa el código del producto que deseas modificar: " << REINICIAR;
    string codigoAModificar;
    cin >> codigoAModificar;

    bool encontrado = false;

    for (int i = 0; i < 100; i++)
    {
        if (codigosProductos[i] == codigoAModificar && !nombresProductos[i].empty())
        {
            encontrado = true;

            cout << VERDE << "Producto encontrado. Ingresa los nuevos datos." << REINICIAR << endl;

            cout << "Nombre actual: " << nombresProductos[i] << endl;
            cout << "Nuevo nombre (o presiona Enter para dejarlo igual): ";
            cin.ignore(); 
            string nuevoNombre;
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty())
                nombresProductos[i] = nuevoNombre;

            cout << "Descripción actual: " << descripciones[i] << endl;
            cout << "Nueva descripción (o presiona Enter para dejarla igual): ";
            string nuevaDescripcion;
            getline(cin, nuevaDescripcion);
            if (!nuevaDescripcion.empty())
                descripciones[i] = nuevaDescripcion;

            cout << "Precio actual: $" << precios[i] << endl;
            cout << "Nuevo precio (o presiona Enter para dejarlo igual): ";
            string nuevoPrecioStr;
            getline(cin, nuevoPrecioStr);
            if (!nuevoPrecioStr.empty())
            {
                float nuevoPrecio = stof(nuevoPrecioStr); 
                if (nuevoPrecio > 0)
                    precios[i] = nuevoPrecio;
                else
                    cout << ROJO << "Precio inválido. Se conserva el precio actual." << REINICIAR << endl;
            }

            cout << "Cantidad actual: " << cantidades[i] << endl;
            cout << "Nueva cantidad (o presiona Enter para dejarla igual): ";
            string nuevaCantidadStr;
            getline(cin, nuevaCantidadStr);
            if (!nuevaCantidadStr.empty())
            {
                int nuevaCantidad = stoi(nuevaCantidadStr); 
                if (nuevaCantidad >= 0)
                    cantidades[i] = nuevaCantidad;
                else
                    cout << ROJO << "Cantidad inválida. Se conserva la cantidad actual." << REINICIAR << endl;
            }

            cout << VERDE << "Producto modificado exitosamente." << REINICIAR << endl;
            break;
        }
    }

    if (!encontrado)
    {
        cout << ROJO << "No se encontró un producto con el código proporcionado." << REINICIAR << endl;
    }


}

// Función para generar reportes
void generarReporte(void) 
{
    int opcionOrdenamiento;
    int totalProductos = 0;

    // Contar productos registrados
    for (int i = 0; i < 100; i++) {
        if (!codigosProductos[i].empty()) { // Verificar si el código del producto no está vacío
            totalProductos++;
        }
    }

    // Verificar si existen productos registrados
    if (totalProductos == 0) {
        cout << ROJO << "No hay productos registrados." << REINICIAR << endl;
        return;
    }

    // Preguntar al usuario cómo desea ordenar
    cout << AZUL << "Seleccione el criterio de ordenamiento:" << REINICIAR << endl;
    cout << "1. Por número de producto" << endl;
    cout << "2. Por nombre de producto" << endl;
    cin >> opcionOrdenamiento;

    // Crear copias para ordenar sin afectar el array original
    int indices[100];
    for (int i = 0; i < totalProductos; i++) {
        indices[i] = i; // Inicializar índices
    }

    // Ordenar por criterio seleccionado
    if (opcionOrdenamiento == 1) {
        // Ordenar por número de producto
        for (int i = 0; i < totalProductos - 1; i++) {
            for (int j = i + 1; j < totalProductos; j++) {
                if (nombresProductos[indices[i]] > nombresProductos[indices[j]]) {
                    // Intercambio de variables
                    int temp = indices[i];
                    indices[i] = indices[j];
                    indices[j] = temp;
                }
            }
        }
    } else if (opcionOrdenamiento == 2) {
        // Ordenar por nombre de producto
        for (int i = 0; i < totalProductos - 1; i++) {
            for (int j = i + 1; j < totalProductos; j++) {
                if (nombresProductos[indices[i]] > nombresProductos[indices[j]]) {
                    // Intercambio de variables
                    int temp = indices[i];
                    indices[i] = indices[j];
                    indices[j] = temp;
                }
            }
        }
    } else {
        cout << ROJO << "Opción no válida. Muestra sin ordenamiento." << REINICIAR << endl;
    }

    // Mostrar el reporte
    cout << VERDE << "==========================================" << REINICIAR << endl;
    cout << VERDE << "               PRODUCT REPORT             " << REINICIAR << endl;
    cout << VERDE << "==========================================" << REINICIAR << endl;
    for (int i = 0; i < totalProductos; i++) {
        int idx = indices[i];
        cout << "Número: " << codigosProductos[idx] << endl;
        cout << "Nombre: " << nombresProductos[idx] << endl;
        cout << "Descripción: " << descripciones[idx] << endl;
        cout << "Precio unitario: $" << precios[idx] << endl;
        cout << "Cantidad en existencia: " << cantidades[idx] << endl;
        cout << "------------------------------------------" << endl;
    }

    cout << AZUL << "Total de productos registraados: " << totalProductos << REINICIAR << endl;
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

// Elimina todos los carácteres de la pantalla del usuario usando comandos
// Detecta si el usuario tiene windows o linux/mac
void limpiarPantalla(void)
{
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux/Mac
    #endif
}

// Imprime el menú correspondiente a lo que haya elegido el usuario.
// Cuando opcion es igual a 0, se imprime el menú principal
void imprimirMenu(int opcion)
{
    switch (opcion)
    {
        case 0:
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
        break;
        case 1:
            cout << VERDE << "===========================================" << REINICIAR << endl;
            cout << VERDE << "            Registrar Productos            " << REINICIAR << endl;
            cout << VERDE << "===========================================" << REINICIAR << endl;
            cout << endl;
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
    }
}

// Valida que un string s sea un caracter entre 0 y 9 (que su valor ascii sea entre 48 y 57 inclusive)
// Si s es un numero entre 0 y 9, se regresa ese número convertido a string.
// De otra forma, se regresa -1
int validarOpcion(string s)
{
    if (s.length() != 1) // Validar que puso solo un caracter
    {
        return -1;
    }
    if (!(s[0] >= 48 && s[0] <= 57)) // Validar que el valor ascii del caracter corresponda a un numero entre 0 y 9
    {
        return -1;
    }
    int res = s[0] - 48; // Tomar el valor ascii del caracter (numero entre 0 y 9 ) y convertirlo a int
    return res;
}

void continuar(void)
{
    string aux;
    cout << VERDE << "Ingresa cualquier caracter para continuar." << REINICIAR << endl;
    cin >> aux;
}

/*  

Lista de cosas por hacer. Pon tu nombre al lado para reclamar la tarea
    Hacer reporte del proyecto --- Benitez
    Añadir documentación de las funciones --- Stratta
    Función alta --- stratta DONE 
    Función baja --- Cesar
    Función cambio --- strattA
    Función generar reporte --- Angel Towers
    Función generar historial --- César
    Función ordenar por numero --- César
    Función ordenar por letra --- César
    Hacer menú  DONE

Nota 1: Hagan las variables GLOBALES!!!!!!!!!!!!!!!

Nota 2:
    Para colorear partes del codigo es necesario declarar globalmente el color, 
    en el siguiente commit subo la tabla de codigos aqui en comentarios
    USAR ESTO PARA CADA OPCION
    cout << GREEN <<"===========================================" << RESET << endl;
    cout << GREEN << "            Register Products              " << RESET << endl;
    cout << GREEN << "===========================================" << RESET << endl;
    cout << endl;
*/