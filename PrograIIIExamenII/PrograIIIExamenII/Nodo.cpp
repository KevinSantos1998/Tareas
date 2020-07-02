#include "Nodo.h"


Nodo::Nodo()
{
	NodoReguistro nodo;
	nodo.Codigo = -1;
	for (int i = 0; i < 20; i++)
	{
		nodo.nombre[i] = ' ';
	}
	nodo.anterior = nullptr;
	nodo.siguiente = nullptr;
}

Nodo::Nodo(int _valor,char _nombre[], Nodo* _anterior, Nodo* _siguiente)
{
	setNombre(_nombre);
	setValor(_valor);
	setAnterior(_anterior);
	setSiguiente(_siguiente);
}

void Nodo::setValor(int _valor)
{
	NodoReguistro nodo;
	nodo.Codigo = _valor;
}

void Nodo::setAnterior(Nodo* _anterior)
{
	NodoReguistro nodo;
	nodo.anterior = _anterior;
}

void Nodo::setSiguiente(Nodo* _siguiente)
{
	NodoReguistro nodo;
	nodo.siguiente = _siguiente;
}

void Nodo::setNombre(char _nombre[20])
{
	NodoReguistro nodo;
	for (int i = 0; i < 20; i++)
	{
		nodo.nombre[i] = _nombre[i];
	}
	
}

char* Nodo::getNombre() 
{
	NodoReguistro nodo;
	return nodo.nombre;
}

int Nodo::getValor()
{
	NodoReguistro nodo;
	return nodo.Codigo;
}

Nodo* Nodo::getAnterior()
{
	NodoReguistro nodo;
	return nodo.anterior;
}

Nodo* Nodo::getSiguiente()
{
	NodoReguistro nodo;
	return nodo.siguiente;
}
