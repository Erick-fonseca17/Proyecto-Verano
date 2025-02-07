#pragma once
#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
    string dato;
    Nodo* siguiente;

    Nodo(string d) : dato(d), siguiente(nullptr) {}
};