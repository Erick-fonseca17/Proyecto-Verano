#include "Descuento.h"

Descuento::Descuento()
{
    porcentaje = 0;
    cantidad = 0;
    contrasenia = " ";
    vecContrasenia = NULL;
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

string Descuento::getContrasenia(bool estadoContrasenia)
{
    
    if (estadoContrasenia == false) {

        contadorContrasenia++;// se incrementa para que en cada vuelta del metodo use la contraseña siguiente
    }
    contrasenia = vecContrasenia[contadorContrasenia]; // se asigna la contraseña almacenda en el vector

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

    return contraseniaGenerada;

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
    

    cout << "Ingrese la cantidad de personas que se les aplicara el cupon de descuento: ";
    cin >> cantidad;

    vecContrasenia = new string[cantidad];
    
    if (cantidad < 0)
    {
        cout << "\033[0;31m";
        cout << "Error: La cantidad debe ser un número positivo\n\n";
        cout << "\033[0m";
    }
  
    cout << "\nDetalles del Descuento:\n";
    cout << "Porcentaje: " << porcentaje << "%\n";
    cout << "Cantidad de personas: " << cantidad << "\n";

    for (int i = 0; i < cantidad; i++)
    {
        string contra = generarContrasenia(); // se asigna la contraseña generada a contra

        vecContrasenia[i] = contra;// se guarda la contraseña de contra en el vector dinamico 

        cout << "Cupon " << (i + 1) << ": " << vecContrasenia[i] << "\n"; // muestra las contraseñas de cada cupon 
        
    }

    cout << "\033[0m";
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

