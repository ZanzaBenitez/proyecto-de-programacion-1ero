#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cctype>
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

int numeroProductos = 0; 

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
        cout << ROJO << "El precio debe ser mayor a 0. Inténtalo de nuevo: " << REINICIAR << "$";
        cin >> precios[numeroProductos];
    }

    cout << "Cantidad en inventario: ";
    cin >> cantidades[numeroProductos];
    while (cantidades[numeroProductos] <= 0)
    {
        cout << ROJO << "La cantidad debe de ser mayor a 0. Inténtalo de nuevo: " << REINICIAR;
        cin >> cantidades[numeroProductos];
    }

    // Validar que el codigo del producto ingresado por el usuario NO exista ya en el stock de productos
    string codigo, cur;
    bool encontrado = true;
    cout << "Código del producto: ";
    while (encontrado == true)
    {   
        encontrado = false;
        cin >> codigo;
        for (int i = 0; i < 100; i++)
        {
            cur = codigosProductos[i];
            if (codigo.compare(cur) == 0)
            {
                encontrado = true;
                break;
            }
        }
        
        if (encontrado == true)
        {
            cout << ROJO << "El código del producto ya existe. Inténtalo de nuevo: " << REINICIAR;
        }
    }
    codigosProductos[numeroProductos] = codigo;
    numeroProductos++; 

    cout << VERDE << "Producto registrado exitosamente." << REINICIAR << endl;
}

