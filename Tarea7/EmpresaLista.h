#pragma once


#ifndef EMPRESALISTA_H
#define EMPRESALISTA_H

#include "NodoEmpleado.h"

class EmpresaLista
{
private:
	NodoEmpleado* primero, * ultimo;

public:
	EmpresaLista();

	bool estaVacia();
	bool agregarEmpleado(int,const char*,double);
	bool insertarEmpleado(int, const char*, double);
	bool eliminarEmpleado(int);
	void ActualizarSalario(double);
	void imprimirEmpleados();
};

#endif // !EMPRESALISTA_H
