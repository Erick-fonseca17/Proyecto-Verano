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
	bool descuentoAplicado;

  

public:

	Descuento();
  
    string generarContrasenia(int cantidad);
	void obtenerContrasenia();
	bool confirmarDescuento(int personaCompra);
	float aplicarDescuento(float total, int personaCompra);
	void mostrarDetallesdelDescuento();

};

