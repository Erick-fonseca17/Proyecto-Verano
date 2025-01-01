#pragma once
#include <iostream>
using namespace std;

class Segmento {
private:
    int cantidadEspacios;
    int fila;
    int columna;
    int valorEntrada;
    int** espacios; // 1 = ocupado, 0 = disponible

public:
    Segmento();
    ~Segmento();

    void setValorEntrada(int valorEntrada);
    void setCantidadEspacios(int cantidadEspacios);
    void setFila(int fila);
    void setColumna(int columna);
    int getCantidadEspacios();
    int getFila();
    int getColumna();
    int getValorEntrada();

    void inicializarMatriz();
    void preguntarEspacios();
    void seleccionarEspacio();
    void mostrarEspacios();
};
