#pragma once
#include <iostream>
#include <string>

using namespace std;


class Lista
{
private:

	struct Nodo {

		float valor;
		Nodo* siguiente;
		Nodo* anterior;

		Nodo(float valor) :siguiente(nullptr), anterior(nullptr) {
		
		}
	};

	Nodo* cabeza;
	Nodo* cola;
	float elemento;
public:

	Lista(float elemento);
	virtual ~Lista();

	void insertarInicio();
	void insertarFinal();
	Nodo* buscarElemento();
	bool eliminarElemento();
	void mostratLista();
	

};
