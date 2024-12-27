#pragma once
#include <iostream>
#include "Segmento.h"
#include "Venta.h"
#include "Descuento.h"

using namespace std;
class Evento
{
private:

	Segmento* segmentos;
	int numeroSegmento;
	int cantidadEspacios;
	string NombreEvento;
	Venta venta;
	Descuento descuento;

public:

	Evento();

	void cantidadSegmento();
	void seleccionDeEntradas();
	void imprimirInformacionEvento();
	void menu();



};

