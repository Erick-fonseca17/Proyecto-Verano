#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <iostream>
using namespace std;

class Segmento {
private:
    int fila;
    int columna;
    float precio;
    char** espacios;
    int entradasVendidas;
    int entradasPorUsuario;

    void liberarMatriz();
    void copiarDesde(const Segmento& otro);

public:
    Segmento();
    ~Segmento();
    Segmento(const Segmento& otro);
    Segmento& operator=(const Segmento& otro);

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

#endif 
