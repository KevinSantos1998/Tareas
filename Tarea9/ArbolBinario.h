#pragma once

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"

class ArbolBinario 
{
private:
	NodoArbol* raiz;
	int peso=0;
public:
	ArbolBinario();

	void agregarElemento(const char*);
	//funcion recursiva
	NodoArbol* agregarAux(NodoArbol*, const char*);

	void imprimirArbol();
	void imprimirAux(NodoArbol*);
	int ObtenerPeso();
	int ObtenerPesoAux(NodoArbol*);
	int ObtenerMaximaAltura();
	int ObtenerMaximaAlturaAux(NodoArbol*);
	void GuardarElementos();
	void GuardarElementosAux(NodoArbol*);
	void CargarElementos();

};


#endif // !ARBOLBINARIO_H
