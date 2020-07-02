#include <iostream> 
#include <deque> 
#include "ListaDoble.h"

using namespace std;

int main()
{

    ListaDoble hola;

    hola.agregarElementoFinal(20, "Kevin");
    hola.agregarElementoInicio(22, "carmen");
    hola.agregarElementoFinal(23, "Karla");
    hola.agregarElementoInicio(24, "Maria");
    hola.imprimirLista();
    hola.estaLlena();
    hola.estaVacia();
    hola.ObtenerFinal();
    hola.ObtenerInicio();
    hola.PopFinal();
    hola.PopInicio();
    hola.imprimirLista();
    hola.Guardarlista();
    


    return 0;
}
