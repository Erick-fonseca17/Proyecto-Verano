#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Descuento
{
private:

	int porcentaje;
	int cantidad;
	string contrasenia;
	float precioActual;
	bool descuentoConfigurado;
	bool cantidadPersonasDescuento= false;


public:
	Descuento(string contrasenia,int cantidad,int porcentaje):contrasenia(contrasenia),cantidad(cantidad),porcentaje(porcentaje){}
	Descuento();

	void setCantidad(int cantidad);
	void setContrasenia(string contrasenia);

	int getCantidad();
	int getPorcentaje();
	string getContrasenia();

	string generarContrasenia();
	void menuDescuento(RenderWindow & window, Font& font);
	void IngresarDatosdelEvento(sf::RenderWindow& window, sf::Font& font);
	void getDescuentos();
	bool getCantidadPersonas();
	void setCantidadPersonas(bool cantidadPersonas); 
	void confirmarDescuento(float precioSegmento);
	float aplicarDescuento();
	

};
