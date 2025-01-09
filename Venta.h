#pragma once
#include <iostream>
#include <string>
using namespace std;

class Venta
{
private:
	string nombreCliente;
	string cedulaCliente;
	string fechaNacimiento;
public:
	string getNombreCliente();
	string getCedulaCliente();
	string getFechaNacimiento();
	void preguntarDatos();
};