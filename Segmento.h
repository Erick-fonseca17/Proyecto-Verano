#pragma once
#include <iostream>

using namespace std;

class Segmento
{
private:
	int cantidadEspacios;
	int fila;
	int columna;
	int** espacios;
public:

	Segmento();
	Segmento(int cantidadEspacios, int fila, int columna);
	void setCantidadEspacios(int cantidadEspacios);
	void setFila(int fila);
	void setColumna(int columna);
	int getCantidadEspacios();
	int getFila();
	int getColumna();
	void preguntarEspacios();
	void seleccionarEspacio();

};

