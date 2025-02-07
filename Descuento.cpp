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

void Descuento::IngresarDatosdelEvento()
{
    int opcion;
    do
    {
        system("cls");
        cout << "---------------------- ESTADO DEL DESCUENTO ----------------------\n";
        cout << endl;
        cout << "Ingrese el porcentaje de descuento: ";
        cin >> porcentaje;

        if (porcentaje < 0 || porcentaje > 100)
        {
            cout << "Error: El porcentaje debe estar entre 0 y 100.\n\n";
            system("pause");
            continue; 
        }

        cout << "Ingrese la cantidad de veces que se puede aplicar el cupon: ";
        cin >> cantidad;

        if (cantidad < 0)
        {
            cout << "Error: La cantidad debe ser un numero positivo\n\n";
            system("pause");
            continue; 
        }

        
        string contra = generarContrasenia();
        listaCupon.insertar(contra);

        cout << "\nDetalles del Descuento:\n";
        cout << "Porcentaje: " << porcentaje << "%\n";
        cout << "Cantidad de uso: " << cantidad << "\n";
        cout << "Cupon generado: " << contra << "\n";
        system("pause");

        do
        {
            system("cls");
            cout << "\nOpciones:\n";
            cout << "1. Insertar otro cupon \n";
            cout << "2. Ver lista de cupones\n";
            cout << "3. Eliminar un cupon\n";
            cout << "4. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (opcion == 2)
            {
                system("cls");
                cout << "\nLista de cupones:\n";
                listaCupon.mostrar();
                system("pause");
            }
            else if (opcion == 3)
            {
                system("cls");
                eliminarCupon();
                system("pause");
            }

        } while (opcion != 1 && opcion != 4);

    } while (opcion == 1);

    cout << "Regresando al menu principal...\n";
}

void Descuento::mostrarCupones()
{
    cout << "\nCupones generados:\n";
    listaCupon.mostrar();
}

void Descuento::eliminarCupon()
{
    system("cls");
    cout << "Lista de cupones disponibles:\n";
    listaCupon.mostrar();  

    string codigo;
    cout << "\nIngrese la contrasenia del cupon a eliminar: ";
    cin >> codigo;

   
    for (int i = 0; i < listaCupon.obtenerTamano(); i++)
    {
        string cupon = listaCupon.obtener(i);

        
        if (cupon == contrasenia)
        {
            
            if (cantidad > 0)  
            {
                cout << "No se puede eliminar el cupon, ya ha sido usado.\n";
                system("pause");
                return;
            }

            listaCupon.eliminar(i);
            cout << "Cupon eliminado exitosamente.\n";
            system("pause");
            return;
        }
    }

    cout << "Cupon no encontrado.\n";
    system("pause");
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