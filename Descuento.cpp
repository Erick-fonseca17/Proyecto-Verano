#include "Descuento.h"

Descuento::Descuento()
{
	porcentaje = 0;
	cantidad = 0;
	contrasenia = " "; 
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

    srand(time(0));

    string contraseniaGenerada;
    for (int i = 0; i < 6; i++) 
    {
        int indice = rand() % caracter.length();
        contraseniaGenerada += caracter[indice];
    }

    contrasenia = contraseniaGenerada;

    return contraseniaGenerada;

}

void Descuento::IngresarDatosdelEvento()
{

    contrasenia = generarContrasenia();

   cout << "---------------------- ESTADO DEL DESCUENTO ----------------------\n";
   cout << endl;
   cout << "Ingrese el porcentaje de descuento: ";
   cin >> porcentaje;

    if (porcentaje < 0 || porcentaje > 100) 
    {
        cout << "Error: El porcentaje debe estar entre 0 y 100.\n\n";
        return;
    }

    cout << "Ingrese la cantidad de personas que se les aplicara descuento: ";
    cin >> cantidad;

    if (cantidad < 0)
    {
        cout << "Error: La cantidad debe ser un número positivo.\n\n";
        return;
    }
    cout << "\nPorcentaje: " << porcentaje << "%\n"
        << "Cantidad personas: " << cantidad << "\n"
        << "Contrasenia: " << contrasenia << "\n";
}

void Descuento::confirmarDescuento(int precioSegmento)
{
    precioSegmentoActual = precioSegmento;

    aplicarDescuento();
		 
}

float Descuento::aplicarDescuento()
{
    float total = 0; 

    total = porcentaje * precioSegmentoActual / 100.0;
	
	return total;
}


