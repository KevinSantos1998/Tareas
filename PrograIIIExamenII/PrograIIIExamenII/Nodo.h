#pragma once
#include <fstream>

#ifndef NODO_H
#define NODO_H
using namespace std;

struct NodoReguistro
{
	int Codigo;
	char nombre[20];
	

};

class Nodo 
{
private:
	Nodo* siguiente;
	Nodo* anterior;
	fstream hola;

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
	void GuardarArchivo(int,char[20]);

};

#endif // !NODO_H
