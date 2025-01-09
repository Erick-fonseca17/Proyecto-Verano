#pragma once
#include <iostream>
#include <string>

using namespace std;

class Descuento
{
private:

	int porcentaje;
	int cantidad;
	string contrasenia;
	float precioActual;

	string* vec;
	int contadorConmtrsenia = 0;

public:

	Descuento();

	void setCantidad(int cantidad);
	void setContrasenia(string contrasenia);

	int getCantidad();
	string getContrasenia();

	string generarContrasenia();
	void confirmarDescuento(float precioSegmento);
	float aplicarDescuento();
	void IngresarDatosdelEvento();

};
