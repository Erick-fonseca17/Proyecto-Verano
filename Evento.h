#pragma once
#include <string>
#include "Segmento.h"
#include "Cliente.h"
#include "Descuento.h"

using namespace std;

class Evento
{
private:

	Segmento* segmentos;
	int numeroSegmento;
	string nombreEvento;
	Cliente cliente;
	Descuento descuento;
	int cantidadPersonas;
	int segmentoSeleccionado;
	bool descuentoAceptado = false; // se declara como atributo para que el valor que se le asigne funcione en todos los metodos en que se use
	bool noHaySegmentos = false; // tiene un mismo uso que el primer bool, solo que para evaluar los espacios de cada segmento
	bool contraseniaIncorrecta = true; // se valida como atributo para que su valor no se actualice con cada cambio de persona



public:

	Evento();
	~Evento();

	string getNombreEvento();


	void generarFactura();
	void configurarEvento();
	void venderEntradas();
	void gestionarCompra();
	int seleccionarSegmento();
	bool procesarDescuento();
	void imprimirInformacionEvento();
	void imprimirEstadoDeVentas();
	void infoEstudiantes();
	void mostrarLogo();
	void menu();



};