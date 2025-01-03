#pragma once
#include <iostream>
using namespace std;

class Segmento {
private:
    int cantidadEspacios;
    int fila;
    int columna;
    char** espacios; // 1 = ocupado, 0 = disponible
    float precio;
    int entradasVendidas;

public:
    Segmento();
    ~Segmento();

    void setPrecio(int precio);
    void setCantidadEspacios(int cantidadEspacios);
    void setFila(int fila);
    void setColumna(int columna);
    int getCantidadEspacios();
    int getFila();
    int getColumna();
    int getPrecio();
    int getEntradasVendidas();

    void inicializarMatriz();
    void preguntarDatos();
    bool verificarEstadodeEntradas();
    void seleccionarEspacio();
    void mostrarEspacios();
};
