//#pragma once
//#include "Lista.h"
//
//template <typename T>
//Lista<T>::Lista() : cabeza(nullptr) {}
//
//template <typename T>
//Lista<T>::~Lista() { limpiar(); }
//
//template <typename T>
//void Lista<T>::insertar(T valor) {
//    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
//    if (!cabeza) {
//        cabeza = nuevoNodo;
//    }
//    else {
//        Nodo<T>* temp = cabeza;
//        while (temp->getSiguiente()) {
//            temp = temp->getSiguiente();
//        }
//        temp->setSiguiente(nuevoNodo);
//    }
//}
//
//template <typename T>
//void Lista<T>::eliminar(T valor) {
//    if (!cabeza) {
//        cout << "Lista vacia..." << endl;
//        return;
//    }
//    if (cabeza->getValor() == valor) {
//        Nodo<T>* temp = cabeza;
//        cabeza = cabeza->getSiguiente();
//        delete temp;
//        return;
//    }
//    Nodo<T>* temp = cabeza;
//    while (temp->getSiguiente() && temp->getSiguiente()->getValor() != valor) {
//        temp = temp->getSiguiente();
//    }
//    if (temp->getSiguiente()) {
//        Nodo<T>* nodoEliminar = temp->getSiguiente();
//        temp->setSiguiente(nodoEliminar->getSiguiente());
//        delete nodoEliminar;
//    }
//}
//
//template <typename T>
//void Lista<T>::imprimir() {
//    if (!cabeza) {
//        cout << "Lista vacia" << endl;
//        return;
//    }
//    Nodo<T>* temp = cabeza;
//    while (temp) {
//        cout << temp->getValor() << " ";
//        temp = temp->getSiguiente();
//    }
//    cout << endl;
//}
//
//template <typename T>
//Nodo<T>* Lista<T>::buscar(T valor) {
//    Nodo<T>* temp = cabeza;
//    while (temp) {
//        if (temp->getValor() == valor)
//            return temp;
//        temp = temp->getSiguiente();
//    }
//    return nullptr;
//}
//
//template <typename T>
//void Lista<T>::limpiar() {
//    while (cabeza) {
//        Nodo<T>* temp = cabeza;
//        cabeza = cabeza->getSiguiente();
//        delete temp;
//    }
//}