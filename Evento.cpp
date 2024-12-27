#include "Evento.h"

Evento::Evento()
{
    segmentos = nullptr;
    numeroSegmento = 0;
    cantidadEspacios = 0;
}

void Evento::cantidadSegmento()
{
    cout << "Ingrese el nombre del evento: " << endl;
    cin.ignore();
    getline(cin, NombreEvento);
    cout << "Ingrese la cantidad de segmentos: ";
    cin >> numeroSegmento;
    if (numeroSegmento <= 0) {
        cout << "Error: El número de segmentos debe ser mayor a 0.\n";
        return;
    }


    delete[] segmentos;
    segmentos = new Segmento[numeroSegmento];


    for (int i = 0; i < numeroSegmento; i++) {
        cout << "Ingrese los datos del segmento: #" << i + 1 << endl;
        segmentos[i].preguntarEspacios();
    }
}

void Evento::seleccionDeEntradas()
{
    int entradas = 0;
    cout << "Digite la cantidad de entradas que desea comprar: " << endl;
    cin >> entradas;
    for (int i = 0; i < entradas; i++) {


    }
}

void Evento::imprimirInformacionEvento()
{
    cout << "Evento: " << NombreEvento << "\n";
    for (int i = 0; i < numeroSegmento; i++) {
        cout << "Segmento " << i + 1 << ": "
            << segmentos[i].getCantidadEspacios() << " espacios ("
            << segmentos[i].getFila() << " filas x "
            << segmentos[i].getColumna() << " columnas)\n";
    }

}

void Evento::menu()
{
    bool entrar = true;

    while (entrar) {

        int opcion = 0;
        cout << "Opciones para creacion del Evento\n";
        cout << "#1 Configuracion de evento\n";
        cout << "#2 Venta de entradas\n";
        cout << "#3 Obtener Contrasenia\n";
        cout << "#4 Aplicacion de Descuento\n";
        cout << "#9 OPCION SALIR\n";
        cout << "Digite la opcion que desea usar" << " : \n";
        cin >> opcion;
        system("CLS");

        switch (opcion)
        {

        case 1:
            cantidadSegmento();
            cout << "\n";
            cout << "\n";
            break;
        case 2:
            venta.preguntarDatos(); // Llamada al método de la clase Venta
            imprimirInformacionEvento();
            break;
            
        case 3:
            descuento.obtenerContrasenia();
            break;
        case 4:
           // descuento.mostrarDetallesdelDescuento();
            break;
        case 9:
            entrar = false;
            break;
        }

    }
}