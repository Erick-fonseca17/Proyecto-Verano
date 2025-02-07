#include "Segmento.h"

// Constructor
Segmento::Segmento() {
    fila = 0;
    columna = 0;
    precio = 0;
    espacios = nullptr;
    entradasVendidas = 0;
    entradasPorUsuario = 0;
}

// Destructor
Segmento::~Segmento() {
    liberarMatriz();
}

// Constructor de copia
Segmento::Segmento(const Segmento& otro) {
    copiarDesde(otro);
}

// Operador de asignación
Segmento& Segmento::operator=(const Segmento& otro) {
    if (this != &otro) {
        liberarMatriz();  // Liberar la memoria anterior
        copiarDesde(otro); // Copiar desde el otro objeto
    }
    return *this;
}

// Métodos setters y getters
void Segmento::setPrecio(float precio) { this->precio = precio; }
void Segmento::setFila(int fila) { this->fila = fila; }
void Segmento::setColumna(int columna) { this->columna = columna; }
int Segmento::getFila() { return fila; }
int Segmento::getColumna() { return columna; }
float Segmento::getPrecio() { return precio; }
int Segmento::getEntradasVendidas() { return entradasVendidas; }
int Segmento::getEntradasPorUsuario() { return entradasPorUsuario; }
void Segmento::inicializarEntradasPorUsurio() { entradasPorUsuario = 0; }

// Inicialización de la matriz de asientos
void Segmento::inicializarMatriz() {
    liberarMatriz(); // Evita fugas de memoria antes de asignar nueva memoria

    if (fila <= 0 || columna <= 0) {
        cout << "Error: Las dimensiones de la matriz deben ser mayores a 0." << endl;
        return;
    }

    espacios = new char* [fila];
    for (int i = 0; i < fila; i++) {
        espacios[i] = new char[columna];
        for (int j = 0; j < columna; j++) {
            espacios[i][j] = 'D'; // Inicializar como disponible
        }
    }
}

// Pedir datos al usuario con validaciones
void Segmento::preguntarDatos() {
    cout << "Filas: ";
    cin >> fila;
    cout << "Columnas: ";
    cin >> columna;
    cout << "Precio de cada espacio en colones: ";
    cin >> precio;

    if (fila <= 0 || columna <= 0) {
        cout << "Error: Filas y columnas deben ser mayores a 0." << endl;
        return;
    }

    inicializarMatriz();
}

// Verifica si todas las entradas han sido vendidas
bool Segmento::verificarEstadodeEntradas() {
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (espacios[i][j] != 'V') {
                return false;
            }
        }
    }
    return true;
}

// Selección de espacio con validaciones
void Segmento::seleccionarEspacio() {
    if (!espacios) {
        cout << "Error: No se ha inicializado la matriz de espacios." << endl;
        return;
    }

    int numeroFila, numeroColumna;
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
            cout << "\nError: Posición fuera de los límites.\n";
            continue;
        }

        if (espacios[numeroFila][numeroColumna] == 'V') {
            cout << "\nEl espacio ya está ocupado. Por favor, elija otro.\n";
            continue;
        }

        validacion = true;
        espacios[numeroFila][numeroColumna] = 'V';
        entradasVendidas++;
        entradasPorUsuario++;

        cout << "\nAsiento reservado exitosamente en la fila " << letraFila << ", columna " << numeroColumna + 1 << ".\n";
    } while (!validacion);
}

// Mostrar estado de los asientos
void Segmento::mostrarEspacios() {
    if (!espacios) {
        cout << "Error: No se ha inicializado la matriz de espacios." << endl;
        return;
    }

    cout << "Estado de los asientos (V = vendida, D = disponible):\n";
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (espacios[i][j] == 'V') {
                cout << " [ \033[0;31mV\033[0m ] "; // Rojo para vendidos
            }
            else {
                cout << " [ \033[0;32mD\033[0m ] "; // Verde para disponibles
            }
        }
        cout << endl;
    }
}

// Liberar memoria de la matriz
void Segmento::liberarMatriz() {
    if (espacios) {
        for (int i = 0; i < fila; i++) {
            delete[] espacios[i];
        }
        delete[] espacios;
        espacios = nullptr;
    }
}

// Copiar matriz desde otro objeto
void Segmento::copiarDesde(const Segmento& otro) {
    fila = otro.fila;
    columna = otro.columna;
    precio = otro.precio;
    entradasVendidas = otro.entradasVendidas;
    entradasPorUsuario = otro.entradasPorUsuario;

    if (otro.espacios) {
        espacios = new char* [fila];
        for (int i = 0; i < fila; i++) {
            espacios[i] = new char[columna];
            for (int j = 0; j < columna; j++) {
                espacios[i][j] = otro.espacios[i][j];
            }
        }
    }
    else {
        espacios = nullptr;
    }
}