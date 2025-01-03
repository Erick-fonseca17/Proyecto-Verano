#pragma once
#include <string>
#include "Segmento.h"
#include "venta.h"
#include "Descuento.h"

using namespace std;

class Evento
{
private:

	Segmento* segmentos;
	Segmento segmento1;
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

	string getNombreEvento();
	void generarFactura();
	void configurarEvento();
	void venderEntradas();
	void descuentos();
	void imprimirInformacionEvento();
	void imprimirEstadoDeVentas();
	void menu();



};
