#include "Evento.h"
#include "Segmento.h"


Evento::Evento() {
    segmentos = NULL;
    numeroSegmento = 0;
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

void Evento::configurarEvento(RenderWindow& window, Font& font, Text& text) {
    int fila = 0;
    int columna = 0;
    float precio = 0;
    string ingresarNombreEvento = "";
    string ingresarSegmentos = "";
    int campoActivo = 0;  // 0: Nombre Evento, 1: Segmentos

    float campoWidth = 300.0f;
    float campoHeight = 30.0f;

    float centerX = (window.getSize().x - campoWidth) / 2;
    float centerY = (window.getSize().y - 2 * (campoHeight + 50)) / 3;

    // Campos de entrada de los datos
    RectangleShape campoNombreEvento(Vector2f(campoWidth, campoHeight));
    campoNombreEvento.setPosition(centerX, centerY);
    campoNombreEvento.setFillColor(Color(40, 40, 40));
    campoNombreEvento.setOutlineColor(Color::White);
    campoNombreEvento.setOutlineThickness(2); 

    RectangleShape inputSegmentosField(Vector2f(campoWidth, campoHeight));
    inputSegmentosField.setPosition(centerX, centerY + campoHeight + 50);
    inputSegmentosField.setFillColor(Color(40, 40, 40));
    inputSegmentosField.setOutlineColor(Color::White);
    inputSegmentosField.setOutlineThickness(2);

    RectangleShape saveButton(Vector2f(300, 50));
    saveButton.setPosition(centerX, centerY + 2 * (campoHeight + 60));
    saveButton.setFillColor(Color(50, 150, 50));
    saveButton.setOutlineColor(sf::Color::White);
    saveButton.setOutlineThickness(2);

    Text saveText("Guardar Evento", font, 24);
    saveText.setPosition(centerX + 50, centerY + 2 * (campoHeight + 60) + 10);
    saveText.setFillColor(Color::Black);

    text.setCharacterSize(18);
    text.setFillColor(Color::White);

    //Titulos
    Text titleNombreEvento("Digite el Nombre del Evento:", font, 18);
    titleNombreEvento.setPosition(centerX, centerY - 30);

    Text titleSegmentos("Digite la cantidad de Segmentos:", font, 18);
    titleSegmentos.setPosition(centerX, centerY + campoHeight + 10);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            // Detectar clics en los campos
            if (event.type == Event::MouseButtonPressed) {
                if (campoNombreEvento.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    campoActivo = 0;  // Cambiar a campo Nombre Evento
                }
                else if (inputSegmentosField.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    campoActivo = 1;  // Cambiar a campo Segmentos
                }
                else if (saveButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    // Guardar el evento
                    if (ingresarNombreEvento.empty() || ingresarSegmentos.empty()) {
                        text.setString("Todos los campos deben ser llenados!");
                        text.setPosition(50, 300);
                        window.draw(text);
                        window.display();
                        sleep(seconds(2));
                        continue;
                    }

                    nombreEvento = ingresarNombreEvento;
                    int numeroSegmentos = stoi(ingresarSegmentos);

                    if (numeroSegmentos <= 0) {
                        text.setString("ERROR: El número de segmentos debe ser mayor a 0");
                        text.setPosition(50, 300);
                        window.draw(text);
                        window.display();
                        sleep(seconds(2));
                        continue;
                    }

                }
            }

            window.clear();

            text.setString("Bienvenido a la configuración del evento");
            text.setPosition((window.getSize().x - text.getGlobalBounds().width) / 2, 20);
            window.draw(text);

            window.draw(titleNombreEvento);
            window.draw(titleSegmentos);

            if (campoActivo == 0) {
                campoNombreEvento.setFillColor(Color(100, 100, 100));
                inputSegmentosField.setFillColor(Color(40, 40, 40));
            }
            else if (campoActivo == 1) {
                inputSegmentosField.setFillColor(Color(100, 100, 100));
                campoNombreEvento.setFillColor(Color(40, 40, 40));
            }

            window.draw(campoNombreEvento);
            window.draw(inputSegmentosField);

            window.draw(saveButton);
            window.draw(saveText);

            text.setString(ingresarNombreEvento);
            text.setPosition(centerX + 10, centerY + 5);
            window.draw(text);

            text.setString(ingresarSegmentos);
            text.setPosition(centerX + 10, centerY + campoHeight + 55);
            window.draw(text);

            window.display();



        }
    }
}

void Evento::venderEntradas() {
    if (!segmentos) {
        cout << "\033[0;31m";
        cout << "\nATENCION: Primero configure el evento\n\n";
        cout << "\033[0m";
        cout << endl;
    }
    else {

        cliente.preguntarDatos();

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

        if (noHaySegmentos == false) {

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
        }


    } while (continuaComprando == 's' && noHaySegmentos == false || continuaComprando == 'S' && noHaySegmentos == false);

    if (procesarDescuento()) {
        cout << "\nDescuento aplicado correctamente.\n";
        descuentoAceptado = true;
        cantidadPersonas++;
    }
    else {
        cout << "\nNo se aplico el descuento.\n";
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
                noHaySegmentos = true;
            }

            if (noHaySegmentos == false) {

                continue;

            }

        }
        seleccionValida = true;
    }

    return segmentoSeleccionado;
}

bool Evento::procesarDescuento() {
    string digitarContrasenia;
    char aplicarDescuento;

    int cantidad = descuento.getCantidad();

    if (descuento.getCantidadPersonas() == true) {
        cantidadPersonas = 0;

        bool reinicioPersonas = false;
        descuento.setCantidadPersonas(reinicioPersonas);
    }

    if (cantidadPersonas < cantidad) {

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
    }

    return false;
}

