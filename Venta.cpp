#include "Venta.h"
#include <string>

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
	cout << "----------------------- VENTA DE ENTRADAS -----------------------\n";
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