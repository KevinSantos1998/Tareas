#pragma once


#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include "Nodo.h"

class ListaDoble
{
private:
	Nodo* primero, * ultimo;

public:
	ListaDoble();

	bool estaVacia();
	void agregarElemento(int);

	void imprimirLista();
	void imprimirListaRev();

	void eliminarElemento(int);

	void insertarElemento(int, int);

	int tamanioLista();

};


#endif // !LISTA_DOBLEH