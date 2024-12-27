#include "Segmento.h"

Segmento::Segmento()
{
	cantidadEspacios = 0;
	fila = 0;
	columna = 0;
}

Segmento::Segmento(int cantidadEspacios, int fila, int columna)
{
	this->cantidadEspacios = cantidadEspacios;
	this->fila = fila;
	this->columna = columna;
}

void Segmento::setCantidadEspacios(int cantidadEspacios)
{
	this->cantidadEspacios = cantidadEspacios;
}

void Segmento::setFila(int fila)
{
	this->fila = fila;
}

void Segmento::setColumna(int columna)
{
	this->columna = columna;
}

int Segmento::getCantidadEspacios()
{
	return cantidadEspacios;
}

int Segmento::getFila()
{
	return fila;
}

int Segmento::getColumna()
{
	return columna;
}

void Segmento::preguntarEspacios()
{
	cout << "Ingrese la cantidad de filas que desea: " << endl;
	cin >> fila;
	cout << "Ingrese la cantidad de columnas que desea: " << endl;
	cin >> columna;
	cantidadEspacios = fila * columna;
	cout << "La cantidad de espacios de su segmento es de: " << cantidadEspacios << endl;
}

void Segmento::seleccionarEspacio()
{
	int numeroFila = 0;
	int numeroColumna = 0;
	cout << "Digite el numero de fila: " << endl;
	cin >> numeroFila;
	cout << "Digite el numero de columna: " << endl;
	cin >> numeroColumna;
}
