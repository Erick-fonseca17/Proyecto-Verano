#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Descuento
{
private:

	int porcentaje;
	int cantidad;
	string contrasenia;
	float precioSegmentoActual;



public:

	Descuento();

	void setCantidad(int cantidad);
	void setContrasenia(string contrasenia);

	int getCantidad();
	string getContrasenia();

	string generarContrasenia();
	void confirmarDescuento(int precioSegmento);
	float aplicarDescuento();
	void IngresarDatosdelEvento();

};