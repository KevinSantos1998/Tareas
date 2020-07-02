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
	void agregarElementoInicio(int,char[20]);
	void agregarElementoFinal (int, char[20]);
	void ObtenerInicio();
	void ObtenerFinal();
	void PopFinal();
	void PopInicio();
	void imprimirLista();


	void insertarElemento(int, int);

	int tamanioLista();
	void showdq(deque <int>);

};


#endif // !LISTA_DOBLEH
