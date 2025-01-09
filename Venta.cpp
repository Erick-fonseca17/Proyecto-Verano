#include "Venta.h"

string Venta::getNombreCliente()
{
	return nombreCliente;
}

string Venta::getCedulaCliente()
{
	return cedulaCliente;
}

string Venta::getFechaNacimiento()
{
	return fechaNacimiento;
}

void Venta::preguntarDatos()
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
	cout << "Fecha de nacimineto: " << endl;
	cin >> fechaNacimiento;
}