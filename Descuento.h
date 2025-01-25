#pragma once
#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

class Descuento
{
private:

	int porcentaje;
	int cantidad;
	string contrasenia;
	float precioActual;
	bool descuentoConfigurado;
	bool cantidadPersonasDescuento= false;
	Lista lista;
	

public:

	Descuento();

	void setCantidad(int cantidad);
	void setContrasenia(string contrasenia);

	int getCantidad();
	string getContrasenia();

	string generarContrasenia();
	void IngresarDatosdelEvento();
	void getDescuentos();
	bool getCantidadPersonas();
	void setCantidadPersonas(bool cantidadPersonas); 
	bool listaDescuento(string codigo);
	void confirmarDescuento(float precioSegmento);
	float aplicarDescuento();
	

};