void Evento::imprimirInformacionEvento()
{
    int cantidadEspacios = 0;
    cout << "\033[0;33m";
    cout << "\n-------------------------------- RESUMEN DE LA IMFORMACION DEL EVENTO -------------------------------- \n";
    cout << "\033[0m";
    cout << "Evento: " << nombreEvento << "\n";
    for (int i = 0; i < numeroSegmento; i++) {
        cantidadEspacios = segmentos[i].getFila() * segmentos[i].getColumna();
        cout << "Segmento #" << i + 1 << ": \n";
        cout << cantidadEspacios << " espacios (" << segmentos[i].getFila() << " filas x " << segmentos[i].getColumna() << " columnas)\n" << endl;
        cout << "El precio por espacio es de: " << segmentos[i].getPrecio() << endl;
        cout << "------------------------------------------------------------------------------------------------------ \n";
        cout << endl << endl;
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
    cout << "Comprador: " << cliente.getNombreCliente() << "\n";
    cout << "Cedula: " << cliente.getCedulaCliente() << "\n";
    cout << "Fecha Nacimiento: " << cliente.getFechaNacimiento() << "\n";

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

void Evento::mostrarFacturas()
{
    
    string validarcedula;

    cout << "Digite su numero de cedula: " << endl;
    cin >> validarcedula;


}

void Evento::imprimirEstadoDeVentas()
{
    string nombreArchivo = "estudiante.txt";
    ofstream archivoSalida;
    archivoSalida.open(nombreArchivo, ios::out);

    if (!segmentos) {
        cout << "\nATENCION: Primero configure el evento \n";
        cout << endl;
        archivoSalida << "\nATENCION: Primero configure el evento \n" << endl;
    }
    else {
        cout << "\033[0;33m";
        cout << "---------------------- ESTADO DE VENTAS ----------------------\n\n";
        cout << "\033[0m";
        cout << "Evento: " << nombreEvento << "\n";
        archivoSalida << "---------------------- ESTADO DE VENTAS ----------------------\n\n";
        archivoSalida << "Evento: " << nombreEvento << "\n";

        for (int i = 0; i < numeroSegmento; i++) {
            cout << "\nSegmento " << i + 1 << ":\n";
            cout << "\nPrecio del Evento: " << segmentos[i].getPrecio() << endl;
            cout << endl;

            archivoSalida << "\nSegmento " << i + 1 << ":\n";
            archivoSalida << "\nPrecio del Evento: " << segmentos[i].getPrecio() << endl;
            archivoSalida << endl;

            segmentos[i].mostrarEspacios();
        }
    }
}

void Evento::infoEstudiantes()
{
}

void Evento::menu(RenderWindow& window, Font& font) {
    bool entrar = true;

    Text titulo("Opciones para el evento", font, 30);
    titulo.setPosition(250, 50);
    titulo.setFillColor(Color::Cyan);

    Text texto;
    Text opciones[6];
    const string menuOpciones[] = {
        "1. Configuracion de evento",
        "2. Configurar descuentos",
        "3. Venta de entradas",
        "4. Consultar estado de ventas",
        "5. Acerca de los creadores",
        "6. Salir"
    };

    Color opcionColor(255, 255, 255);
    Color hoveredColor(255, 255, 0);

    for (int i = 0; i < 6; ++i) {
        opciones[i].setString(menuOpciones[i]);
        opciones[i].setFont(font);
        opciones[i].setCharacterSize(20);
        opciones[i].setPosition(250, 120 + (i * 40));
        opciones[i].setFillColor(opcionColor);
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseMoved) {
                for (int i = 0; i < 6; ++i) {
                    if (opciones[i].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                        opciones[i].setFillColor(hoveredColor);
                    }
                    else {
                        opciones[i].setFillColor(opcionColor);
                    }
                }
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 6; ++i) {
                    if (opciones[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        int opcion = i + 1;
                        switch (opcion) {
                        case 1:
                            texto.setFont(font);
                            texto.setCharacterSize(24);
                            texto.setFillColor(sf::Color::White);
                            configurarEvento(window, font, texto);
                            break;
                        case 2:
                            descuento.IngresarDatosdelEvento(window, font);
                            break;
                        case 3:
                            // venderEntradas();
                            break;
                        case 4:

                            break;
                        case 5:
                            //  infoEstudiantes();
                            break;
                        case 6:
                            entrar = false;
                            window.close();
                            break;
                        }
                    }
                }
            }
        }

        window.clear(Color(30, 30, 30));

        window.draw(titulo);
        for (int i = 0; i < 6; ++i) {
            window.draw(opciones[i]);
        }

        window.display();

        int opcion = -1;
        if (Keyboard::isKeyPressed(Keyboard::Num1)) opcion = 1;
        else if (Keyboard::isKeyPressed(Keyboard::Num2)) opcion = 2;
        else if (Keyboard::isKeyPressed(Keyboard::Num3)) opcion = 3;
        else if (Keyboard::isKeyPressed(Keyboard::Num4)) opcion = 4;
        else if (Keyboard::isKeyPressed(Keyboard::Num5)) opcion = 5;
        else if (Keyboard::isKeyPressed(Keyboard::Num6)) opcion = 6;

        if (opcion != -1) {
            switch (opcion) {
            case 1:
                texto.setFont(font);
                texto.setCharacterSize(24);
                texto.setFillColor(Color::White);
                configurarEvento(window, font, texto);
                break;
            case 2:

                break;
            case 3:
                // venderEntradas();
                break;
            case 4:

                break;
            case 5:
                //  infoEstudiantes();
                break;
            case 6:
                entrar = false;
                window.close();
                break;
            }
        }

        if (!entrar) break;
    }
}