// Función para eliminar productos
void baja(void)
{
    cout << AZUL << "Ingresa el código del producto que deseas eliminar: " << REINICIAR;
    string codigoAEliminar;
    cin >> codigoAEliminar;

    bool encontrado = false;
    for (int i = 0; i < 100; i++)
    {
        if (codigosProductos[i] == codigoAEliminar && !nombresProductos[i].empty())
        {
            encontrado = true;
            // Limpiar datos del producto
            nombresProductos[i].clear();
            descripciones[i].clear();
            precios[i] = 0;
            cantidades[i] = 0;
            codigosProductos[i].clear();
            cout << VERDE << "Producto eliminado correctamente." << REINICIAR << endl;
            numeroProductos--;
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

void generarReporte() 
{
    if (numeroProductos == 0)
    {
        cout << ROJO << "No hay productos registrados " << endl << endl;
        return;
    }

    string thisCodigos[100], thisNombres[100], thisDescripciones[100];
    int thisPrecios[100], thisCantidades[100];

    cout << "Total de productos registrados: " << numeroProductos << endl;
    for (int i = 0; i < 100; i++) 
    {
        if (!nombresProductos[i].empty()) 
        {
            cout << "----------------------------" << endl;
            cout << "Código: " << codigosProductos[i] << endl;
            cout << "Nombre: " << nombresProductos[i] << endl;
            cout << "Descripción: " << descripciones[i] << endl;
            cout << "Precio unitario: $" << precios[i] << endl;
            cout << "Cantidad en existencia: " << cantidades[i] << endl;
            cout << "----------------------------" << endl;
            
            thisCodigos[i] = codigosProductos[i];
            thisNombres[i] = nombresProductos[i];
            thisDescripciones[i] = descripciones[i];
            thisPrecios[i] = precios[i];
            thisCantidades[i] = cantidades[i];
        }
    }

    string op = "0";
    while (op.compare("3") != 0) // Salir del menu hasta que el usuario presione 3
    {      
        cout << endl;
        cout << AZUL << "Ingresa una de las siguientes opciones: " << endl;
        cout << "1) Ordenar por código" << endl;
        cout << "2) Ordenar por nombre de producto" << endl;
        cout << "3) Salir" << endl << REINICIAR;
        cin >> op;

        if (op.compare("1") == 0)
        {
            // Ordenar por código ascendente   
            for (int i = 0; i < numeroProductos - 1; i++) 
            {
                for (int j = i + 1; j < numeroProductos; j++) 
                {
                    if (thisCodigos[i] > thisCodigos[j]) {
                        swap(thisCodigos[i], thisCodigos[j]);
                        swap(thisNombres[i], thisNombres[j]);
                        swap(thisDescripciones[i], thisDescripciones[j]);
                        swap(thisPrecios[i], thisPrecios[j]);
                        swap(thisCantidades[i], thisCantidades[j]);
                    }
                }
            }
        }
        else if (op.compare("2") == 0)
        {
            // Ordenar por nombre insensible a mayúsculas y minúsculas
            for (int i = 0; i < numeroProductos - 1; i++) 
            {
                for (int j = i + 1; j < numeroProductos; j++) 
                {
                    string nombre1 = thisNombres[i];
                    string nombre2 = thisNombres[j];

                    // Convertir ambos nombres a minúsculas para comparación case insensitive
                    transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
                    transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);

                    if (nombre1 > nombre2) 
                    {
                        swap(thisCodigos[i], thisCodigos[j]);
                        swap(thisNombres[i], thisNombres[j]);
                        swap(thisDescripciones[i], thisDescripciones[j]);
                        swap(thisPrecios[i], thisPrecios[j]);
                        swap(thisCantidades[i], thisCantidades[j]);
                    }
                }
            }
        }
        else if (op.compare("3") == 0)
        {
            limpiarPantalla();
            cout << ROJO << "Saliendo." << REINICIAR << endl;
            return;
        }
        else
        {
            limpiarPantalla();
            cout << ROJO << "Opcion no en la lista. Saliendo." << REINICIAR << endl;
            return;
        }

        limpiarPantalla();
        imprimirMenu(4);
        cout << "Total de productos registrados: " << numeroProductos << endl;
        // Mostrar productos ordenados
        for (int i = 0; i < numeroProductos; i++) 
        {
            cout << "----------------------------" << endl;
            cout << "Código: " << thisCodigos[i] << endl;
            cout << "Nombre: " << thisNombres[i] << endl;
            cout << "Descripción: " << thisDescripciones[i] << endl;
            cout << "Precio unitario: $" << thisPrecios[i] << endl;
            cout << "Cantidad en existencia: " << thisCantidades[i] << endl;
            cout << "----------------------------" << endl;
        }
    }
}

// Función para mostrar historial
void historial(void)
{
    string codigoProducto;
    int unidades;
    char tipoOperacion; // 'E' para entrada, 'S' para salida
    bool encontrado = false;

    cout << "Ingresa el código del producto: ";
    cin >> codigoProducto;

    // Buscar el producto por código
    for (int i = 0; i < 100; i++)
    {
        if (codigosProductos[i] == codigoProducto && !nombresProductos[i].empty())
        {
            encontrado = true;

            // Mostrar datos del producto
            cout << "------------------------------------------" << endl;
            cout << "Nombre: " << nombresProductos[i] << endl;
            cout << "Descripción: " << descripciones[i] << endl;
            cout << "Precio unitario: $" << precios[i] << endl;
            cout << "Cantidad en existencia: " << cantidades[i] << endl;
            cout << "------------------------------------------" << endl;

            // Solicitar operación
            cout << "Ingresa el tipo de operación (E para entrada, S para salida): ";
            cin >> tipoOperacion;
            tipoOperacion = toupper(tipoOperacion); // Convertir a mayúscula para evitar errores

            if (tipoOperacion != 'E' && tipoOperacion != 'S')
            {
                cout << ROJO << "Operación inválida. Solo se permiten 'E' o 'S'." << REINICIAR << endl;
                return;
            }

            // Solicitar número de unidades
            cout << "Ingresa la cantidad de unidades: ";
            cin >> unidades;

            if (unidades <= 0)
            {
                cout << ROJO << "La cantidad debe ser mayor a 0. Operación cancelada." << REINICIAR << endl;
                return;
            }

            if (tipoOperacion == 'E') // Entrada
            {
                cantidades[i] += unidades; // Incrementar la cantidad en existencia
                limpiarPantalla();
                cout << VERDE << "Entrada registrada exitosamente." << REINICIAR << endl;
            }
            else if (tipoOperacion == 'S') // Salida
            {
                if (cantidades[i] < unidades) // Verificar si hay suficiente inventario
                {
                    cout << ROJO << "No hay suficientes unidades en inventario. Operación cancelada." << REINICIAR << endl;
                    return;
                }
                limpiarPantalla();
                cantidades[i] -= unidades; // Decrementar la cantidad en existencia
                cout << VERDE << "Salida registrada exitosamente." << REINICIAR << endl;
            }

            // Mostrar inventario actualizado
            cout << "------------------------------------------" << endl;
            cout << "Cantidad actualizada en el inventario: " << cantidades[i] << endl;
            cout << "------------------------------------------" << endl;
            return;
        }
    }

    if (!encontrado)
    {
        cout << ROJO << "No se encontró un producto con el código proporcionado." << REINICIAR << endl;
    }
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
            cout << VERDE << "             REISTRAR PRODUCTOS            " << REINICIAR << endl;
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
    cout << VERDE << "Ingresa cualquier carácter para continuar." << REINICIAR << endl;
    cin >> aux;
}

/*  

Lista de cosas por hacer. Pon tu nombre al lado para reclamar la tarea
    Hacer reporte del proyecto --- Benitez
    Función generar historial --- César

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