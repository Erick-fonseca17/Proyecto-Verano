#pragma once
#include <string>
#include "Segmento.h"
#include "venta.h"
#include "Descuento.h"

class Evento
{
private:

	Segmento* segmentos;
	int numeroSegmento;
	int cantidadEspacios;
	string nombreEvento;
	Venta venta;
	Descuento descuento;
	int cantidadPersonas;
	int segmentoSeleccionado;

public:

	Evento();
	~Evento();

	
	void cantidadSegmento();//Datos del evento, cambiar nombre
	void seleccionDeEntradas();
	void descuentos();
	void imprimirInformacionEvento();
	void imprimirEstadoDeVentas();
	void menu();



};
