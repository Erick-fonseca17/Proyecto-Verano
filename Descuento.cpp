#include "Descuento.h"

Descuento::Descuento()
{
    porcentaje = 0;
    cantidad = 0;
    contrasenia = " ";
    srand(time(0));
}

void Descuento::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

void Descuento::setContrasenia(string contrasenia)
{
    this->contrasenia = contrasenia;
}

int Descuento::getCantidad()
{
    return cantidad;
}

string Descuento::getContrasenia()
{

    return contrasenia; 
}

string Descuento::generarContrasenia()
{

    string caracter;

    for (char c = '0'; c <= '9'; c++)
    {
        caracter += c;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        caracter += c;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        caracter += c;
    }
    caracter += "!@#$%^&*()";


    string contraseniaGenerada;

    for (int i = 0; i < 6; i++)
    {
        int indice = rand() % caracter.length();
        contraseniaGenerada += caracter[indice];
    }

    contrasenia = contraseniaGenerada;

    return contraseniaGenerada;

}

void Descuento::getDescuentos()
{
    if (descuentoConfigurado) {

        char opcion;
        cout << "Ya existe un descuento configurado:\n";
        cout << "Porcentaje actual: " << porcentaje << "%, Cantidad de uso: " << cantidad << "\n";
        cout << "Desea actualizar este descuento? (s/n): ";
        cin >> opcion;
       
        if (opcion == 'n' || opcion == 'N') {
            cout << "No se actualizara el descuento.\n";
            return;
        }
        else {
           
            IngresarDatosdelEvento();
            cantidadPersonasDescuento = true; 

        }
    }

    else {
        IngresarDatosdelEvento();
        descuentoConfigurado = true;
    }

  
}

void Descuento::IngresarDatosdelEvento()
{
    cout << "---------------------- ESTADO DEL DESCUENTO ----------------------\n";
    cout << "\033[0m";
    cout << endl;
    cout << "Ingrese el porcentaje de descuento: ";
    cin >> porcentaje;

    if (porcentaje < 0 || porcentaje > 100)
    {
        cout << "\033[0;31m";
        cout << "Error: El porcentaje debe estar entre 0 y 100.\n\n";
        cout << "\033[0m";
    }

    cout << "Ingrese la cantidad de veces que se puede aplicar el cupon: ";
    cin >> cantidad;

    if (cantidad < 0)
    {
        cout << "\033[0;31m";
        cout << "Error: La cantidad debe ser un número positivo\n\n";
        cout << "\033[0m";
    }
    string contra = generarContrasenia(); // se asigna la contraseña generada a contra
    lista.insertarFinal();

    cout << "\nDetalles del Descuento:\n";
    cout << "Porcentaje: " << porcentaje << "%\n";
    cout << "Cantidad de uso: " << cantidad << "\n";

 
    cout << "Cupon: " << contra << "\n"; // muestra las contraseñas de cada cupon      
    cout << "\033[0m";
}

bool Descuento::getCantidadPersonas()
{
    return cantidadPersonasDescuento;
}

void Descuento::setCantidadPersonas(bool cantidadPersonas)
{
    cantidadPersonasDescuento = cantidadPersonas;
}

bool Descuento::listaDescuento(string codigo)
{
    Nodo* nodo = lista.buscarElemento();
    return false;
}

void Descuento::confirmarDescuento(float precioTotal)
{
    precioActual = precioTotal;
   
    aplicarDescuento();

}

float Descuento::aplicarDescuento()
{
    float total = 0;

    total = porcentaje * precioActual / 100.0;

    float precioEntrada = precioActual - total;

    return precioEntrada;
}

