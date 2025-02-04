#include "ListaCupon.h"

ListaCupon::ListaCupon():cabeza(nullptr){}


void ListaCupon::insertar(Descuento dato)
{
	NodoCupon* nuevoNodo = new NodoCupon(dato);

	if (!cabeza) {

		cabeza = nuevoNodo;
	}
	else {
		NodoCupon* aux = cabeza;

		while (aux->getSiguiente()) {

			aux = aux->getSiguiente();
		}
		aux->setSigueinte(nuevoNodo);
	}
}

bool ListaCupon::eliminar(string contrasenia)
{
	if (!cabeza) {

		cout << "Lista vacia..." << endl;
		return false;
	}
	else {
		if (cabeza->getDato().generarContrasenia() == contrasenia) {

			if (cabeza->getDato().getCantidad() > 0) {
				cout << "El cupon ya se uso mas de una vez no puede ser eliminado.." << endl;
				return false;
					
			}
			NodoCupon* aux = cabeza;
			cabeza = cabeza->getSiguiente();
			delete aux;
			cout << "Cabeza eliminada : " << contrasenia << endl;
			return true;
		}
		else {
			NodoCupon* aux = cabeza;

			while (aux->getSiguiente() && aux->getSiguiente()->getDato().getContrasenia() != contrasenia) {

				aux = aux->getSiguiente();

			}
			if (!aux->getSiguiente()) {

				cout << "Cupon seleccionado no se encuentra en la lista: " << contrasenia << endl;
				return false;
			}
			else {
				if (aux->getSiguiente()->getDato().getCantidad() > 0) {

					cout << "El cupon ya se uso mas de una vez no puede ser eliminado.." << endl;
					return false;
				}
			}
				NodoCupon* borrar = aux->getSiguiente();
				aux->setSigueinte(borrar->getSiguiente());
				delete borrar;
				cout << "El Nodo borrado es: " << contrasenia << endl;
				return true;
		}
	}
}

NodoCupon* ListaCupon::buscar(string contrasenia)
{
	NodoCupon* actual = cabeza;

	while (actual) {

		if (actual->getDato().getContrasenia() == contrasenia) {

			return actual;
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
}

void ListaCupon::imprimir()
{
	if (!cabeza) {
		cout << "Lista vacia..." << endl;
	}
	else {
		NodoCupon* aux = cabeza;

		while (aux) {

			cout << "Cupon: " << aux->getDato().getContrasenia() <<
				"Cantidad de Usos: " << aux->getDato().getCantidad()
				<< "Porcentaje: " << aux->getDato().getPorcentaje();
			aux = aux->getSiguiente();
		}
	}
}
