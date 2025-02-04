#include "Segmento.h"
#include "Evento.h"

int main()
{
    RenderWindow window(VideoMode(800, 600), "Venta de Entradas");

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error al cargar la fuente." << endl;
        return -1;
    }

    Evento evento;

    evento.menu(window, font);

    window.close();

    return 0;

}
