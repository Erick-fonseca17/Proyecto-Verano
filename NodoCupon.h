#pragma once
#include <iostream>
using namespace std;
#include "Descuento.h"

class NodoCupon
{
private:

	Descuento dato;
	NodoCupon* siguiente;

public:
	NodoCupon(Descuento dato);

	void setDato(Descuento dato);
	void setSigueinte(NodoCupon* siguiente);
	Descuento getDato();
	NodoCupon* getSiguiente();
};

