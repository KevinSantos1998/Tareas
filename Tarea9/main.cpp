#include <iostream>
#include <conio.h>
#include "ArbolBinario.h"
using namespace std;
int main() 
{
	
	ArbolBinario arbol;
	ArbolBinario arbol2;

	arbol.agregarElemento("Julio");
	arbol.agregarElemento("Francis");
	arbol.agregarElemento("Ana");
	arbol.agregarElemento("Xiomara");
	arbol.agregarElemento("Lily");
	arbol.agregarElemento("Yessiel");
	arbol.agregarElemento("Maria");
	arbol.agregarElemento("Nora");
	arbol.agregarElemento("Ramon");

	arbol.imprimirArbol();
	int peso = arbol.ObtenerPeso();
	cout << "\nEl peso del arbol es: " << peso;
	int altura = arbol.ObtenerMaximaAltura();
	cout << "\nLa altura del arbol es: " << altura;
	arbol.GuardarElementos();
	arbol2.CargarElementos();
	arbol2.imprimirArbol();
	_getch();
}