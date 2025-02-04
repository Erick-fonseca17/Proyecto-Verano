#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Segmento.h"
#include "Cliente.h"
#include "Descuento.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

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
	bool descuentoAceptado = false;// se declara como atributo para que el valor que se le asigne funcione en todos los metodos en que se use
	bool noHaySegmentos = false;// tiene un mismo uso que el primer bool, solo que para evaluar los espacios de cada segmento
	

public:

	Evento();
	~Evento();

	string getNombreEvento();

	void configurarEvento(RenderWindow& window, Font& font, Text& text);
	void venderEntradas();
	void gestionarCompra();
	int seleccionarSegmento();
	bool procesarDescuento();
	void imprimirInformacionEvento();
	void generarFactura();
	void mostrarFacturas();
	void imprimirEstadoDeVentas();
	void infoEstudiantes();
	void configurarDescuentos(RenderWindow& window, Font& font);
	void menu(RenderWindow& window, sf::Font& font);

};