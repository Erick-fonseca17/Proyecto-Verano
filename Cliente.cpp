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
	cout << "Numero de cedula: " << endl;
	cin >> cedulaCliente;
	cout << "Ingrese la fecha de nacimiento por numeros.\n" << endl;
	cout << "Dia:" << endl;
	cin >> dia;
	cout << "Mes:" << endl;
	cin >> mes;
	cout << "Anio:" << endl;
	cin >> anio;
	
}