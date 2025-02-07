#pragma once
#include <string>
#include <iostream>
#include "Segmento.h"
#include "Cliente.h"
#include "Descuento.h"

using namespace std;

class Evento
{
private:
    Lista<Segmento> segmentos;
    string nombreEvento;
    Cliente cliente;
    Descuento descuento;
    int cantidadPersonas;
    int segmentoSeleccionado;
    bool descuentoAceptado = false;
    bool noHaySegmentos = false;
    int numeroSegmento = 0;

public:
    Evento();
    ~Evento();
    string getNombreEvento();
    void configurarEvento();
    void venderEntradas();
    void gestionarCompra();
    int seleccionarSegmento();
    bool procesarDescuento();
    void imprimirInformacionEvento();
    void generarFactura();
    void imprimirEstadoDeVentas();
    void infoEstudiantes();
    void mostrarLogo();
    void menu();

};