#include "NodoCupon.h"

NodoCupon::NodoCupon(Descuento dato):dato(dato),siguiente(nullptr){}


void NodoCupon::setDato(Descuento dato)
{
	this->dato = dato;
}

void NodoCupon::setSigueinte(NodoCupon* siguiente)
{
	this->siguiente = siguiente;
}

Descuento NodoCupon::getDato()
{
	return dato;
}

NodoCupon* NodoCupon::getSiguiente()
{
	return siguiente;
}
