#pragma once


#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <deque> 
#include "Nodo.h"

class ListaDoble
{
private:
	Nodo* primero, * ultimo;

public:
	ListaDoble();

	bool estaVacia();
	bool estaLlena();
	void agregarElementoInicio(int,char[]);
	void agregarElementoFinal (int,char[]);
	void ObtenerInicio();
	void ObtenerFinal();
	void PopFinal();
	void PopInicio();
	void imprimirLista();
	void Guardarlista();

};


#endif // !LISTA_DOBLEH
