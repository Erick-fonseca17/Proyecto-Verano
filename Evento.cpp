#include "Evento.h"
#include "Segmento.h"

Evento::Evento() {
    segmentos = nullptr;
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

// Configura el evento
void Evento::configurarEvento() {
    cout << "------------------------------- CONFIGURACION DEL EVENTO -------------------------------\n";
    cout << endl;
    cout << "\nIngrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);
    cout << "\nIngrese la cantidad de segmentos: ";
    cin >> numeroSegmento;
    cout << endl;

    if (numeroSegmento <= 0) {
        cout << "ERROR: El numero de segmentos debe ser mayor a 0 \n";
        return;
    }
    delete[] segmentos;

    segmentos = new Segmento[numeroSegmento];
    for (int i = 0; i < numeroSegmento; i++) {
        cout << "\nIngrese los datos del segmento #" << i + 1 << ":\n";
        segmentos[i].preguntarDatos();
    }
    system("CLS");
}

void Evento::generarFactura() {
    float totalPagar = 0;
    cout << "------------------------- FACTURA -------------------------\n";
    cout << "Evento: " << nombreEvento << "\n";
    cout << "Comprador: " << venta.getNombreCliente() << "\n";
    cout << "Cedula: " << venta.getCedulaCliente() << "\n";
    cout << "Fecha Nacimiento: " << venta.getFechaNacimiento() << "\n";

    cout << "Desglose de las entradas vendidas:\n";

    for (int i = 0; i < numeroSegmento; i++) {
        int entradas = segmentos[i].getEntradasPorUsuario();
        float precioSegmento = segmentos[i].getPrecio();

        float subtotal = entradas * precioSegmento;

        cout << "Segmento #" << i + 1 << ":\n";
        cout << "  Entradas vendidas: " << segmentos[i].getEntradasPorUsuario() << "\n";
        cout << "  Precio por entrada: " << precioSegmento << " colones\n";
        cout << "  Subtotal: " << subtotal << " colones\n";
        segmentos[i].inicializarEntradasPorUsurio();

        totalPagar += subtotal;
    }

    cout << "\nTOTAL A PAGAR: " << totalPagar << " colones\n";
    cout << "----------------------------------------------------------\n";

}

void Evento::venderEntradas() {

    int contadorEspacios = 0;
    char continuaComprando;
    int segmentoSeleccionado;

    if (!segmentos) {
        cout << "\nATENCION: Primero configure el evento.\n";
        cout << endl;
        return;
    }

    venta.preguntarDatos();
    cantidadPersonas++;
    cout << "\nATENCION: Puede comprar un maximo de 5 espacios.\n";
    cout << endl;

    do {

        imprimirEstadoDeVentas();

        bool seleccionValida = false;

        while (!seleccionValida) {
            cout << "\nSeleccione el segmento (1-" << numeroSegmento << "): ";
            cin >> segmentoSeleccionado;


            if (segmentoSeleccionado < 1 || segmentoSeleccionado > numeroSegmento) {
                cout << "\nSegmento invalido. Intentelo de nuevo.\n";
                continue;
            }


            if (segmentos[segmentoSeleccionado - 1].verificarEstadodeEntradas()) {
                cout << "\nEl segmento seleccionado esta lleno. Intente con otro segmento.\n";
                continue;
            }

            seleccionValida = true;
        }

        segmentos[segmentoSeleccionado - 1].seleccionarEspacio();
        contadorEspacios++;

        string digitarContrasenia;
        bool descuentoExitoso = false;

        for (int i = 0; i < 5; i++)
        {
            if (cantidadPersonas <= descuento.getCantidad()) {


                cout << "\nContrasenia para validar el descuento: " << descuento.getContrasenia() << endl;

                cout << "\nDigite la contrasenia para validar la compra: " << endl;
                cin.ignore();
                getline(cin, digitarContrasenia);

                if (digitarContrasenia == descuento.getContrasenia()) {

                    descuento.confirmarDescuento(segmentos[segmentoSeleccionado - 1].getPrecio());
                    cout << "\nValor de la entrada con descuento: " << descuento.aplicarDescuento() << endl << endl;
                    descuentoExitoso = true;
                    break;
                }
                else {
                    cout << "\nContrasenia incorrecta, vuelva a intentar.\n";
                    break;
                }

            }
        }

        if (!descuentoExitoso) {
            cout << "\nNo se aplico ningun descuento.\n";
        }

        contadorEspacios++;
        if (contadorEspacios < 5) {
            cout << "\nDesea seguir comprando (s/n):\n ";
            cin >> continuaComprando;
            system("CLS");
        }
        else {
            cout << "\nHa alcanzado el máximo de 5 entradas permitidas.\n";
            break;
        }

        descuento.generarContrasenia();

    } while (continuaComprando == 's' || continuaComprando == 'S');

    cout << "\nTotal de entradas compradas: " << contadorEspacios << ".\n";
    generarFactura();

}

void Evento::imprimirInformacionEvento()
{
    //Aplicar restriccion si todavia no se han creado los segmentos
    cout << "\n-------------------------------- RESUMEN DE LA IMFORMACION DEL EVENTO -------------------------------- \n";
    cout << "Evento: " << nombreEvento << "\n";
    for (int i = 0; i < numeroSegmento; i++) {
        cout << "Segmento #" << i + 1 << ": \n";
        cout << segmentos[i].getCantidadEspacios() << " espacios (" << segmentos[i].getFila() << " filas x " << segmentos[i].getColumna() << " columnas)\n" << endl;
        cout << "El precio por espacio es de: " << segmentos[i].getPrecio();
        cout << endl << endl;
    }

}

void Evento::imprimirEstadoDeVentas()
{
    if (!segmentos) {
        cout << "\nATENCION: Primero configure el evento.\n";
        cout << endl;
        return;
    }

    cout << "---------------------- ESTADO DE VENTAS ----------------------\n";
    cout << endl;
    cout << "Evento: " << nombreEvento << "\n";
    for (int i = 0; i < numeroSegmento; i++) {
        cout << "\nSegmento " << i + 1 << ":\n";
        cout << "\nPrecio del Evento: " << segmentos[i].getPrecio() << endl;
        cout << endl;
        segmentos[i].mostrarEspacios();
    }
}


void Evento::menu()
{
    bool entrar = true;

    while (entrar) {

        int opcion = 0;
        cout << "\nOpciones para creacion del Evento\n";
        cout << "#1 Configuracion de evento\n";//Listo, solo falta hacer restricciones
        cout << "#2 Configurar descuentos\n"; //Erick
        cout << "#3 Venta de entradas\n";
        cout << "#4 Consultar estado de ventas\n";
        cout << "#5 Acerca de los creadores\n";
        cout << "#6 OPCION SALIR\n";

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
            //Funcion de creacion de descuento
            descuento.IngresarDatosdelEvento();
            break;

        case 3:
            venderEntradas();

            break;
        case 4:
            //Presentacion grafica de la venta de entadas.No es la version final, es un borrador de lo que quiero
            imprimirEstadoDeVentas();
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