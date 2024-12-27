#include "Venta.h"

void Venta::preguntarDatos()
{
	cout << "Ingrese el nombre del comprador: " << endl;
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese el numero de cedula del comprador: " << endl;
	cin >> cedula;
	cout << "Ingrese la fecha de nacimiento del comprador: " << endl;
	cin >> fechaNacimiento;

}