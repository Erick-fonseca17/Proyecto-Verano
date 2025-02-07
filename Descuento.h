#pragma once
#include <iostream>
#include <string>
#include "Lista.h"
#include "SFML/Graphics.hpp"
using namespace std;


class Descuento
{
private:

	int porcentaje;
	int cantidad;
	string contrasenia;
	float precioActual;
	Lista<string> listaCupon;
	


public:

	Descuento();

	void setCantidad(int cantidad);
	void setContrasenia(string contrasenia);

	int getCantidad();
	string getContrasenia();

	string generarContrasenia();
	void IngresarDatosdelEvento();
	void mostrarCupones();
	void eliminarCupon();
	void confirmarDescuento(float precioSegmento);
	float aplicarDescuento();


};