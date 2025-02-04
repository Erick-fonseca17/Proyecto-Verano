#include "Cliente.h"

string Cliente::getNombreCliente()
{
	return nombreCliente;
}

string Cliente::getCedulaCliente()
{
	return cedulaCliente;
}

string Cliente::getFechaNacimiento()
{
	
	string fecha = "";

	if (dia < 10) {
		fecha += "0";
	}
	fecha += to_string(dia) + "/";

	if (mes < 10) {
		fecha += "0";
	}
	fecha += to_string(mes) + "/";

	
	fecha += to_string(anio);

	return fecha;
}

bool Cliente::validarCedula()
{
	for (int i = 0; i < 8; i++) {
		char c = cedulaCliente[i];
		// Comprobar si el carácter es un dígito o una letra
		if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z')) {
			return false;
		}
	}

	return true;
}
 
void Cliente::preguntarDatos()
{
	cout << "\033[0;33m";
	cout << "----------------------- VENTA DE ENTRADAS -----------------------\n";
	cout << "\033[0m";
	cout << endl;
	cout << "Ingrese los datos del comprador: \n";
	cout << endl;
	cout << "Nombre completo: " << endl;
	cin.ignore();
	getline(cin, nombreCliente);

	do {
		cout << "Numero de cedula: " << endl;
		cin >> cedulaCliente;
		if (!validarCedula()) {
			cout << "Cedula incorrecta...\n";
		}
	} while (!validarCedula());

	cout << "Ingrese la fecha de nacimiento por numeros.\n" << endl;
	cout << "Dia:" << endl;
	cin >> dia;
	cout << "Mes:" << endl;
	cin >> mes;
	cout << "Anio:" << endl;
	cin >> anio;
	
}