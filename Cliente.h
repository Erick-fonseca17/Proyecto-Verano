#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente
{
private:
	string nombreCliente;
	string cedulaCliente;
	string fechaNacimiento;
	int dia, mes, anio;
	

public:
	string getNombreCliente();
	string getCedulaCliente();
	string getFechaNacimiento(); 
	void preguntarDatos();
};