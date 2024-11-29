    //notas y TODO hasta el final del codigo
    
    #include <iostream>
    #include <string.h>
    #include <string>
    using namespace std;
     //variables de colores
    const string GREEN = "\033[1;32m";
    const string BLUE = "\033[1;34m";
    const string RESET = "\033[0m";
    const string RED = "\033[1;31m";
    //datos de los productos
    string nameofproducts[100]; 
    float price[100];
    string description[100];
    int quantity[100];
    string productCode[100];
    

    // Arreglos usados cuando vayamos a usar la funcion ordenar
    int ordenadoPorNumero[1];
    string ordenadoPorLetra[1];

    void alta(void);
    void baja(void);
    void cambio(void);
    void generarReporte(void);
    void historial(void);
    int opcion;
    int main() // no uses int main (void) :)
    {
     
    
    cout << GREEN << "==========================================" << RESET << endl;
    cout << GREEN << "            Walmart's Data Base           " << RESET << endl;
    cout << GREEN << "==========================================" << RESET << endl;
    cout << endl;
    cout << BLUE << "Please select one of the following options:" << RESET << endl;
    cout << "------------------------------------------" << endl;
    cout << "  " << BLUE << "1." << RESET << "  Register Products" << endl;
    cout << "  " << BLUE << "2." << RESET << "  Delete Products" << endl;
    cout << "  " << BLUE << "3." << RESET << "  Edit Products" << endl;
    cout << "  " << BLUE << "4." << RESET << "  Product Report" << endl;
    cout << "  " << BLUE << "5." << RESET << "  In & Out" << endl;
    cout << "  " << BLUE << "6." << RESET << "  Log Off" << endl;
    cout << "------------------------------------------" << endl;
    cin>>opcion;
    cout << "------------------------------------------" << endl;
    switch (opcion)
    {
    case 1:
     cout << GREEN <<"===========================================" << RESET << endl;
    cout << GREEN << "            Register Products              " << RESET << endl;
    cout << GREEN << "===========================================" << RESET << endl;
    cout << endl;
     cout << BLUE << "   Please write the name of the product" << RESET << endl;
    cin >> nameofproducts[0];
    cout << BLUE << "   Please write the price of the product" << RESET << endl;
    cin >> price[0];
    cout << BLUE << "   Please write the description of the product" << RESET << endl;
    cin >> description[0];
    cout << BLUE << "   Please write the quantity of the product" << RESET << endl;
    cin >> quantity[0];
    cout << BLUE << "   Please write the product code" << RESET << endl;
    cin >> productCode[0];
    cout << GREEN << "Product data has been successfully added!" << RESET << endl;


        break;
    case 2:
        // TODO: Dar de baja un producto
        break;
    case 3:
    cout << GREEN << "==========================================" << RESET << endl;
    cout << GREEN << "               Edit a Product             " << RESET << endl;
    cout << GREEN << "==========================================" << RESET << endl;
    cout << endl;
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
        cout << RED << "Invalid option, please try again." << RESET << endl;
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
    // Hagan las variables GLOBALES!!!!!!!!!!!!!!!
    // Lista de cosas por hacer. Pon tu nombre al lado para reclamar la tarea
    /*
    Hacer reporte del proyecto --- Benitez
    Añadir documentación de las funciones --- Stratta
    Función alta --- DONE 50%
    Función baja --- Cesar
    Función cambio --- Benitez / strattA
    Función generar reporte --- Angel Towers
    Función generar historial --- tentativo >:D
    Función ordenar por numero --- César
    Función ordenar por letra --- César
    Hacer menú  DONE
    */

   //Para colorear partes del codigo es necesario declarar globalmente el color, en el siguiente commit subo la tabla de codigos aqui en comentarios
 /* USAR ESTO PARA CADA OPCION
  cout << GREEN <<"===========================================" << RESET << endl;
    cout << GREEN << "            Register Products              " << RESET << endl;
    cout << GREEN << "===========================================" << RESET << endl;
    cout << endl;
 
 
 
 
 
 
 */