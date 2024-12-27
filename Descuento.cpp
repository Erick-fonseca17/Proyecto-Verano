#include "Descuento.h"

Descuento::Descuento()
{
	porcentaje = 0;
	cantidad = 0;
	contrasenia = " "; 
	descuentoAplicado = 0.0;
}

string Descuento::generarContrasenia(int cantidad)
{
		if (cantidad <= 0) 
		{
			return ""; 
		}

		
		string caracter;

		for (char c = '0'; c <= '9'; ++c) {
			caracter += c; 
		}
		for (char c = 'A'; c <= 'Z'; ++c) {
			caracter += c;
		}
		for (char c = 'a'; c <= 'z'; ++c) {
			caracter += c;
		}
		caracter += "!@#$%^&*()";                   

		
		srand(static_cast<unsigned int>(time(nullptr)));

		
		string contrasenia;
		for (int i = 0; i < cantidad; ++i) {
			int indice = rand() % caracter.length();
			contrasenia += caracter[indice];
		}

		return contrasenia;
}

void Descuento::obtenerContrasenia()
{
	cout << "Su contrasenia es: " << endl;
	getline(cin, contrasenia);
	
	//return contrasenia;
}

bool Descuento::confirmarDescuento(int personaCompra)
{
	if (!descuentoAplicado) {

		if (personaCompra <= cantidad) {
			
			return true;
		}
	}

	return false;

}

float Descuento::aplicarDescuento( float total,int personaCompra)
{
	if (confirmarDescuento(personaCompra)) {

		descuentoAplicado = true;

		return total * (1 - porcentaje / 100.0);
	}

	return total;
}


void Descuento::mostrarDetallesdelDescuento()
{
	std::cout << "Porcentaje: " << porcentaje << "%\n"
		<< "Cantidad disponible: " << cantidad << "\n"
		<< "Codigo: " << contrasenia << "\n"
		<< "Estado: " << (descuentoAplicado ? "Utilizado" : "Disponible") << "\n";
}
