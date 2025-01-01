#include "Descuento.h"

Descuento::Descuento()
{
	porcentaje = 0;
	cantidad = 0;
	contrasenia = " "; 
	descuentoAplicado = 0.0;
}

string Descuento::generarContrasenia(int cantidad) {
    if (cantidad <= 0) {
        return "";
    }

    string caracter;

    
    for (char c = '0'; c <= '9'; c++) {
        caracter += c;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        caracter += c;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        caracter += c;
    }
    caracter += "!@#$%^&*()";

    srand(time(0));

    string contrasenia;
    for (int i = 0; i < cantidad; i++) {
        int indice = rand() % caracter.length();
        contrasenia += caracter[indice];
    }

    return contrasenia;
}

void Descuento::IngresarDatosdelEvento()
{
    int tamano = rand() % 5 + 7;

   contrasenia = generarContrasenia(tamano);

    cout << "Ingrese el porcentaje de descuento: ";
    cin >> porcentaje;

    if (porcentaje < 0 || porcentaje > 100) {
        cout << "Error: El porcentaje debe estar entre 0 y 100.\n\n";
        return;
    }

    cout << "Ingrese la cantidad de personas que se les aplicara descuento: ";
    cin >> cantidad;

    if (cantidad < 0) {
        cout << "Error: La cantidad debe ser un número positivo.\n\n";
        return;
    }
    cout << "\nPorcentaje: " << porcentaje << "%\n"
        << "Cantidad personas: " << cantidad << "\n"
        << "Contrasenia: " << contrasenia << "\n";
}

void Descuento::confirmarDescuento(int personaCompra, int precioSegmento)
{
    precioSegmentoActual = precioSegmento;

		if (personaCompra <= cantidad) {
			
            descuentoAprobado= true;
            aplicarDescuento();
		}
}

float Descuento::aplicarDescuento()
{
    int total = 0; 

	if (descuentoAprobado==true) {

        total = porcentaje * precioSegmentoActual / 100.0;
	}

	return total;
}
