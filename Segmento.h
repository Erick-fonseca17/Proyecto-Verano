#pragma once
#include <iostream>
using namespace std;

class Segmento {
private:
    int fila;  
    int columna;
    char** espacios; // V = vendida, D = disponible
    float precio;
    int entradasVendidas;
    int entradasPorUsuario;


public:
    Segmento();
    ~Segmento();

    void setPrecio(float precio);
    void setFila(int fila);
    void setColumna(int columna);
    int getFila();
    int getColumna();
    float getPrecio();
    int getEntradasVendidas();
    int getEntradasPorUsuario();
    void inicializarEntradasPorUsurio();

    void inicializarMatriz();
    void preguntarDatos();
    bool verificarEstadodeEntradas();
    void seleccionarEspacio();
    void mostrarEspacios();
};