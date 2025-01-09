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
	int numeroSegmento;
	int cantidadEspacios;
	string nombreEvento;
	Venta venta;
	Descuento descuento;
	int cantidadPersonas;
	int segmentoSeleccionado;
	bool descuentoAceptado = false; 
	int contadorContrasena;



public:

	Evento();
	~Evento();

	string getNombreEvento();


	void generarFactura();
	void configurarEvento();
	void venderEntradas();
	void gestionarCompra();
	int seleccionarSegmento();
	bool procesarDescuento(int segmentoSeleccionado);
	void imprimirInformacionEvento();
	void imprimirEstadoDeVentas();
	void infoEstudiantes();
	void mostrarLogo();
	void menu();



};