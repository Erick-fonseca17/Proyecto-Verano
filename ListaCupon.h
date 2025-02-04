#pragma once
#include <iostream>
#include "NodoCupon.h"
#include "Descuento.h"
using namespace std;

class ListaCupon
{
private:
	NodoCupon* cabeza;
public:
	ListaCupon();
	void insertar(Descuento dato);
	bool eliminar(string contrasenia);
	NodoCupon* buscar(string contrasenia);
	void imprimir();
};

