#include "Evento.h"
#include "Segmento.h"

Evento::Evento() {
    segmentos = NULL;
    numeroSegmento = 0;
    cantidadEspacios = 0;
    nombreEvento = "";
    cantidadPersonas = 0;
    segmentoSeleccionado = 0;
}

Evento::~Evento() {
    delete[] segmentos;
}

string Evento::getNombreEvento()
{
    return nombreEvento;
}

void Evento::configurarEvento() {
    cout << "\033[0;33m";
    cout << "------------------------------- CONFIGURACION DEL EVENTO -------------------------------\n\n";
    cout << "\033[0m";
    cout << "\nIngrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);
    cout << "\nIngrese la cantidad de segmentos: ";
    cin >> numeroSegmento;
    cout << endl;

    if (numeroSegmento <= 0) {
        cout << "ERROR: El numero de segmentos debe ser mayor a 0 \n";
    }
    else {
        delete[] segmentos;

        segmentos = new Segmento[numeroSegmento];
        for (int i = 0; i < numeroSegmento; i++) {
            cout << "\nIngrese los datos del segmento #" << i + 1 << ":\n";
            segmentos[i].preguntarDatos();
        }
        system("CLS");
    }
}



//Aplicar descuento a la factura
void Evento::generarFactura() {
    float totalPagar = 0;
    int entradas = 0;
    float precioSegmento = 0.0;
    float subtotal = 0.0;
    cout << "\033[0;33m";
    cout << "------------------------- FACTURA -------------------------\n";
    cout << "\033[0m";
    cout << "Evento: " << nombreEvento << "\n";
    cout << "Comprador: " << venta.getNombreCliente() << "\n";
    cout << "Cedula: " << venta.getCedulaCliente() << "\n";
    cout << "Fecha Nacimiento: " << venta.getFechaNacimiento() << "\n";

    cout << "Desglose de las entradas vendidas:\n";
    for (int i = 0; i < numeroSegmento; i++) {
        entradas = segmentos[i].getEntradasPorUsuario();
        if (entradas > 0) {
            precioSegmento = segmentos[i].getPrecio();
            subtotal = entradas * precioSegmento;

            cout << "Segmento #" << i + 1 << ":\n";
            cout << "  Entradas vendidas: " << entradas << "\n";
            cout << "  Precio por entrada: " << precioSegmento << " colones\n";
            cout << "  Subtotal: " << subtotal << " colones\n";
            segmentos[i].inicializarEntradasPorUsurio();

            totalPagar += subtotal;
        }
    }

    descuento.confirmarDescuento(totalPagar);
    cout << "\nTOTAL A PAGAR: " << totalPagar << " colones\n";
    if (descuentoAceptado == true) {
        cout << "TOTAL A PAGAR CON DESCUENTO: " << descuento.aplicarDescuento() << " colones\n";
    }
    cout << "----------------------------------------------------------\n";
}

void Evento::venderEntradas() {
    if (!segmentos) {
        cout << "\033[0;31m";
        cout << "\nATENCION: Primero configure el evento\n\n";
        cout << "\033[0m";
        cout << endl;
    }
    else {
        venta.preguntarDatos();
       
        cout << "\033[0;31m";
        cout << "\nATENCION: Puede comprar un maximo de 5 espacios.\n";
        cout << "\033[0m";
        cout << endl;
        gestionarCompra();
    }
}

void Evento::gestionarCompra() {
    char continuaComprando;
    int contadorEspacios = 0;
   
    do {
        imprimirEstadoDeVentas();

        segmentoSeleccionado = seleccionarSegmento();
        segmentos[segmentoSeleccionado - 1].seleccionarEspacio();
        contadorEspacios++;

        if (contadorEspacios < 5) {
            cout << "\nDesea seguir comprando (s/n):\n ";
            cin >> continuaComprando;
            system("CLS");
        }
        else {
            cout << "\033[0;31m";
            cout << "\nHa alcanzado el maximo de 5 entradas permitidas \n";
            cout << "\033[0m";
            break;
        }

        
    } while (continuaComprando == 's' || continuaComprando == 'S');

    if (procesarDescuento(segmentoSeleccionado)) {
        cout << "\nEl descuento se aplico exitosamente.\n";
        descuentoAceptado = true; 
        cantidadPersonas++;
    }
    else {
        cout << "\nNo se aplico ningun descuento.\n";
        descuentoAceptado = false;
    }

   cout << "\nTotal de entradas compradas: " << contadorEspacios << ".\n";

    generarFactura();
}

int Evento::seleccionarSegmento() {
    bool seleccionValida = false;

    while (!seleccionValida) {
        cout << "\nSeleccione el segmento (1-" << numeroSegmento << "): ";
        cin >> segmentoSeleccionado;

        if (segmentoSeleccionado < 1 || segmentoSeleccionado > numeroSegmento) {
            cout << "\nSegmento invalido. Intentelo de nuevo \n";
            continue;
        }

        if (segmentos[segmentoSeleccionado - 1].verificarEstadodeEntradas()) {
            cout << "\nEl segmento seleccionado esta lleno.\n";


            if (numeroSegmento > 1) {
                cout << "\nIntente con otro segmento.\n";
            }
            else {

                cout << "\nNo hay mas espacios disponibles en el segmento.\n";
                generarFactura();
                return 0;
            }

            continue;
        }


        seleccionValida = true;
    }

    return segmentoSeleccionado;
}

