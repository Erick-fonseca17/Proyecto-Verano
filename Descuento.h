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
	bool descuentoAprobado = false; 
	int precioSegmentoActual;

  

public:
	    
	Descuento();
  

    string generarContrasenia(int cantidad);
	void confirmarDescuento(int personaCompra, int precioSegmento);
	float aplicarDescuento();
	void IngresarDatosdelEvento();

};

