#include "Evento.h"

Evento::Evento() {
    segmentos = nullptr;
    numeroSegmento = 0;
    nombreEvento = "";
}

Evento::~Evento() {
    delete[] segmentos;
}

// Configura el evento
void Evento::cantidadSegmento() {
    cout << "------------------------------- CONFIGURACION DEL EVENTO -------------------------------\n";
    cout << endl;
    cout << "Ingrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);
    cout << "Ingrese la cantidad de segmentos: ";
    cin >> numeroSegmento;
    cout << endl;

    if (numeroSegmento <= 0) {
        cout << "ERROR: El numero de segmentos debe ser mayor a 0 \n";
        return;
    }

    delete[] segmentos;

    segmentos = new Segmento[numeroSegmento];

    for (int i = 0; i < numeroSegmento; ++i) {
        cout << "Ingrese los datos del segmento #" << i + 1 << ":\n";
        segmentos[i].preguntarEspacios();
    }
}

// Permite seleccionar entradas
void Evento::seleccionDeEntradas()
{ //CAMBIAR NOMBRE A "VENDER ENTRADAS"
    if (!segmentos) {
        cout << "ANTENCION: Primero configure el evento. \n";
        cout << endl;
        return;
    }
    venta.preguntarDatos();

    cantidadPersonas++; 

    char continuaComprando;
    do {

        imprimirEstadoDeVentas(); 

        cout <<endl<< "Seleccione el segmento (1-" << numeroSegmento << "): ";
        cin >> segmentoSeleccionado;
        descuentos();

        if (segmentoSeleccionado < 1 || segmentoSeleccionado > numeroSegmento) {
            cout << "Segmento inválido. Inténtelo de nuevo.\n";
            return;
        }
        segmentos[segmentoSeleccionado - 1].seleccionarEspacio();

        cout << "Valor de la entrada con descuento: " << descuento.aplicarDescuento() << endl<<endl;

        cout << "Desea seguir comprando? (s/n)";
        cin >> continuaComprando;
    } while (continuaComprando == 's');

}

void Evento::descuentos()
{

   descuento.confirmarDescuento(cantidadPersonas, segmentos[segmentoSeleccionado-1].getValorEntrada());

}

void Evento::imprimirInformacionEvento() //Dice la cantidad de espacios , filas y columnas
{
    //Aplicar restriccion si todavia no se han creado los segmentos
    cout << "Evento: " << nombreEvento << "\n";
    for (int i = 0; i < numeroSegmento; i++) {
        cout << "Segmento " << i + 1 << ": "
            << segmentos[i].getCantidadEspacios() << " espacios ("
            << segmentos[i].getFila() << " filas x "
            << segmentos[i].getColumna() << " columnas)\n";
    }

}

// Muestra el estado del evento
void Evento::imprimirEstadoDeVentas() {
    cout << "---------------------- ESTADO DE VENTAS ----------------------\n";
    cout << endl;
    cout << "Evento: " << nombreEvento << "\n";
    for (int i = 0; i < numeroSegmento; ++i) {
        cout << "\nSegmento " << i + 1 << ":\n";
        cout << endl;
        cout << "Valor de la entrada: " << segmentos[i].getValorEntrada() << endl;
       
        segmentos[i].mostrarEspacios();
    }
}


void Evento::menu()
{
    bool entrar = true;

    while (entrar) {

        int opcion = 0;
        cout << "\nOpciones para creacion del Evento\n";
        cout << "#1 Configuracion de evento\n";//Listo, solo falta hhacer restricciones
        cout << "#2 Configurar descuentos\n"; //Erick
        cout << "#3 Venta de entradas\n";
        cout << "#4 Factura de la Compra\n";
       
       // cout << "# Acerca de los creadores\n";
        cout << "#6 OPCION SALIR\n";

        cout << "Digite la opcion que desea usar" << " : \n";
        cin >> opcion;
        system("CLS");
        switch (opcion)
        {

        case 1:

            cantidadSegmento();
            imprimirInformacionEvento();
            cout << "\n";
            cout << "\n";
            break;
        case 2:
            //Funcion de creacion de descuento
            descuento.IngresarDatosdelEvento();
            break;
        case 3:
            seleccionDeEntradas();

            break;
        case 4:
            //Presentacion grafica de la venta de entadas.No es la version final, es un borrador de lo que quiero
            //imprimirEstadoDeVentas();
            break;
        case 5:
            //Presentacion de los estudiantes creadores de proyecto

            break;

        case 6:
            entrar = false;
            break;
        }

    }
}