#include "Segmento.h"

Segmento::Segmento() {
    cantidadEspacios = 0;
    fila = 0;
    columna = 0;
    valorEntrada = 0;
    espacios = nullptr;
}

Segmento::~Segmento() {
    if (espacios != nullptr) {
        for (int i = 0; i < fila; ++i) {
            delete[] espacios[i];
        }
        delete[] espacios;
    }
}

void Segmento::setValorEntrada(int valorEntrada)
{
    this->valorEntrada = valorEntrada;
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

int Segmento::getValorEntrada()
{
    return valorEntrada;
}

// Inicializa la matriz dinámica
void Segmento::inicializarMatriz() { 
    if (espacios != nullptr) {
        for (int i = 0; i < fila; ++i) {
            delete[] espacios[i];
        }
        delete[] espacios;
    }

    espacios = new int* [fila];
    for (int i = 0; i < fila; ++i) {
        espacios[i] = new int[columna];
        for (int j = 0; j < columna; ++j) {
            espacios[i][j] = 0; // Inicializar como disponibles
        }
    }
}

// Configura el segmento
void Segmento::preguntarEspacios() {
    
    cout << "\nPrecio de la entrada del Segmento: ";
    cin >> valorEntrada;
    cout << "Filas: ";
    cin >> fila;
    cout << "Columnas: ";
    cin >> columna;

    setCantidadEspacios(fila * columna);
    inicializarMatriz();

    cout << "\nLa cantidad de espacios de su segmento es de: " << cantidadEspacios << endl;
    cout << "Valor de la entrada: " << valorEntrada << endl;
    cout << endl;
}
 
// Permite reservar un asiento
void Segmento::seleccionarEspacio() {
    int numeroFila, numeroColumna;
    cout << "Digite el numero de fila que desea (0-" << fila - 1 << "): ";//Cambiar para que empiece en 1 o como A1
    cin >> numeroFila;
    cout << "Digite el numero de columna que desea (0-" << columna - 1 << "): ";
    cin >> numeroColumna;

    // Validar límites
    if (numeroFila < 0 || numeroFila >= fila || numeroColumna < 0 || numeroColumna >= columna) {
        cout << "Error: Posicion fuera de los limites.\n";
        return;
    }

    // Verificar disponibilidad
    if (espacios[numeroFila][numeroColumna] == 1) {
        cout << "El espacio ya está ocupado. Por favor, elija otro.\n";
    }
    else {
        // Marcar como ocupado
        espacios[numeroFila][numeroColumna] = 1;
        cout << "Asiento reservado exitosamente en la fila " << numeroFila << ", columna " << numeroColumna << ".\n";

        
    }
}

// Muestra el estado actual del segmento
void Segmento::mostrarEspacios() {

    cout << "\nEstado de los asientos (1 = ocupado, 0 = disponible):\n";
    for (int i = 0; i < fila; ++i) {
        for (int j = 0; j < columna; ++j) {
            cout << espacios[i][j] << " ";
            
        }
        cout << endl;
    }
}