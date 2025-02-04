#include "Descuento.h"

Descuento::Descuento()
{
    porcentaje = 0;
    cantidad = 0;
    contrasenia = " ";
    srand(time(0));
}

void Descuento::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

void Descuento::setContrasenia(string contrasenia)
{
    this->contrasenia = contrasenia;
}

int Descuento::getCantidad()
{
    return cantidad;
}

int Descuento::getPorcentaje()
{
    return porcentaje;
}

string Descuento::getContrasenia()
{

    return contrasenia; 
}

string Descuento::generarContrasenia()
{

    string caracter;

    for (char c = '0'; c <= '9'; c++)
    {
        caracter += c;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        caracter += c;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        caracter += c;
    }
    caracter += "!@#$%^&*()";


    string contraseniaGenerada;

    for (int i = 0; i < 6; i++)
    {
        int indice = rand() % caracter.length();
        contraseniaGenerada += caracter[indice];
    }

    contrasenia = contraseniaGenerada;

    return contraseniaGenerada;

}

void Descuento::menuDescuento(RenderWindow& window, Font& font)
{
    window.clear();

    Text text("===== Configuracion de Descuentos =====", font, 20);
    text.setPosition(10, 10);
    window.draw(text);

    text.setString("1. Ingresar nuevo cupon");
    text.setPosition(10, 50);
    window.draw(text);

    text.setString("2. Eliminar cupon");
    text.setPosition(10, 90);
    window.draw(text);

    text.setString("3. Ver lista de cupones");
    text.setPosition(10, 130);
    window.draw(text);

    text.setString("4. Regresar al menu principal");
    text.setPosition(10, 170);
    window.draw(text);

    window.display();
}

//void Descuento::getDescuentos()
//{
//    if (descuentoConfigurado) {
//
//        char opcion;
//        cout << "Ya existe un descuento configurado:\n";
//        cout << "Porcentaje actual: " << porcentaje << "%, Cantidad de uso: " << cantidad << "\n";
//        cout << "Desea actualizar este descuento? (s/n): ";
//        cin >> opcion;
//       
//        if (opcion == 'n' || opcion == 'N') {
//            cout << "No se actualizara el descuento.\n";
//            return;
//        }
//        else {
//           
//            IngresarDatosdelEvento();
//            cantidadPersonasDescuento = true; 
//
//        }
//    }
//
//    else {
//        IngresarDatosdelEvento();
//        descuentoConfigurado = true;
//    }
//
//  
//}

