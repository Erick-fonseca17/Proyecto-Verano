#include "Segmento.h"

Segmento::Segmento() {
    cantidadEspacios = 0;
    fila = 0;
    columna = 0;
    precio = 0;
    espacios = NULL;
    entradasVendidas = 0;
    entradasPorUsuario = 0;
}

Segmento::~Segmento() {
    if (espacios != NULL) {
        for (int i = 0; i < fila; i++) {
            delete[] espacios[i];
        }
        delete[] espacios;
    }
}

void Segmento::setPrecio(float precio)
{
    this->precio = precio;
}

void Segmento::setCantidadEspacios(int cantidadEspacios) {
    this->cantidadEspacios = cantidadEspacios;
}

void Segmento::setFila(int fila) {
    this->fila = fila;
}

void Segmento::setColumna(int columna) {
    this->columna = columna;
}

int Segmento::getCantidadEspacios() {
    return cantidadEspacios;
}

int Segmento::getFila() {
    return fila;
}
int Segmento::getColumna() {
    return columna;
}

int Segmento::getPrecio()
{
    return precio;
}

int Segmento::getEntradasVendidas()
{
    return entradasVendidas;
}

int Segmento::getEntradasPorUsuario()
{
    return entradasPorUsuario;
}

void Segmento::inicializarEntradasPorUsurio()
{
    entradasPorUsuario = 0;
}

void Segmento::inicializarMatriz() {
    if (espacios != NULL) {
        for (int i = 0; i < fila; i++) {
            delete[] espacios[i];
        }
        delete[] espacios;
    }

    espacios = new char* [fila];
    for (int i = 0; i < fila; i++) {
        espacios[i] = new char[columna];
        for (int j = 0; j < columna; j++) {
            espacios[i][j] = 'D';
        }
    }
}

void Segmento::preguntarDatos() {
    cout << "Filas: ";
    cin >> fila;
    cout << "Columnas: ";
    cin >> columna;
    cout << "Precio de cada espacio en colones: ";
    cin >> precio;

    setCantidadEspacios(fila * columna);
    inicializarMatriz();
}

bool Segmento::verificarEstadodeEntradas()
{
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {

            if (espacios[i][j] != 'V') {

                return false;
            }
        }
    }

    return true;
}


void Segmento::seleccionarEspacio() {
    int numeroFila;
    int numeroColumna;
    int contadorEspacios = 0;
    char letraFila;
    bool validacion = false;

    do {

        cout << "\nDigite la letra de la fila que desea (A-" << static_cast<char>('A' + fila - 1) << "): ";
        cin >> letraFila;
        cout << "\nDigite el numero de silla que desea (1-" << columna << "): ";
        cin >> numeroColumna;


        numeroFila = static_cast<int>(toupper(letraFila) - 'A');
        numeroColumna -= 1;

        if (numeroFila < 0 || numeroFila >= fila || numeroColumna < 0 || numeroColumna >= columna) {
            cout << "\nError: Posicion fuera de los limites.\n";
            continue;

        }

        if (espacios[numeroFila][numeroColumna] == 'V') {
            cout << "\nEl espacio ya esta ocupado. Por favor, elija otro.\n";
            continue;
        }

        validacion = true;
        espacios[numeroFila][numeroColumna] = 'V';
        entradasVendidas++;
        cout << "\nAsiento reservado exitosamente en la fila " << letraFila << ", columna " << numeroColumna + 1 << ".\n";
        entradasPorUsuario++;

    } while (!validacion);


}


void Segmento::mostrarEspacios() {
    cout << "Estado de los asientos (V = vendida, D = disponible):\n";
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (espacios[i][j] == 'V') {
                cout << " [ ";
                cout << "\033[0;31m";
                cout << espacios[i][j];
                cout << "\033[0m";
                cout << " ] ";
            }
            else {
                cout << " [ ";
                cout << "\033[0;32m";
                cout << espacios[i][j];
                cout << "\033[0m";
                cout << " ] ";
            }
        }
        cout << endl;
    }
}