#pragma once


#ifndef NODO_H
#define NODO_H

struct NodoReguistro
{
	int Codigo;
	char nombre[20];
	Nodo* siguiente;
	Nodo* anterior;

};

class Nodo 
{
private:

public:
	Nodo(void);
	//Valor del nodo, ptrAnterior, ptrSiguiente
	Nodo(int,char[], Nodo*, Nodo*);

	void setNombre(char[20]);
	void setValor(int);
	void setSiguiente(Nodo*);
	void setAnterior(Nodo*);

	char* getNombre();
	int getValor();
	Nodo* getAnterior();
	Nodo* getSiguiente();

};

#endif // !NODO_H