void Descuento::IngresarDatosdelEvento(RenderWindow& window, Font& font) {

    Text title("Formulario de Descuento", font, 30);
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 10);
    title.setFillColor(Color::White);

    Text labelPorcentaje("Porcentaje de descuento (0-100):", font, 24);
    labelPorcentaje.setPosition(window.getSize().x / 2 - labelPorcentaje.getGlobalBounds().width / 2, 70);
    labelPorcentaje.setFillColor(Color::White);

    Text labelCantidad("Cantidad de personas:", font, 24);
    labelCantidad.setPosition(window.getSize().x / 2 - labelCantidad.getGlobalBounds().width / 2, 150);
    labelCantidad.setFillColor(Color::White);

    RectangleShape inputPorcentaje(sf::Vector2f(200, 30));
    inputPorcentaje.setPosition(window.getSize().x / 2 - 100, 110);
    inputPorcentaje.setFillColor(Color(40, 40, 40));
    inputPorcentaje.setOutlineColor(Color::White);
    inputPorcentaje.setOutlineThickness(2);

    RectangleShape inputCantidad(Vector2f(200, 30));
    inputCantidad.setPosition(window.getSize().x / 2 - 100, 190);
    inputCantidad.setFillColor(Color(40, 40, 40));
    inputCantidad.setOutlineColor(Color::White);
    inputCantidad.setOutlineThickness(2);

    RectangleShape saveButton(Vector2f(200, 50));
    saveButton.setFillColor(Color(50, 150, 50));
    saveButton.setPosition(window.getSize().x / 2 - 100, 265);
    saveButton.setOutlineColor(Color::White);
    saveButton.setOutlineThickness(2);

    Text saveText("Guardar", font, 24);
    saveText.setPosition(window.getSize().x / 2 - saveText.getGlobalBounds().width / 2, 275);
    saveText.setFillColor(Color::Black);

    String userInputPorcentaje, userInputCantidad;
    int activeInput = 0;

    vector<Text> couponTexts;  
    float couponTextYOffset = 330;  

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (inputPorcentaje.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    activeInput = 1;
                else if (inputCantidad.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    activeInput = 2;
                else
                    activeInput = 0;
            }

            if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b') {
                    if (activeInput == 1 && !userInputPorcentaje.isEmpty())
                        userInputPorcentaje.erase(userInputPorcentaje.getSize() - 1, 1);
                    else if (activeInput == 2 && !userInputCantidad.isEmpty())
                        userInputCantidad.erase(userInputCantidad.getSize() - 1, 1);
                }
                else if (event.text.unicode < 128) {
                    if (activeInput == 1)
                        userInputPorcentaje += event.text.unicode;
                    else if (activeInput == 2)
                        userInputCantidad += event.text.unicode;
                }
            }

            if (event.type == Event::MouseButtonPressed) {
                if (saveButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    try {
                        porcentaje = stof(userInputPorcentaje.toAnsiString());
                        cantidad = stoi(userInputCantidad.toAnsiString());

                        if (porcentaje < 0 || porcentaje > 100) {
                            throw out_of_range("El porcentaje debe estar entre 0 y 100.");
                        }
                        if (cantidad < 0) {
                            throw invalid_argument("La cantidad debe ser positiva.");
                        }

                        
                        couponTexts.clear();

                        for (int i = 0; i < cantidad; i++) {
                            string contra = generarContrasenia();
                            Text couponText("Cupon " + std::to_string(i + 1) + ": " + contra, font, 24);
                            couponText.setPosition(window.getSize().x / 2 - couponText.getGlobalBounds().width / 2, couponTextYOffset);
                            couponText.setFillColor(Color::White);
                            couponTexts.push_back(couponText);

                            couponTextYOffset += 30;  
                        }

                        
                        menuDescuento(window, font);

                       
                        bool menuActivo = true;
                        while (menuActivo) {
                            Event menuEvent;
                            while (window.pollEvent(menuEvent)) {
                                if (menuEvent.type == Event::Closed)
                                    window.close();

                                if (menuEvent.type == Event::MouseButtonPressed) {
                                   
                                    if (menuEvent.mouseButton.x >= 10 && menuEvent.mouseButton.x <= 210) {
                                        if (menuEvent.mouseButton.y >= 50 && menuEvent.mouseButton.y <= 80) {
                                            // Opción 1: Ingresar nuevo cupon
                                            menuActivo = false;  
                                        }
                                        else if (menuEvent.mouseButton.y >= 90 && menuEvent.mouseButton.y <= 120) {
                                            // Opción 2: Eliminar cupon
                                            menuActivo = false;  
                                        }
                                        else if (menuEvent.mouseButton.y >= 130 && menuEvent.mouseButton.y <= 160) {
                                            // Opción 3: Ver lista de cupones
                                            menuActivo = false;  
                                            
                                        }
                                        else if (menuEvent.mouseButton.y >= 170 && menuEvent.mouseButton.y <= 200) {
                                            // Opción 4: Regresar al menu principal
                                            menuActivo = false;  
                                        }
                                    }
                                }
                            }

                            window.clear();
                            menuDescuento(window, font);  // Volver a dibujar el menu
                            window.display();
                        }

                        return;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                }
            }
        }

        window.clear();
        window.draw(title);
        window.draw(labelPorcentaje);
        window.draw(inputPorcentaje);
        window.draw(labelCantidad);
        window.draw(inputCantidad);
        window.draw(saveButton);
        window.draw(saveText);

        Text textPorcentaje(userInputPorcentaje, font, 24);
        textPorcentaje.setPosition(window.getSize().x / 2 - 95, 105);
        textPorcentaje.setFillColor(Color::White);
        window.draw(textPorcentaje);

        Text textCantidad(userInputCantidad, font, 24);
        textCantidad.setPosition(window.getSize().x / 2 - 95, 185);
        textCantidad.setFillColor(Color::White);
        window.draw(textCantidad);

        // Dibujar los textos de los cupones
        for (const auto& couponText : couponTexts) {
            window.draw(couponText);
        }

        window.display();
    }
}


bool Descuento::getCantidadPersonas()
{
    return cantidadPersonasDescuento;
}

void Descuento::setCantidadPersonas(bool cantidadPersonas)
{
    cantidadPersonasDescuento = cantidadPersonas;
}


void Descuento::confirmarDescuento(float precioTotal)
{
    precioActual = precioTotal;
   
    aplicarDescuento();

}

float Descuento::aplicarDescuento()
{
    float total = 0;

    total = porcentaje * precioActual / 100.0;

    float precioEntrada = precioActual - total;

    return precioEntrada;
}