bool Evento::procesarDescuento(int segmentoSeleccionado) {
    string digitarContrasenia;
    char aplicarDescuento;

    if (cantidadPersonas < descuento.getCantidad()) {


        do {
            cout << "\nDesea aplicar descuento (s/n): ";
            cin >> aplicarDescuento;

            bool contraseniaAceptada = false;

            if (aplicarDescuento == 's' || aplicarDescuento == 'S')
            {
                do {

                    string contrasenna = descuento.getContrasenia();
                    cout << "\nContrasenia para validar el descuento: " << contrasenna << endl;
                    cout << "\nDigite la contrasenia para validar la compra: ";
                    cin >> digitarContrasenia;

                    if (digitarContrasenia == contrasenna) {

                        cout << "\nValor total con descuento aplicado. " << endl;
                        contraseniaAceptada = true;
                        return true;
                        
                    }
                    else {
                        cout << "\nContrasenia incorrecta, vuelva a intentar.\n";
                    }

                } while (contraseniaAceptada == false);
            }

        } while (aplicarDescuento == 's' || aplicarDescuento == 'S');
    }

    return false;
}



void Evento::imprimirInformacionEvento()
{
    cout << "\033[0;33m";
    cout << "\n-------------------------------- RESUMEN DE LA IMFORMACION DEL EVENTO -------------------------------- \n";
    cout << "\033[0m";
    cout << "Evento: " << nombreEvento << "\n";
    for (int i = 0; i < numeroSegmento; i++) {
        cout << "Segmento #" << i + 1 << ": \n";
        cout << segmentos[i].getCantidadEspacios() << " espacios (" << segmentos[i].getFila() << " filas x " << segmentos[i].getColumna() << " columnas)\n" << endl;
        cout << "El precio por espacio es de: " << segmentos[i].getPrecio() << endl;
        cout << "------------------------------------------------------------------------------------------------------ \n";
        cout << endl << endl;
    }

}

void Evento::imprimirEstadoDeVentas()
{
    if (!segmentos) {
        cout << "\nATENCION: Primero configure el evento \n";
        cout << endl;
    }
    else {
        cout << "\033[0;33m";
        cout << "---------------------- ESTADO DE VENTAS ----------------------\n\n";
        cout << "\033[0m";
        cout << "Evento: " << nombreEvento << "\n";
        for (int i = 0; i < numeroSegmento; i++) {
            cout << "\nSegmento " << i + 1 << ":\n";
            cout << "\nPrecio del Evento: " << segmentos[i].getPrecio() << endl;
            cout << endl;
            segmentos[i].mostrarEspacios();
        }
    }
}

void Evento::infoEstudiantes()
{
    const char* brenda = R"( ____                     _            _               _ _            
| __ ) _ __ ___ _ __   _| | __ _     / \   __ _ _   _() | __ _ _ __ 
|  _ \| '/ _ \ '_ \ / ` |/ _` |   / _ \ / _` | | | | | |/ _` | '_|
| |) | | |  __/ | | | (| | (| |  / ___ \ (| | || | | | (| | |   
|/||  \|| ||\,|\,| //   \\, |\,|||\,|_|   
|  __|_  _ __  ___  ___  ___ __ _        |_/                      
| |_ / _ \| '_ \/ __|/ _ \/ __/ _` |                                  
|  | () | | | \__ \  _/ (| (_| |                                  
||  \/|| ||/\|\\,|                                  )";
    cout << "\033[0;35m";
    cout << brenda << endl;
    cout << "\033[0m";
    cout << "Numero de cedula:\n";
    cout << endl << endl << endl;

    const char* erick = R"( _____      _      _      _____                              
| ___| _() __| | __ |  ___|_  _ __  ___  ___  ___ __ _ 
|  | | '| |/ __| |/ / | | / _ \| '_ \/ __|/ _ \/ __/ _` |
| || |  | | (|   <  |  _| () | | | \__ \  _/ (| (_| |
|||  ||\||\\ ||  \/|| ||/\|\\,|
|  \/  | __ | | __ _                                       
| |\/| |/ _` | __/ _` |                                      
| |  | | (| | || (| |                                      
||  ||\,|\\,|                                      )";
    cout << "\033[0;34m";
    cout << erick << endl;
    cout << "\033[0m";
    cout << "Numero de cedula: \n";


}

void Evento::mostrarLogo()
{
    const char* logo = R"( _____                 _              _____          _   __        
| ___|   _____ _ __ | |_ ___  ___  |  __|   _ ___() /_/  _ __  
|  | \ \ / / _ \ ' \| _/ _ \/ __| | | | | | / _| |/ _ \| ' \ 
| |___ \ V /  _/ | | | || () \__ \ |  || || \__ \ | (_) | | | |
|| \/ \|| ||\\/|/ ||   \,|/|\/|| ||)";
    cout << "\033[0;32m";
    cout << logo;
    cout << "\033[0m";
}

void Evento::menu()
{
    bool entrar = true;
    mostrarLogo();
    cout << endl;
    while (entrar) {

        int opcion = 0;
        cout << "\nOpciones para el evento:\n\n";
        cout << "#1 Configuracion de evento\n";
        cout << "#2 Configurar descuentos\n";
        cout << "#3 Venta de entradas\n";
        cout << "#4 Consultar estado de ventas\n";
        cout << "#5 Acerca de los creadores\n";
        cout << "#6 OPCION SALIR\n\n";

        cout << "Digite la opcion que desea usar" << " : \n";
        cin >> opcion;
        system("CLS");
        switch (opcion)
        {

        case 1:


            configurarEvento();
            imprimirInformacionEvento();
            cout << "\n";
            cout << "\n";
            break;
        case 2:
            descuento.IngresarDatosdelEvento();
            break;

        case 3:
            venderEntradas();

            break;
        case 4:
            imprimirEstadoDeVentas();
            break;
        case 5:
            infoEstudiantes();
            break;
        case 6:
            entrar = false;
            break;
        }

    }
}