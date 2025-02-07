#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T d) : dato(d), siguiente(nullptr) {}
};

template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;
    Nodo<T>* fin;

public:
    Lista() : cabeza(nullptr), fin(nullptr) {}

    ~Lista() {
        Nodo<T>* temp = cabeza;
        while (temp) {
            Nodo<T>* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
    }

    void insertar(T d) {
        Nodo<T>* nuevo = new Nodo<T>(d);

        if (!cabeza) {
            cabeza = nuevo;
            fin = nuevo;
        }
        else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }


    void insertarAlPrincipio(T d) {
        Nodo<T>* nuevo = new Nodo<T>(d);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        if (fin == nullptr) {
            fin = nuevo;
        }
    }

    void mostrar() {
        Nodo<T>* temp = cabeza;
        while (temp) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        cout << "NULL" << endl;
    }

    T obtener(int index) {
        Nodo<T>* actual = cabeza;
        int i = 0;

        while (actual != nullptr && i < index) {
            actual = actual->siguiente;
            i++;
        }

        if (actual != nullptr) {
            return actual->dato;
        }
        else {
            throw out_of_range("Índice fuera de rango");
        }
    }

    void eliminar(int index) {
        if (index < 0) {
            throw out_of_range("Índice negativo no válido");
        }

        if (index == 0 && cabeza != nullptr) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            if (cabeza == nullptr) {
                fin = nullptr;
            }
            return;
        }

        Nodo<T>* actual = cabeza;
        int i = 0;
        while (actual != nullptr && i < index - 1) {
            actual = actual->siguiente;
            i++;
        }

        if (actual != nullptr && actual->siguiente != nullptr) {
            Nodo<T>* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            if (actual->siguiente == nullptr) {
                fin = actual;
            }
            delete temp;
        }
        else {
            throw out_of_range("Índice fuera de rango");
        }
    }

    int obtenerTamano() {
        int tamaño = 0;
        Nodo<T>* temp = cabeza;
        while (temp) {
            tamaño++;
            temp = temp->siguiente;
        }
        return tamaño;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }
};
