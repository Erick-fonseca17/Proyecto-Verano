#include "Lista.h"

Lista::Lista(float elem):elemento(elem),cabeza(nullptr), cola(nullptr) {}

 Lista:: ~Lista() {
     while (cabeza) {
         Nodo* temp = cabeza;
         cabeza = cabeza->siguiente;
         delete temp;
     }
     cola = nullptr;
 }


 void Lista:: insertarInicio()
 {
     Nodo* nuevoNodo = new Nodo(elemento);

     if (cabeza) {
         cabeza->anterior = nuevoNodo;
     }
     else {
         cola = nuevoNodo;
     }
     cabeza = nuevoNodo;
 }

 
 void Lista::insertarFinal()
 {
     Nodo* nuevoNodo = new Nodo(elemento);
     if (cola) {
         cola->siguiente = nuevoNodo;
     }
     else {
         cabeza = nuevoNodo;
     }
     cola = nuevoNodo;

 }

 Lista::Nodo* Lista::buscarElemento()
 {
     Nodo* actual = cabeza;

     while (actual) {

         if (actual->valor == elemento) {

             return actual;
         }

         actual = actual->siguiente;
     }

     return nullptr;
 }

 bool Lista::eliminarElemento()
 {
     if (cabeza->valor == elemento) {

         Nodo* aux = cabeza;
         cabeza = cabeza->siguiente;
         delete aux;
         return true;
     }

     Nodo* elementoActual = cabeza;
     while (elementoActual->siguiente) {

         if (elementoActual->siguiente->valor == elemento) {

             Nodo* aux = elementoActual->siguiente;
             elementoActual->siguiente = elementoActual->siguiente->siguiente;
             delete aux;
             return true;
         }
         elementoActual = elementoActual->siguiente;
     }

     return false;
 }

 void Lista ::mostratLista()
 {
     Nodo* actual = cabeza;
     while (actual) {
         cout << actual->valor << " ";
         actual = actual->siguiente;
     }
     cout << endl;
 }

